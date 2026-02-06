# regression_analysis.py
# 二手车回归分析：线性回归、多项式回归、多元回归

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
from sklearn.metrics import mean_squared_error, r2_score, mean_absolute_error
import warnings
warnings.filterwarnings('ignore')

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

print("=" * 80)
print("二手车回归分析实验")
print("=" * 80)

# 1. 数据加载与预处理
print("\n" + "=" * 80)
print("1. 数据加载与预处理")
print("=" * 80)

df = pd.read_csv('carvana.csv')
print(f"\n原始数据集形状: {df.shape}")

# 提取品牌
df['Brand'] = df['Name'].str.split().str[0]

# 计算车龄
current_year = 2024
df['Age'] = current_year - df['Year']

# 查看品牌分布
brand_counts = df['Brand'].value_counts()
print(f"\n品牌数量统计 (前10名):")
print(brand_counts.head(10))

# 选择一个热门品牌进行分析 (例如: Ford)
selected_brand = 'Ford'
print(f"\n选择品牌: {selected_brand}")

df_brand = df[df['Brand'] == selected_brand].copy()
print(f"筛选后数据集形状: {df_brand.shape}")

# 移除异常值 (使用IQR方法)
def remove_outliers(df, columns):
    df_clean = df.copy()
    for col in columns:
        Q1 = df_clean[col].quantile(0.25)
        Q3 = df_clean[col].quantile(0.75)
        IQR = Q3 - Q1
        lower_bound = Q1 - 1.5 * IQR
        upper_bound = Q3 + 1.5 * IQR
        df_clean = df_clean[(df_clean[col] >= lower_bound) & (df_clean[col] <= upper_bound)]
    return df_clean

df_brand = remove_outliers(df_brand, ['Price', 'Miles', 'Age'])
print(f"移除异常值后数据集形状: {df_brand.shape}")

# 查看数据统计
print(f"\n数据统计描述:")
print(df_brand[['Age', 'Miles', 'Price']].describe())

# 2. 线性回归分析 (车龄 vs 价格)
print("\n" + "=" * 80)
print("2. 线性回归分析: 车龄 vs 价格")
print("=" * 80)

# 准备数据
X_age = df_brand[['Age']].values
y = df_brand['Price'].values

# 划分训练集和测试集
X_age_train, X_age_test, y_train, y_test = train_test_split(
    X_age, y, test_size=0.2, random_state=42
)

# 训练线性回归模型
lr_age = LinearRegression()
lr_age.fit(X_age_train, y_train)

# 预测
y_pred_age_train = lr_age.predict(X_age_train)
y_pred_age_test = lr_age.predict(X_age_test)

# 评估模型
print(f"\n线性回归模型参数:")
print(f"截距 (Intercept): {lr_age.intercept_:.2f}")
print(f"斜率 (Coefficient): {lr_age.coef_[0]:.2f}")
print(f"回归方程: Price = {lr_age.intercept_:.2f} + {lr_age.coef_[0]:.2f} * Age")

print(f"\n训练集性能:")
print(f"R² Score: {r2_score(y_train, y_pred_age_train):.4f}")
print(f"RMSE: ${np.sqrt(mean_squared_error(y_train, y_pred_age_train)):.2f}")
print(f"MAE: ${mean_absolute_error(y_train, y_pred_age_train):.2f}")

print(f"\n测试集性能:")
print(f"R² Score: {r2_score(y_test, y_pred_age_test):.4f}")
print(f"RMSE: ${np.sqrt(mean_squared_error(y_test, y_pred_age_test)):.2f}")
print(f"MAE: ${mean_absolute_error(y_test, y_pred_age_test):.2f}")

# 3. 线性回归分析 (里程 vs 价格)
print("\n" + "=" * 80)
print("3. 线性回归分析: 里程 vs 价格")
print("=" * 80)

# 准备数据
X_miles = df_brand[['Miles']].values

# 划分训练集和测试集
X_miles_train, X_miles_test, y_train2, y_test2 = train_test_split(
    X_miles, y, test_size=0.2, random_state=42
)

# 训练线性回归模型
lr_miles = LinearRegression()
lr_miles.fit(X_miles_train, y_train2)

# 预测
y_pred_miles_train = lr_miles.predict(X_miles_train)
y_pred_miles_test = lr_miles.predict(X_miles_test)

# 评估模型
print(f"\n线性回归模型参数:")
print(f"截距 (Intercept): {lr_miles.intercept_:.2f}")
print(f"斜率 (Coefficient): {lr_miles.coef_[0]:.6f}")
print(f"回归方程: Price = {lr_miles.intercept_:.2f} + {lr_miles.coef_[0]:.6f} * Miles")

print(f"\n训练集性能:")
print(f"R² Score: {r2_score(y_train2, y_pred_miles_train):.4f}")
print(f"RMSE: ${np.sqrt(mean_squared_error(y_train2, y_pred_miles_train)):.2f}")
print(f"MAE: ${mean_absolute_error(y_train2, y_pred_miles_train):.2f}")

print(f"\n测试集性能:")
print(f"R² Score: {r2_score(y_test2, y_pred_miles_test):.4f}")
print(f"RMSE: ${np.sqrt(mean_squared_error(y_test2, y_pred_miles_test)):.2f}")
print(f"MAE: ${mean_absolute_error(y_test2, y_pred_miles_test):.2f}")

# 4. 多项式回归分析 (车龄 vs 价格)
print("\n" + "=" * 80)
print("4. 多项式回归分析: 车龄 vs 价格")
print("=" * 80)

# 测试不同的多项式阶数
degrees = [2, 3, 4]
poly_results = {}

for degree in degrees:
    # 创建多项式特征
    poly = PolynomialFeatures(degree=degree)
    X_age_poly_train = poly.fit_transform(X_age_train)
    X_age_poly_test = poly.transform(X_age_test)
    
    # 训练模型
    poly_model = LinearRegression()
    poly_model.fit(X_age_poly_train, y_train)
    
    # 预测
    y_pred_poly_train = poly_model.predict(X_age_poly_train)
    y_pred_poly_test = poly_model.predict(X_age_poly_test)
    
    # 评估
    r2_train = r2_score(y_train, y_pred_poly_train)
    r2_test = r2_score(y_test, y_pred_poly_test)
    rmse_test = np.sqrt(mean_squared_error(y_test, y_pred_poly_test))
    
    poly_results[degree] = {
        'model': poly_model,
        'poly': poly,
        'r2_train': r2_train,
        'r2_test': r2_test,
        'rmse_test': rmse_test,
        'y_pred_test': y_pred_poly_test
    }
    
    print(f"\n{degree}次多项式回归:")
    print(f"训练集 R²: {r2_train:.4f}")
    print(f"测试集 R²: {r2_test:.4f}")
    print(f"测试集 RMSE: ${rmse_test:.2f}")

# 选择最佳多项式阶数 (基于测试集R²)
best_degree = max(poly_results.keys(), key=lambda k: poly_results[k]['r2_test'])
print(f"\n最佳多项式阶数: {best_degree}")
print(f"最佳模型测试集 R²: {poly_results[best_degree]['r2_test']:.4f}")

# 5. 多元回归分析 (车龄 + 里程 vs 价格)
print("\n" + "=" * 80)
print("5. 多元回归分析: 车龄 + 里程 vs 价格")
print("=" * 80)

# 准备数据
X_multi = df_brand[['Age', 'Miles']].values

# 划分训练集和测试集
X_multi_train, X_multi_test, y_train3, y_test3 = train_test_split(
    X_multi, y, test_size=0.2, random_state=42
)

# 训练多元线性回归模型
mlr = LinearRegression()
mlr.fit(X_multi_train, y_train3)

# 预测
y_pred_multi_train = mlr.predict(X_multi_train)
y_pred_multi_test = mlr.predict(X_multi_test)

# 评估模型
print(f"\n多元线性回归模型参数:")
print(f"截距 (Intercept): {mlr.intercept_:.2f}")
print(f"系数 (Coefficients):")
print(f"  Age: {mlr.coef_[0]:.2f}")
print(f"  Miles: {mlr.coef_[1]:.6f}")
print(f"回归方程: Price = {mlr.intercept_:.2f} + {mlr.coef_[0]:.2f} * Age + {mlr.coef_[1]:.6f} * Miles")

print(f"\n训练集性能:")
print(f"R² Score: {r2_score(y_train3, y_pred_multi_train):.4f}")
print(f"RMSE: ${np.sqrt(mean_squared_error(y_train3, y_pred_multi_train)):.2f}")
print(f"MAE: ${mean_absolute_error(y_train3, y_pred_multi_train):.2f}")

print(f"\n测试集性能:")
print(f"R² Score: {r2_score(y_test3, y_pred_multi_test):.4f}")
print(f"RMSE: ${np.sqrt(mean_squared_error(y_test3, y_pred_multi_test)):.2f}")
print(f"MAE: ${mean_absolute_error(y_test3, y_pred_multi_test):.2f}")

# 6. 模型对比
print("\n" + "=" * 80)
print("6. 模型性能对比")
print("=" * 80)

comparison_df = pd.DataFrame({
    '模型': [
        '线性回归 (车龄)',
        '线性回归 (里程)',
        f'{best_degree}次多项式回归 (车龄)',
        '多元线性回归 (车龄+里程)'
    ],
    'R² (测试集)': [
        r2_score(y_test, y_pred_age_test),
        r2_score(y_test2, y_pred_miles_test),
        poly_results[best_degree]['r2_test'],
        r2_score(y_test3, y_pred_multi_test)
    ],
    'RMSE (测试集)': [
        np.sqrt(mean_squared_error(y_test, y_pred_age_test)),
        np.sqrt(mean_squared_error(y_test2, y_pred_miles_test)),
        poly_results[best_degree]['rmse_test'],
        np.sqrt(mean_squared_error(y_test3, y_pred_multi_test))
    ]
})

print("\n模型性能对比表:")
print(comparison_df.to_string(index=False))

# 7. 可视化
print("\n" + "=" * 80)
print("7. 回归分析可视化")
print("=" * 80)

fig = plt.figure(figsize=(20, 12))

# 7.1 线性回归: 车龄 vs 价格
ax1 = plt.subplot(2, 3, 1)
ax1.scatter(X_age_test, y_test, alpha=0.5, s=30, label='实际值')
ax1.plot(X_age_test, y_pred_age_test, color='red', linewidth=2, label='预测值')
ax1.set_xlabel('车龄 (年)')
ax1.set_ylabel('价格 ($)')
ax1.set_title(f'线性回归: 车龄 vs 价格\nR² = {r2_score(y_test, y_pred_age_test):.4f}', 
              fontsize=12, fontweight='bold')
ax1.legend()
ax1.grid(alpha=0.3)

# 7.2 线性回归: 里程 vs 价格
ax2 = plt.subplot(2, 3, 2)
ax2.scatter(X_miles_test, y_test2, alpha=0.5, s=30, label='实际值')
# 排序以便绘制平滑的线
sorted_idx = np.argsort(X_miles_test.flatten())
ax2.plot(X_miles_test[sorted_idx], y_pred_miles_test[sorted_idx], 
         color='red', linewidth=2, label='预测值')
ax2.set_xlabel('里程 (英里)')
ax2.set_ylabel('价格 ($)')
ax2.set_title(f'线性回归: 里程 vs 价格\nR² = {r2_score(y_test2, y_pred_miles_test):.4f}', 
              fontsize=12, fontweight='bold')
ax2.legend()
ax2.grid(alpha=0.3)

# 7.3 多项式回归: 车龄 vs 价格
ax3 = plt.subplot(2, 3, 3)
ax3.scatter(X_age_test, y_test, alpha=0.5, s=30, label='实际值')
sorted_idx = np.argsort(X_age_test.flatten())
ax3.plot(X_age_test[sorted_idx], poly_results[best_degree]['y_pred_test'][sorted_idx], 
         color='green', linewidth=2, label=f'{best_degree}次多项式')
ax3.set_xlabel('车龄 (年)')
ax3.set_ylabel('价格 ($)')
ax3.set_title(f'{best_degree}次多项式回归: 车龄 vs 价格\nR² = {poly_results[best_degree]["r2_test"]:.4f}', 
              fontsize=12, fontweight='bold')
ax3.legend()
ax3.grid(alpha=0.3)

# 7.4 多元回归: 预测值 vs 实际值
ax4 = plt.subplot(2, 3, 4)
ax4.scatter(y_test3, y_pred_multi_test, alpha=0.5, s=30)
# 绘制理想预测线 (y=x)
min_val = min(y_test3.min(), y_pred_multi_test.min())
max_val = max(y_test3.max(), y_pred_multi_test.max())
ax4.plot([min_val, max_val], [min_val, max_val], 'r--', linewidth=2, label='理想预测')
ax4.set_xlabel('实际价格 ($)')
ax4.set_ylabel('预测价格 ($)')
ax4.set_title(f'多元回归: 预测值 vs 实际值\nR² = {r2_score(y_test3, y_pred_multi_test):.4f}', 
              fontsize=12, fontweight='bold')
ax4.legend()
ax4.grid(alpha=0.3)

# 7.5 残差分析
ax5 = plt.subplot(2, 3, 5)
residuals = y_test3 - y_pred_multi_test
ax5.scatter(y_pred_multi_test, residuals, alpha=0.5, s=30)
ax5.axhline(y=0, color='r', linestyle='--', linewidth=2)
ax5.set_xlabel('预测价格 ($)')
ax5.set_ylabel('残差 ($)')
ax5.set_title('多元回归残差分析', fontsize=12, fontweight='bold')
ax5.grid(alpha=0.3)

# 7.6 模型性能对比
ax6 = plt.subplot(2, 3, 6)
models = comparison_df['模型'].values
r2_scores = comparison_df['R² (测试集)'].values
colors = ['steelblue', 'coral', 'lightgreen', 'plum']
bars = ax6.barh(models, r2_scores, color=colors)
ax6.set_xlabel('R² Score')
ax6.set_title('模型性能对比 (R² Score)', fontsize=12, fontweight='bold')
ax6.grid(axis='x', alpha=0.3)
# 添加数值标签
for i, (bar, score) in enumerate(zip(bars, r2_scores)):
    ax6.text(score + 0.01, i, f'{score:.4f}', va='center')

plt.tight_layout()
plt.savefig('回归分析结果.png', dpi=300, bbox_inches='tight')
print("\n可视化图表已保存为: 回归分析结果.png")
# plt.show() 

# 8. 相关性分析
print("\n" + "=" * 80)
print("8. 特征相关性分析")
print("=" * 80)

correlation_matrix = df_brand[['Age', 'Miles', 'Price']].corr()
print("\n相关系数矩阵:")
print(correlation_matrix)

# 绘制相关性热力图
fig, ax = plt.subplots(figsize=(8, 6))
sns.heatmap(correlation_matrix, annot=True, fmt='.3f', cmap='coolwarm', 
            center=0, square=True, linewidths=1, cbar_kws={"shrink": 0.8})
ax.set_title(f'{selected_brand} 品牌二手车特征相关性热力图', fontsize=14, fontweight='bold')
plt.tight_layout()
plt.savefig('特征相关性热力图.png', dpi=300, bbox_inches='tight')
print("\n相关性热力图已保存为: 特征相关性热力图.png")
# plt.show()

print("\n" + "=" * 80)
print("实验完成!")
print("=" * 80)
