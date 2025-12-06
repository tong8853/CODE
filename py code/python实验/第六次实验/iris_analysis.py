import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# ============================================================
# 1. 数据加载与检查
# ============================================================
print("=" * 60)
print("1. 数据加载与检查")
print("=" * 60)

# 从本地CSV文件加载鸢尾花数据集
df = pd.read_csv('iris.csv', index_col=0)

# 查看数据基本信息
print("\n数据集基本信息：")
print(f"数据形状: {df.shape}")
print(f"列名: {list(df.columns)}")

# 查看前5行
print("\n数据集前5行：")
print(df.head())

# 查看数据类型和缺失值
print("\n数据类型和缺失值：")
print(df.info())

# 查看每个物种的样本数量
print("\n各物种样本数量：")
print(df['Species'].value_counts())

# 统计信息
print("\n各特征的统计信息：")
print(df.describe())

# 计算方差
print("\n各特征的方差：")
variance = df.iloc[:, :4].var()
print(variance)
print("\n方差分析：")
for col, var in variance.items():
    if var > 0.1:
        print(f"{col}: 方差={var:.4f}，分布较广，适合用于预测")
    else:
        print(f"{col}: 方差={var:.4f}，分布较窄")

# ============================================================
# 2. 特征分离效果可视化（小提琴图）
# ============================================================
print("\n" + "=" * 60)
print("2. 特征分离效果可视化")
print("=" * 60)

fig, axes = plt.subplots(2, 2, figsize=(14, 10))
features = df.columns[:4]  # 前4列是特征

for i, (ax, feature) in enumerate(zip(axes.flatten(), features)):
    sns.violinplot(data=df, x='Species', y=feature, ax=ax, palette='Set2')
    ax.set_title(f'{feature} 的分离效果', fontsize=12, fontweight='bold')
    ax.set_xlabel('物种', fontsize=10)
    ax.set_ylabel(feature, fontsize=10)
    ax.grid(True, alpha=0.3)

plt.suptitle('鸢尾花特征分离效果分析（小提琴图）', fontsize=16, fontweight='bold', y=1.00)
plt.tight_layout()
plt.savefig('iris_violin_plot.png', dpi=300, bbox_inches='tight')
print("✓ 小提琴图已保存为: iris_violin_plot.png")
plt.show()

# ============================================================
# 3. 特征关系可视化（散点图矩阵）
# ============================================================
print("\n" + "=" * 60)
print("3. 特征关系可视化")
print("=" * 60)

# 使用pairplot绘制散点图矩阵
pairplot_fig = sns.pairplot(df, hue='Species', diag_kind='kde', 
                             palette='Set1', height=2.5, 
                             plot_kws={'alpha': 0.6, 's': 50, 'edgecolor': 'k'},
                             diag_kws={'alpha': 0.7})
pairplot_fig.fig.suptitle('鸢尾花特征散点图矩阵', y=1.02, fontsize=16, fontweight='bold')
plt.savefig('iris_pairplot.png', dpi=300, bbox_inches='tight')
print("✓ 散点图矩阵已保存为: iris_pairplot.png")
plt.show()

# ============================================================
# 4. 特征相关性分析
# ============================================================
print("\n" + "=" * 60)
print("4. 特征相关性分析")
print("=" * 60)

# 计算相关系数矩阵
corr_matrix = df.iloc[:, :4].corr()
print("\n特征相关系数矩阵：")
print(corr_matrix)

# 分析相关性
print("\n相关性分析：")
for i in range(len(corr_matrix.columns)):
    for j in range(i+1, len(corr_matrix.columns)):
        corr_value = corr_matrix.iloc[i, j]
        feature1 = corr_matrix.columns[i]
        feature2 = corr_matrix.columns[j]
        
        if abs(corr_value) > 0.8:
            print(f"  {feature1} 与 {feature2}: {corr_value:.4f} (强相关)")
        elif abs(corr_value) > 0.5:
            print(f"  {feature1} 与 {feature2}: {corr_value:.4f} (中度相关)")
        else:
            print(f"  {feature1} 与 {feature2}: {corr_value:.4f} (弱相关)")

# 绘制热力图
plt.figure(figsize=(10, 8))
sns.heatmap(corr_matrix, annot=True, cmap='coolwarm', center=0,
            square=True, linewidths=2, cbar_kws={"shrink": 0.8},
            fmt='.3f', annot_kws={'size': 11, 'weight': 'bold'})
plt.title('鸢尾花特征相关性热力图', fontsize=16, fontweight='bold', pad=20)
plt.tight_layout()
plt.savefig('iris_heatmap.png', dpi=300, bbox_inches='tight')
print("\n✓ 热力图已保存为: iris_heatmap.png")
plt.show()

# ============================================================
# 5. 额外分析：按物种分组的统计
# ============================================================
print("\n" + "=" * 60)
print("5. 按物种分组的统计分析")
print("=" * 60)

print("\n各物种的平均值：")
print(df.groupby('Species').mean())

print("\n各物种的标准差：")
print(df.groupby('Species').std())

# 绘制箱线图
fig, axes = plt.subplots(2, 2, figsize=(14, 10))
for i, (ax, feature) in enumerate(zip(axes.flatten(), features)):
    sns.boxplot(data=df, x='Species', y=feature, ax=ax, palette='pastel')
    ax.set_title(f'{feature} 的箱线图', fontsize=12, fontweight='bold')
    ax.set_xlabel('物种', fontsize=10)
    ax.set_ylabel(feature, fontsize=10)
    ax.grid(True, alpha=0.3, axis='y')

plt.suptitle('鸢尾花特征箱线图分析', fontsize=16, fontweight='bold', y=1.00)
plt.tight_layout()
plt.savefig('iris_boxplot.png', dpi=300, bbox_inches='tight')
print("\n✓ 箱线图已保存为: iris_boxplot.png")
plt.show()

# ============================================================
# 实验总结
# ============================================================
print("\n" + "=" * 60)
print("实验总结")
print("=" * 60)
print(f"""
数据集信息：
  - 总样本数: {len(df)}
  - 特征数量: {len(df.columns) - 1}
  - 物种数量: {df['Species'].nunique()}
  - 缺失值: {df.isnull().sum().sum()}

关键发现：
  1. 所有特征方差都较大，适合用于分类预测
  2. Petal.Length 和 Petal.Width 高度相关 (r={corr_matrix.loc['Petal.Length', 'Petal.Width']:.3f})
  3. 花瓣特征对物种区分效果最好
  4. setosa 物种与其他两种有明显区分
  5. versicolor 和 virginica 在某些特征上有重叠

生成的图表：
  ✓ iris_violin_plot.png - 特征分离效果
  ✓ iris_pairplot.png - 特征关系矩阵
  ✓ iris_heatmap.png - 相关性热力图
  ✓ iris_boxplot.png - 箱线图分析
""")

print("=" * 60)
print("分析完成！")
print("=" * 60)
