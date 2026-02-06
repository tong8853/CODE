# car_analysis_neural_network.py
# 使用神经网络进行二手车价格预测

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import r2_score, mean_squared_error, mean_absolute_error
import warnings
warnings.filterwarnings('ignore')

# 导入深度学习库
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers, models, callbacks
print(f"TensorFlow版本: {tf.__version__}")


# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 设置随机种子以保证结果可复现
np.random.seed(42)
tf.random.set_seed(42)

print("=" * 80)
print("神经网络二手车价格预测实验")
print("=" * 80)

###
# 1. 数据加载和预处理
###
print("\n" + "=" * 80)
print("1. 数据加载和预处理")
print("=" * 80)

# 读取数据
df = pd.read_csv('carvana.csv')
print(f"\n数据集大小: {df.shape}")
print(f"总样本数: {len(df)}")

# 提取品牌信息
df['Brand'] = df['Name'].str.strip().str.split().str[0]

# 计算车龄
current_year = 2023
df['Age'] = current_year - df['Year']

# 选择主要品牌（数据量最多的品牌）
top_brand = df['Brand'].value_counts().index[0]
brand_df = df[df['Brand'] == top_brand].copy()

print(f"\n选择品牌: {top_brand}")
print(f"该品牌数据量: {len(brand_df)} 条")

# 准备特征和目标变量
features = ['Age', 'Miles']
target = 'Price'

X = brand_df[features].values
y = brand_df[target].values

print(f"\n特征变量: {features}")
print(f"目标变量: {target}")
print(f"\n特征统计信息:")
print(brand_df[features].describe())
print(f"\n目标变量统计信息:")
print(brand_df[target].describe())

# 划分训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

print(f"\n训练集大小: {X_train.shape[0]}")
print(f"测试集大小: {X_test.shape[0]}")

# 特征标准化（神经网络训练的关键步骤）
scaler_X = StandardScaler()
scaler_y = StandardScaler()

X_train_scaled = scaler_X.fit_transform(X_train)
X_test_scaled = scaler_X.transform(X_test)

y_train_scaled = scaler_y.fit_transform(y_train.reshape(-1, 1)).flatten()
y_test_scaled = scaler_y.transform(y_test.reshape(-1, 1)).flatten()

print("\n数据标准化完成")
print(f"标准化后训练集特征均值: {X_train_scaled.mean(axis=0)}")
print(f"标准化后训练集特征标准差: {X_train_scaled.std(axis=0)}")

###
# 2. 构建神经网络模型
###
print("\n" + "=" * 80)
print("2. 构建神经网络模型")
print("=" * 80)

def create_model(input_dim, hidden_layers=[64, 32, 16], dropout_rate=0.2):
    """
    创建神经网络模型
    
    参数:
        input_dim: 输入特征维度
        hidden_layers: 隐藏层神经元数量列表
        dropout_rate: Dropout比率
    """
    model = models.Sequential()
    
    # 输入层
    model.add(layers.Input(shape=(input_dim,)))
    
    # 隐藏层
    for i, units in enumerate(hidden_layers):
        model.add(layers.Dense(units, activation='relu', name=f'hidden_{i+1}'))
        model.add(layers.BatchNormalization())
        model.add(layers.Dropout(dropout_rate))
    
    # 输出层
    model.add(layers.Dense(1, name='output'))
    
    return model

# 创建模型
model = create_model(
    input_dim=X_train_scaled.shape[1],
    hidden_layers=[64, 32, 16],
    dropout_rate=0.2
)

# 编译模型
model.compile(
    optimizer=keras.optimizers.Adam(learning_rate=0.001),
    loss='mse',
    metrics=['mae']
)

# 显示模型结构
print("\n模型结构:")
model.summary()

###
# 3. 训练神经网络
###
print("\n" + "=" * 80)
print("3. 训练神经网络")
print("=" * 80)

# 设置回调函数
early_stopping = callbacks.EarlyStopping(
    monitor='val_loss',
    patience=20,
    restore_best_weights=True,
    verbose=1
)

reduce_lr = callbacks.ReduceLROnPlateau(
    monitor='val_loss',
    factor=0.5,
    patience=10,
    min_lr=1e-6,
    verbose=1
)

# 训练模型
print("\n开始训练...")
history = model.fit(
    X_train_scaled, y_train_scaled,
    validation_split=0.2,
    epochs=200,
    batch_size=32,
    callbacks=[early_stopping, reduce_lr],
    verbose=1
)

print("\n训练完成！")

###
# 4. 模型评估
###
print("\n" + "=" * 80)
print("4. 模型评估")
print("=" * 80)

# 在训练集上预测
y_train_pred_scaled = model.predict(X_train_scaled, verbose=0).flatten()
y_train_pred = scaler_y.inverse_transform(y_train_pred_scaled.reshape(-1, 1)).flatten()

# 在测试集上预测
y_test_pred_scaled = model.predict(X_test_scaled, verbose=0).flatten()
y_test_pred = scaler_y.inverse_transform(y_test_pred_scaled.reshape(-1, 1)).flatten()

# 计算评估指标
def evaluate_model(y_true, y_pred, dataset_name):
    """计算并打印评估指标"""
    r2 = r2_score(y_true, y_pred)
    rmse = np.sqrt(mean_squared_error(y_true, y_pred))
    mae = mean_absolute_error(y_true, y_pred)
    mape = np.mean(np.abs((y_true - y_pred) / y_true)) * 100
    
    print(f"\n{dataset_name}性能:")
    print(f"  R² 分数: {r2:.4f}")
    print(f"  RMSE: ${rmse:.2f}")
    print(f"  MAE: ${mae:.2f}")
    print(f"  MAPE: {mape:.2f}%")
    
    return r2, rmse, mae, mape

# 评估训练集
train_r2, train_rmse, train_mae, train_mape = evaluate_model(
    y_train, y_train_pred, "训练集"
)

# 评估测试集
test_r2, test_rmse, test_mae, test_mape = evaluate_model(
    y_test, y_test_pred, "测试集"
)

###
# 5. 与传统回归模型比较
###
print("\n" + "=" * 80)
print("5. 与传统回归模型比较")
print("=" * 80)

from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

# 5.1 线性回归
lr = LinearRegression()
lr.fit(X_train, y_train)
y_test_pred_lr = lr.predict(X_test)
lr_r2 = r2_score(y_test, y_test_pred_lr)
lr_rmse = np.sqrt(mean_squared_error(y_test, y_test_pred_lr))

print(f"\n线性回归:")
print(f"  R² 分数: {lr_r2:.4f}")
print(f"  RMSE: ${lr_rmse:.2f}")

# 5.2 多项式回归
poly = PolynomialFeatures(degree=2)
X_train_poly = poly.fit_transform(X_train)
X_test_poly = poly.transform(X_test)

poly_lr = LinearRegression()
poly_lr.fit(X_train_poly, y_train)
y_test_pred_poly = poly_lr.predict(X_test_poly)
poly_r2 = r2_score(y_test, y_test_pred_poly)
poly_rmse = np.sqrt(mean_squared_error(y_test, y_test_pred_poly))

print(f"\n多项式回归(2次):")
print(f"  R² 分数: {poly_r2:.4f}")
print(f"  RMSE: ${poly_rmse:.2f}")

# 模型比较表
comparison_df = pd.DataFrame({
    '模型': ['神经网络', '线性回归', '多项式回归(2次)'],
    'R² 分数': [test_r2, lr_r2, poly_r2],
    'RMSE': [test_rmse, lr_rmse, poly_rmse]
})
comparison_df = comparison_df.sort_values('R² 分数', ascending=False)

print("\n" + "=" * 80)
print("模型性能比较（测试集）")
print("=" * 80)
print(comparison_df.to_string(index=False))

###
# 6. 可视化结果
###
print("\n" + "=" * 80)
print("6. 生成可视化图表")
print("=" * 80)

# 图1: 训练历史
fig, axes = plt.subplots(1, 2, figsize=(15, 5))

# 损失曲线
axes[0].plot(history.history['loss'], label='训练损失', linewidth=2)
axes[0].plot(history.history['val_loss'], label='验证损失', linewidth=2)
axes[0].set_xlabel('训练轮次 (Epoch)', fontsize=12)
axes[0].set_ylabel('损失 (MSE)', fontsize=12)
axes[0].set_title('训练过程：损失曲线', fontsize=14, fontweight='bold')
axes[0].legend(fontsize=11)
axes[0].grid(True, alpha=0.3)

# MAE曲线
axes[1].plot(history.history['mae'], label='训练MAE', linewidth=2)
axes[1].plot(history.history['val_mae'], label='验证MAE', linewidth=2)
axes[1].set_xlabel('训练轮次 (Epoch)', fontsize=12)
axes[1].set_ylabel('平均绝对误差 (MAE)', fontsize=12)
axes[1].set_title('训练过程：MAE曲线', fontsize=14, fontweight='bold')
axes[1].legend(fontsize=11)
axes[1].grid(True, alpha=0.3)

plt.tight_layout()
plt.savefig('神经网络_训练历史.png', dpi=300, bbox_inches='tight')
print("图表已保存: 神经网络_训练历史.png")
plt.close()

# 图2: 预测结果对比
fig, axes = plt.subplots(2, 2, figsize=(15, 12))

# 训练集：预测vs实际
axes[0, 0].scatter(y_train, y_train_pred, alpha=0.5, s=30, edgecolors='k', linewidth=0.5)
axes[0, 0].plot([y_train.min(), y_train.max()], [y_train.min(), y_train.max()], 
                'r--', linewidth=2, label='理想预测线')
axes[0, 0].set_xlabel('实际价格 ($)', fontsize=12)
axes[0, 0].set_ylabel('预测价格 ($)', fontsize=12)
axes[0, 0].set_title(f'训练集：预测vs实际\nR²={train_r2:.4f}, RMSE=${train_rmse:.2f}', 
                     fontsize=14, fontweight='bold')
axes[0, 0].legend(fontsize=11)
axes[0, 0].grid(True, alpha=0.3)

# 测试集：预测vs实际
axes[0, 1].scatter(y_test, y_test_pred, alpha=0.5, s=30, edgecolors='k', linewidth=0.5, color='orange')
axes[0, 1].plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 
                'r--', linewidth=2, label='理想预测线')
axes[0, 1].set_xlabel('实际价格 ($)', fontsize=12)
axes[0, 1].set_ylabel('预测价格 ($)', fontsize=12)
axes[0, 1].set_title(f'测试集：预测vs实际\nR²={test_r2:.4f}, RMSE=${test_rmse:.2f}', 
                     fontsize=14, fontweight='bold')
axes[0, 1].legend(fontsize=11)
axes[0, 1].grid(True, alpha=0.3)

# 训练集：残差分析
train_residuals = y_train - y_train_pred
axes[1, 0].scatter(y_train_pred, train_residuals, alpha=0.5, s=30, edgecolors='k', linewidth=0.5)
axes[1, 0].axhline(y=0, color='r', linestyle='--', linewidth=2)
axes[1, 0].set_xlabel('预测价格 ($)', fontsize=12)
axes[1, 0].set_ylabel('残差 ($)', fontsize=12)
axes[1, 0].set_title('训练集：残差分析', fontsize=14, fontweight='bold')
axes[1, 0].grid(True, alpha=0.3)

# 测试集：残差分析
test_residuals = y_test - y_test_pred
axes[1, 1].scatter(y_test_pred, test_residuals, alpha=0.5, s=30, edgecolors='k', linewidth=0.5, color='orange')
axes[1, 1].axhline(y=0, color='r', linestyle='--', linewidth=2)
axes[1, 1].set_xlabel('预测价格 ($)', fontsize=12)
axes[1, 1].set_ylabel('残差 ($)', fontsize=12)
axes[1, 1].set_title('测试集：残差分析', fontsize=14, fontweight='bold')
axes[1, 1].grid(True, alpha=0.3)

plt.tight_layout()
plt.savefig('神经网络_预测结果.png', dpi=300, bbox_inches='tight')
print("图表已保存: 神经网络_预测结果.png")
plt.close()

# 图3: 模型比较
fig, axes = plt.subplots(1, 2, figsize=(15, 5))

# R²分数比较
model_names = ['神经网络', '线性回归', '多项式回归']
r2_scores = [test_r2, lr_r2, poly_r2]
colors = ['#2ecc71', '#3498db', '#e74c3c']

bars1 = axes[0].bar(model_names, r2_scores, color=colors, edgecolor='black', linewidth=1.5)
axes[0].set_ylabel('R² 分数', fontsize=12)
axes[0].set_title('不同模型的R²分数比较', fontsize=14, fontweight='bold')
axes[0].set_ylim([0, 1])
axes[0].grid(True, alpha=0.3, axis='y')

for bar, score in zip(bars1, r2_scores):
    height = bar.get_height()
    axes[0].text(bar.get_x() + bar.get_width()/2., height,
                f'{score:.4f}',
                ha='center', va='bottom', fontsize=11, fontweight='bold')

# RMSE比较
rmse_scores = [test_rmse, lr_rmse, poly_rmse]
bars2 = axes[1].bar(model_names, rmse_scores, color=colors, edgecolor='black', linewidth=1.5)
axes[1].set_ylabel('RMSE ($)', fontsize=12)
axes[1].set_title('不同模型的RMSE比较', fontsize=14, fontweight='bold')
axes[1].grid(True, alpha=0.3, axis='y')

for bar, score in zip(bars2, rmse_scores):
    height = bar.get_height()
    axes[1].text(bar.get_x() + bar.get_width()/2., height,
                f'${score:.2f}',
                ha='center', va='bottom', fontsize=11, fontweight='bold')

plt.tight_layout()
plt.savefig('神经网络_模型比较.png', dpi=300, bbox_inches='tight')
print("图表已保存: 神经网络_模型比较.png")
plt.close()

# 图4: 特征重要性分析（通过扰动法）
print("\n计算特征重要性...")

def calculate_feature_importance(model, X_test_scaled, y_test_scaled, scaler_y):
    """通过特征扰动法计算特征重要性"""
    baseline_pred = model.predict(X_test_scaled, verbose=0).flatten()
    baseline_mse = mean_squared_error(y_test_scaled, baseline_pred)
    
    importances = []
    for i in range(X_test_scaled.shape[1]):
        X_test_permuted = X_test_scaled.copy()
        np.random.shuffle(X_test_permuted[:, i])
        permuted_pred = model.predict(X_test_permuted, verbose=0).flatten()
        permuted_mse = mean_squared_error(y_test_scaled, permuted_pred)
        importance = permuted_mse - baseline_mse
        importances.append(importance)
    
    return np.array(importances)

feature_importances = calculate_feature_importance(
    model, X_test_scaled, y_test_scaled, scaler_y
)

# 归一化特征重要性
feature_importances = feature_importances / feature_importances.sum() * 100

plt.figure(figsize=(10, 6))
bars = plt.barh(features, feature_importances, color=['#3498db', '#e74c3c'], 
                edgecolor='black', linewidth=1.5)
plt.xlabel('相对重要性 (%)', fontsize=12)
plt.title('神经网络：特征重要性分析', fontsize=14, fontweight='bold')
plt.grid(True, alpha=0.3, axis='x')

for bar, importance in zip(bars, feature_importances):
    width = bar.get_width()
    plt.text(width, bar.get_y() + bar.get_height()/2.,
            f'{importance:.1f}%',
            ha='left', va='center', fontsize=11, fontweight='bold')

plt.tight_layout()
plt.savefig('神经网络_特征重要性.png', dpi=300, bbox_inches='tight')
print("图表已保存: 神经网络_特征重要性.png")
plt.close()

###
# 7. 预测示例
###
print("\n" + "=" * 80)
print("7. 预测示例")
print("=" * 80)

# 创建一些示例数据进行预测
example_data = pd.DataFrame({
    'Age': [3, 5, 8, 10],
    'Miles': [30000, 50000, 70000, 90000]
})

print("\n示例数据:")
print(example_data)

# 标准化并预测
example_scaled = scaler_X.transform(example_data.values)
example_pred_scaled = model.predict(example_scaled, verbose=0).flatten()
example_pred = scaler_y.inverse_transform(example_pred_scaled.reshape(-1, 1)).flatten()

example_data['预测价格'] = example_pred.astype(int)

print("\n预测结果:")
print(example_data)

# ##
# 总结
# ##
print("\n" + "=" * 80)
print("实验总结")
print("=" * 80)

print(f"""
神经网络模型性能:
- 测试集 R² 分数: {test_r2:.4f}
- 测试集 RMSE: ${test_rmse:.2f}
- 测试集 MAE: ${test_mae:.2f}
- 测试集 MAPE: {test_mape:.2f}%

与传统模型对比:
- 神经网络 vs 线性回归: R²提升 {(test_r2 - lr_r2)*100:.2f}%
- 神经网络 vs 多项式回归: R²提升 {(test_r2 - poly_r2)*100:.2f}%

特征重要性:
- {features[0]}: {feature_importances[0]:.1f}%
- {features[1]}: {feature_importances[1]:.1f}%

生成的文件:
1. 神经网络_训练历史.png
2. 神经网络_预测结果.png
3. 神经网络_模型比较.png
4. 神经网络_特征重要性.png
""")

print("=" * 80)
print("实验完成！")
print("=" * 80)
