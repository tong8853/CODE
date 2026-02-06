#grouping_aggregation.py

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import warnings
warnings.filterwarnings('ignore')

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

# 1. 加载数据
print("=" * 80)
print("1. 数据加载与预处理")
print("=" * 80)

df = pd.read_csv('carvana.csv')
print(f"\n数据集形状: {df.shape}")
print(f"\n前5行数据:")
print(df.head())

# 数据预处理：提取品牌名称
df['Brand'] = df['Name'].str.split().str[0]

# 计算车龄（假设当前年份为2024）
current_year = 2024
df['Age'] = current_year - df['Year']

print(f"\n数据集基本信息:")
print(df.info())

print(f"\n数据统计描述:")
print(df.describe())

# 检查缺失值
print(f"\n缺失值统计:")
print(df.isnull().sum())

# 2. 按品牌分组聚合分析
print("\n" + "=" * 80)
print("2. 按品牌分组聚合分析")
print("=" * 80)

# 2.1 统计各品牌车辆数量
brand_counts = df['Brand'].value_counts()
print(f"\n各品牌车辆数量 (前10名):")
print(brand_counts.head(10))

# 2.2 按品牌分组计算平均价格、平均里程、平均车龄
brand_stats = df.groupby('Brand').agg({
    'Price': ['mean', 'median', 'min', 'max', 'std'],
    'Miles': ['mean', 'median', 'min', 'max'],
    'Age': ['mean', 'median', 'min', 'max'],
    'Name': 'count'  # 统计数量
}).round(2)

brand_stats.columns = ['_'.join(col).strip() for col in brand_stats.columns.values]
brand_stats = brand_stats.rename(columns={'Name_count': 'Count'})
brand_stats = brand_stats.sort_values('Count', ascending=False)

print(f"\n各品牌统计信息 (前10名):")
print(brand_stats.head(10))

# 2.3 筛选车辆数量大于100的品牌进行详细分析
popular_brands = brand_counts[brand_counts > 100].index.tolist()
print(f"\n车辆数量大于100的品牌: {popular_brands}")

popular_brand_stats = brand_stats[brand_stats['Count'] > 100].sort_values('Price_mean', ascending=False)
print(f"\n热门品牌统计信息:")
print(popular_brand_stats)

# 3. 按车龄分组聚合分析
print("\n" + "=" * 80)
print("3. 按车龄分组聚合分析")
print("=" * 80)

# 创建车龄分组
age_bins = [0, 3, 5, 8, 15]
age_labels = ['0-3年', '3-5年', '5-8年', '8年以上']
df['Age_Group'] = pd.cut(df['Age'], bins=age_bins, labels=age_labels, include_lowest=True)

# 按车龄分组统计
age_stats = df.groupby('Age_Group').agg({
    'Price': ['mean', 'median', 'std'],
    'Miles': ['mean', 'median'],
    'Name': 'count'
}).round(2)

age_stats.columns = ['_'.join(col).strip() for col in age_stats.columns.values]
age_stats = age_stats.rename(columns={'Name_count': 'Count'})

print(f"\n按车龄分组统计:")
print(age_stats)

# 4. 按里程分组聚合分析
print("\n" + "=" * 80)
print("4. 按里程分组聚合分析")
print("=" * 80)

# 创建里程分组
miles_bins = [0, 30000, 60000, 90000, 150000]
miles_labels = ['0-3万英里', '3-6万英里', '6-9万英里', '9万英里以上']
df['Miles_Group'] = pd.cut(df['Miles'], bins=miles_bins, labels=miles_labels, include_lowest=True)

# 按里程分组统计
miles_stats = df.groupby('Miles_Group').agg({
    'Price': ['mean', 'median', 'std'],
    'Age': ['mean', 'median'],
    'Name': 'count'
}).round(2)

miles_stats.columns = ['_'.join(col).strip() for col in miles_stats.columns.values]
miles_stats = miles_stats.rename(columns={'Name_count': 'Count'})

print(f"\n按里程分组统计:")
print(miles_stats)

# 5. 多维度分组聚合分析
print("\n" + "=" * 80)
print("5. 多维度分组聚合分析 (品牌 + 车龄)")
print("=" * 80)

# 选择热门品牌进行多维度分析
top_brands = brand_counts.head(5).index.tolist()
df_top = df[df['Brand'].isin(top_brands)]

multi_stats = df_top.groupby(['Brand', 'Age_Group']).agg({
    'Price': 'mean',
    'Miles': 'mean',
    'Name': 'count'
}).round(2)

multi_stats.columns = ['Avg_Price', 'Avg_Miles', 'Count']
print(f"\n热门品牌按车龄分组统计:")
print(multi_stats)

# 6. 数据可视化
print("\n" + "=" * 80)
print("6. 数据可视化")
print("=" * 80)

# 创建图形
fig = plt.figure(figsize=(20, 12))

# 6.1 各品牌车辆数量分布 (前15名)
ax1 = plt.subplot(2, 3, 1)
top_15_brands = brand_counts.head(15)
top_15_brands.plot(kind='barh', ax=ax1, color='steelblue')
ax1.set_xlabel('车辆数量')
ax1.set_ylabel('品牌')
ax1.set_title('各品牌车辆数量分布 (前15名)', fontsize=14, fontweight='bold')
ax1.grid(axis='x', alpha=0.3)

# 6.2 热门品牌平均价格对比
ax2 = plt.subplot(2, 3, 2)
popular_brand_stats_top10 = popular_brand_stats.head(10)
popular_brand_stats_top10['Price_mean'].plot(kind='bar', ax=ax2, color='coral')
ax2.set_xlabel('品牌')
ax2.set_ylabel('平均价格 ($)')
ax2.set_title('热门品牌平均价格对比 (前10名)', fontsize=14, fontweight='bold')
ax2.tick_params(axis='x', rotation=45)
ax2.grid(axis='y', alpha=0.3)

# 6.3 车龄与平均价格关系
ax3 = plt.subplot(2, 3, 3)
age_stats['Price_mean'].plot(kind='bar', ax=ax3, color='lightgreen')
ax3.set_xlabel('车龄分组')
ax3.set_ylabel('平均价格 ($)')
ax3.set_title('不同车龄分组的平均价格', fontsize=14, fontweight='bold')
ax3.tick_params(axis='x', rotation=45)
ax3.grid(axis='y', alpha=0.3)

# 6.4 里程与平均价格关系
ax4 = plt.subplot(2, 3, 4)
miles_stats['Price_mean'].plot(kind='bar', ax=ax4, color='plum')
ax4.set_xlabel('里程分组')
ax4.set_ylabel('平均价格 ($)')
ax4.set_title('不同里程分组的平均价格', fontsize=14, fontweight='bold')
ax4.tick_params(axis='x', rotation=45)
ax4.grid(axis='y', alpha=0.3)

# 6.5 价格分布箱线图
ax5 = plt.subplot(2, 3, 5)
df_top_brands = df[df['Brand'].isin(top_brands)]
df_top_brands.boxplot(column='Price', by='Brand', ax=ax5)
ax5.set_xlabel('品牌')
ax5.set_ylabel('价格 ($)')
ax5.set_title('热门品牌价格分布箱线图', fontsize=14, fontweight='bold')
plt.suptitle('')  # 移除默认标题
ax5.grid(alpha=0.3)

# 6.6 里程与价格散点图
ax6 = plt.subplot(2, 3, 6)
scatter = ax6.scatter(df['Miles'], df['Price'], c=df['Age'], cmap='viridis', alpha=0.5, s=10)
ax6.set_xlabel('里程 (英里)')
ax6.set_ylabel('价格 ($)')
ax6.set_title('里程与价格关系散点图 (颜色表示车龄)', fontsize=14, fontweight='bold')
cbar = plt.colorbar(scatter, ax=ax6)
cbar.set_label('车龄 (年)')
ax6.grid(alpha=0.3)

plt.tight_layout()
plt.savefig('分组聚合分析结果.png', dpi=300, bbox_inches='tight')
print("\n可视化图表已保存为: 分组聚合分析结果.png")
# plt.show()

# 7. 高级聚合分析
print("\n" + "=" * 80)
print("7. 高级聚合分析")
print("=" * 80)

# 7.1 使用pivot_table进行透视分析
pivot_table = pd.pivot_table(
    df_top,
    values='Price',
    index='Brand',
    columns='Age_Group',
    aggfunc='mean',
    fill_value=0
).round(2)

print(f"\n热门品牌按车龄的价格透视表:")
print(pivot_table)

# 7.2 创建热力图
fig, ax = plt.subplots(figsize=(10, 6))
sns.heatmap(pivot_table, annot=True, fmt='.0f', cmap='YlOrRd', ax=ax, cbar_kws={'label': '平均价格 ($)'})
ax.set_title('热门品牌不同车龄的平均价格热力图', fontsize=14, fontweight='bold')
ax.set_xlabel('车龄分组')
ax.set_ylabel('品牌')
plt.tight_layout()
plt.savefig('价格热力图.png', dpi=300, bbox_inches='tight')
print("\n热力图已保存为: 价格热力图.png")
#plt.show()