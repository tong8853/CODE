#superstore_analysis.py
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from datetime import datetime
import warnings
warnings.filterwarnings('ignore')

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

print("="*80)
print("实验七：大型超市商品订购数据分析")
print("="*80)

###
# 1.数据加载与预处理
###
print("\n【第一部分：数据加载和预处理】")
print("-"*80)

# 1. 加载数据
df = pd.read_csv('SuperStoreOrders.csv', encoding='utf-8')
print(f"\n1. 数据集基本信息：")
print(f"   - 数据集形状：{df.shape}")
print(f"   - 行数：{df.shape[0]:,}")
print(f"   - 列数：{df.shape[1]}")

# 2. 查看数据结构
print(f"\n2. 数据列信息：")
print(df.info())

# 3. 查看前几行数据
print(f"\n3. 数据前5行：")
print(df.head())

# 4. 数据预处理
print(f"\n4. 数据预处理：")

# 检查缺失值
missing_values = df.isnull().sum()
print(f"\n   缺失值统计：")
print(missing_values[missing_values > 0])

# 检查重复值
duplicates = df.duplicated().sum()
print(f"\n   重复行数：{duplicates}")

# 转换日期列
date_columns = ['order_date', 'ship_date']
for col in date_columns:
    df[col] = pd.to_datetime(df[col], format='%d/%m/%Y', errors='coerce')
    
print(f"\n   日期列已转换为datetime格式")

# 数据类型转换
numeric_columns = ['sales', 'quantity', 'discount', 'profit', 'shipping_cost']
for col in numeric_columns:
    # 处理可能的千位分隔符
    if df[col].dtype == 'object':
        df[col] = df[col].str.replace(',', '').astype(float)
    
print(f"   数值列已确保为数值类型")

# 基本统计信息
print(f"\n5. 数值列统计信息：")
print(df[numeric_columns].describe())

###
# 2.分组和聚合分析
###
print("\n\n【第二部分：分组和聚合分析】")
print("-"*80)

# 1. 按国家分析
print("\n1. 按国家分析销售情况（Top 10）：")
country_analysis = df.groupby('country').agg({
    'sales': 'sum',
    'quantity': 'sum',
    'discount': 'mean',
    'profit': 'sum',
    'order_id': 'count'
}).round(2)
country_analysis.columns = ['总销售额', '总销量', '平均折扣', '总利润', '订单数']
country_analysis = country_analysis.sort_values('总销售额', ascending=False)
print(country_analysis.head(10))

# 2. 按地区分析
print("\n2. 按地区分析销售情况：")
region_analysis = df.groupby('region').agg({
    'sales': 'sum',
    'quantity': 'sum',
    'discount': 'mean',
    'profit': 'sum',
    'order_id': 'count'
}).round(2)
region_analysis.columns = ['总销售额', '总销量', '平均折扣', '总利润', '订单数']
region_analysis = region_analysis.sort_values('总销售额', ascending=False)
print(region_analysis)

# 3. 按市场分析
print("\n3. 按市场分析销售情况：")
market_analysis = df.groupby('market').agg({
    'sales': 'sum',
    'quantity': 'sum',
    'discount': 'mean',
    'profit': 'sum',
    'order_id': 'count'
}).round(2)
market_analysis.columns = ['总销售额', '总销量', '平均折扣', '总利润', '订单数']
market_analysis = market_analysis.sort_values('总销售额', ascending=False)
print(market_analysis)

# 4. 按商品类别分析
print("\n4. 按商品类别分析销售情况：")
category_analysis = df.groupby('category').agg({
    'sales': 'sum',
    'quantity': 'sum',
    'discount': 'mean',
    'profit': 'sum',
    'order_id': 'count'
}).round(2)
category_analysis.columns = ['总销售额', '总销量', '平均折扣', '总利润', '订单数']
category_analysis = category_analysis.sort_values('总销售额', ascending=False)
print(category_analysis)

# 5. 按子类别分析
print("\n5. 按子类别分析销售情况（Top 10）：")
subcategory_analysis = df.groupby('sub_category').agg({
    'sales': 'sum',
    'quantity': 'sum',
    'discount': 'mean',
    'profit': 'sum'
}).round(2)
subcategory_analysis.columns = ['总销售额', '总销量', '平均折扣', '总利润']
subcategory_analysis = subcategory_analysis.sort_values('总销售额', ascending=False)
print(subcategory_analysis.head(10))

# 6. 折扣与销售额、利润的关系分析
print("\n6. 折扣与销售额、利润的关系分析：")
# 创建折扣区间
df['discount_range'] = pd.cut(df['discount'], 
                               bins=[0, 0.1, 0.2, 0.3, 0.5, 1.0],
                               labels=['0-10%', '10-20%', '20-30%', '30-50%', '50%+'])

discount_analysis = df.groupby('discount_range').agg({
    'sales': 'mean',
    'profit': 'mean',
    'quantity': 'mean',
    'order_id': 'count'
}).round(2)
discount_analysis.columns = ['平均销售额', '平均利润', '平均销量', '订单数']
print(discount_analysis)

###
# 3.时间序列分析
###
print("\n\n【第三部分：时间序列分析】")
print("-"*80)

# 1. 按年份分析
print("\n1. 按年份分析销售趋势：")
yearly_analysis = df.groupby('year').agg({
    'sales': 'sum',
    'profit': 'sum',
    'quantity': 'sum',
    'order_id': 'count'
}).round(2)
yearly_analysis.columns = ['总销售额', '总利润', '总销量', '订单数']
print(yearly_analysis)

# 2. 按月份分析
print("\n2. 按月份分析销售趋势：")
df['month'] = df['order_date'].dt.month
monthly_analysis = df.groupby('month').agg({
    'sales': 'sum',
    'profit': 'sum',
    'quantity': 'sum'
}).round(2)
monthly_analysis.columns = ['总销售额', '总利润', '总销量']
monthly_analysis.index = ['1月', '2月', '3月', '4月', '5月', '6月', 
                          '7月', '8月', '9月', '10月', '11月', '12月']
print(monthly_analysis)

# 3. 按年-月分析
print("\n3. 按年-月分析销售趋势（前12个月）：")
df['year_month'] = df['order_date'].dt.to_period('M')
time_series = df.groupby('year_month').agg({
    'sales': 'sum',
    'profit': 'sum',
    'quantity': 'sum'
}).round(2)
time_series.columns = ['总销售额', '总利润', '总销量']
print(time_series.head(12))

# 4. 季度分析
print("\n4. 按季度分析销售趋势：")
df['quarter'] = df['order_date'].dt.quarter
quarterly_analysis = df.groupby(['year', 'quarter']).agg({
    'sales': 'sum',
    'profit': 'sum',
    'quantity': 'sum'
}).round(2)
quarterly_analysis.columns = ['总销售额', '总利润', '总销量']
print(quarterly_analysis.head(12))

###
# 4.数据可视化
###
print("\n\n【第四部分：数据可视化】")
print("-"*80)

# 创建图形保存目录
import os
if not os.path.exists('analysis_results'):
    os.makedirs('analysis_results')

# 1. 各市场销售额对比
plt.figure(figsize=(12, 6))
market_sales = df.groupby('market')['sales'].sum().sort_values(ascending=False)
plt.subplot(1, 2, 1)
market_sales.plot(kind='bar', color='steelblue')
plt.title('各市场总销售额对比', fontsize=14, fontweight='bold')
plt.xlabel('市场', fontsize=12)
plt.ylabel('销售额', fontsize=12)
plt.xticks(rotation=45)
plt.grid(axis='y', alpha=0.3)

# 各市场利润对比
market_profit = df.groupby('market')['profit'].sum().sort_values(ascending=False)
plt.subplot(1, 2, 2)
market_profit.plot(kind='bar', color='coral')
plt.title('各市场总利润对比', fontsize=14, fontweight='bold')
plt.xlabel('市场', fontsize=12)
plt.ylabel('利润', fontsize=12)
plt.xticks(rotation=45)
plt.grid(axis='y', alpha=0.3)
plt.tight_layout()
plt.savefig('analysis_results/1_market_comparison.png', dpi=300, bbox_inches='tight')
print("\n图1：各市场销售额和利润对比图已保存")

# 2. 商品类别销售分析
plt.figure(figsize=(14, 6))
category_sales = df.groupby('category')['sales'].sum().sort_values(ascending=False)
plt.subplot(1, 2, 1)
colors = ['#FF6B6B', '#4ECDC4', '#45B7D1']
plt.pie(category_sales, labels=category_sales.index, autopct='%1.1f%%', 
        colors=colors, startangle=90)
plt.title('各类别销售额占比', fontsize=14, fontweight='bold')

# 子类别Top10
subcategory_sales = df.groupby('sub_category')['sales'].sum().sort_values(ascending=False).head(10)
plt.subplot(1, 2, 2)
subcategory_sales.plot(kind='barh', color='teal')
plt.title('销售额Top 10子类别', fontsize=14, fontweight='bold')
plt.xlabel('销售额', fontsize=12)
plt.ylabel('子类别', fontsize=12)
plt.grid(axis='x', alpha=0.3)
plt.tight_layout()
plt.savefig('analysis_results/2_category_analysis.png', dpi=300, bbox_inches='tight')
print("图2：商品类别销售分析图已保存")

# 3. 时间序列分析 - 月度趋势
plt.figure(figsize=(14, 8))

# 月度销售额趋势
plt.subplot(2, 1, 1)
time_series_monthly = df.groupby('year_month')['sales'].sum()
plt.plot(time_series_monthly.index.astype(str), time_series_monthly.values, 
         marker='o', linewidth=2, markersize=4, color='steelblue')
plt.title('月度销售额趋势', fontsize=14, fontweight='bold')
plt.xlabel('时间', fontsize=12)
plt.ylabel('销售额', fontsize=12)
plt.xticks(rotation=45)
plt.grid(True, alpha=0.3)

# 月度利润趋势
plt.subplot(2, 1, 2)
time_series_profit = df.groupby('year_month')['profit'].sum()
plt.plot(time_series_profit.index.astype(str), time_series_profit.values, 
         marker='s', linewidth=2, markersize=4, color='coral')
plt.title('月度利润趋势', fontsize=14, fontweight='bold')
plt.xlabel('时间', fontsize=12)
plt.ylabel('利润', fontsize=12)
plt.xticks(rotation=45)
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig('analysis_results/3_time_series_trend.png', dpi=300, bbox_inches='tight')
print("图3：时间序列趋势图已保存")

# 4. 折扣与销售额、利润的关系
plt.figure(figsize=(14, 6))

# 折扣与销售额
plt.subplot(1, 2, 1)
discount_sales = df.groupby('discount_range')['sales'].mean()
discount_sales.plot(kind='bar', color='skyblue')
plt.title('不同折扣区间的平均销售额', fontsize=14, fontweight='bold')
plt.xlabel('折扣区间', fontsize=12)
plt.ylabel('平均销售额', fontsize=12)
plt.xticks(rotation=45)
plt.grid(axis='y', alpha=0.3)

# 折扣与利润
plt.subplot(1, 2, 2)
discount_profit = df.groupby('discount_range')['profit'].mean()
discount_profit.plot(kind='bar', color='lightcoral')
plt.title('不同折扣区间的平均利润', fontsize=14, fontweight='bold')
plt.xlabel('折扣区间', fontsize=12)
plt.ylabel('平均利润', fontsize=12)
plt.xticks(rotation=45)
plt.grid(axis='y', alpha=0.3)
plt.tight_layout()
plt.savefig('analysis_results/4_discount_analysis.png', dpi=300, bbox_inches='tight')
print("图4：折扣分析图已保存")

# 5. Top 10 国家销售分析
plt.figure(figsize=(14, 6))
top10_countries = df.groupby('country')['sales'].sum().sort_values(ascending=False).head(10)
plt.subplot(1, 2, 1)
top10_countries.plot(kind='barh', color='mediumseagreen')
plt.title('销售额Top 10国家', fontsize=14, fontweight='bold')
plt.xlabel('销售额', fontsize=12)
plt.ylabel('国家', fontsize=12)
plt.grid(axis='x', alpha=0.3)

# Top 10 国家利润
top10_countries_profit = df.groupby('country')['profit'].sum().sort_values(ascending=False).head(10)
plt.subplot(1, 2, 2)
top10_countries_profit.plot(kind='barh', color='mediumpurple')
plt.title('利润Top 10国家', fontsize=14, fontweight='bold')
plt.xlabel('利润', fontsize=12)
plt.ylabel('国家', fontsize=12)
plt.grid(axis='x', alpha=0.3)
plt.tight_layout()
plt.savefig('analysis_results/5_top10_countries.png', dpi=300, bbox_inches='tight')
print("图5：Top 10国家分析图已保存")

# 6. 季度销售和利润对比
plt.figure(figsize=(12, 6))
quarterly_data = df.groupby(['year', 'quarter']).agg({'sales': 'sum', 'profit': 'sum'})
quarterly_data = quarterly_data.reset_index()
quarterly_data['period'] = quarterly_data['year'].astype(str) + '-Q' + quarterly_data['quarter'].astype(str)

x = range(len(quarterly_data))
width = 0.35

plt.bar([i - width/2 for i in x], quarterly_data['sales'], width, label='销售额', color='steelblue')
plt.bar([i + width/2 for i in x], quarterly_data['profit'], width, label='利润', color='coral')
plt.xlabel('季度', fontsize=12)
plt.ylabel('金额', fontsize=12)
plt.title('季度销售额与利润对比', fontsize=14, fontweight='bold')
plt.xticks(x, quarterly_data['period'], rotation=45)
plt.legend()
plt.grid(axis='y', alpha=0.3)
plt.tight_layout()
plt.savefig('analysis_results/6_quarterly_comparison.png', dpi=300, bbox_inches='tight')
print("图6：季度对比图已保存")

# 7. 销售额与利润散点图（按类别）
plt.figure(figsize=(10, 8))
categories = df['category'].unique()
colors_map = {'Technology': 'red', 'Furniture': 'blue', 'Office Supplies': 'green'}

for category in categories:
    category_data = df[df['category'] == category]
    plt.scatter(category_data['sales'], category_data['profit'], 
               alpha=0.5, s=30, label=category, 
               color=colors_map.get(category, 'gray'))

plt.xlabel('销售额', fontsize=12)
plt.ylabel('利润', fontsize=12)
plt.title('销售额与利润关系（按类别）', fontsize=14, fontweight='bold')
plt.legend()
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig('analysis_results/7_sales_profit_scatter.png', dpi=300, bbox_inches='tight')
print("图7：销售额与利润散点图已保存")

# 8. 热力图 - 各地区各类别销售额
plt.figure(figsize=(12, 8))
heatmap_data = df.pivot_table(values='sales', index='region', columns='category', aggfunc='sum')
sns.heatmap(heatmap_data, annot=True, fmt='.0f', cmap='YlOrRd', cbar_kws={'label': '销售额'})
plt.title('各地区各类别销售额热力图', fontsize=14, fontweight='bold')
plt.xlabel('商品类别', fontsize=12)
plt.ylabel('地区', fontsize=12)
plt.tight_layout()
plt.savefig('analysis_results/8_region_category_heatmap.png', dpi=300, bbox_inches='tight')
print("图8：地区-类别销售额热力图已保存")

###
# 5.关键发现和总结
###
print("\n\n【第五部分：关键发现和总结】")
print("-"*80)

print("\n1. 市场分析关键发现：")
print(f"   - 销售额最高的市场：{market_sales.index[0]}，销售额：{market_sales.values[0]:,.2f}")
print(f"   - 利润最高的市场：{market_profit.index[0]}，利润：{market_profit.values[0]:,.2f}")

print("\n2. 商品类别关键发现：")
print(f"   - 销售额最高的类别：{category_sales.index[0]}，销售额：{category_sales.values[0]:,.2f}")
category_profit = df.groupby('category')['profit'].sum().sort_values(ascending=False)
print(f"   - 利润最高的类别：{category_profit.index[0]}，利润：{category_profit.values[0]:,.2f}")

print("\n3. 时间趋势关键发现：")
yearly_growth = yearly_analysis['总销售额'].pct_change() * 100
print(f"   - 年度销售额增长率：")
for year, growth in yearly_growth.items():
    if not pd.isna(growth):
        print(f"     {year}年：{growth:+.2f}%")

print("\n4. 折扣策略发现：")
print(f"   - 平均折扣率：{df['discount'].mean():.2%}")
print(f"   - 折扣对利润的影响：折扣越高，平均利润越低")

print("\n5. 地区分析发现：")
top_region = region_analysis.index[0]
print(f"   - 销售额最高的地区：{top_region}")
print(f"   - 该地区总销售额：{region_analysis.loc[top_region, '总销售额']:,.2f}")
print(f"   - 该地区总利润：{region_analysis.loc[top_region, '总利润']:,.2f}")
