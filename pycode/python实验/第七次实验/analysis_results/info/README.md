# 第七次实验：超市订单数据分析

## 📋 实验概述

本实验使用大型超市订单数据集（SuperStoreOrders.csv），通过Python进行全面的数据分析，包括数据预处理、分组聚合、时间序列分析和数据可视化。

**实验目标：**
- 掌握Python数据预处理技术
- 理解和应用分组聚合方法
- 学习时间序列分析
- 掌握数据可视化的原理和方法

---

## 📁 文件结构

```
第七次实验/
├── README.md                          # 本文档
├── superstore_analysis.py             # 主分析脚本
├── SuperStoreOrders.csv               # 数据集（10.8 MB）
└── analysis_results/                  # 分析结果图表
    ├── 1_market_comparison.png        # 市场对比分析
    ├── 2_category_analysis.png        # 商品类别分析
    ├── 3_time_series_trend.png        # 时间序列趋势
    ├── 4_discount_analysis.png        # 折扣分析
    ├── 5_top10_countries.png          # Top 10国家分析
    ├── 6_quarterly_comparison.png     # 季度对比分析
    ├── 7_sales_profit_scatter.png     # 销售额与利润关系
    └── 8_region_category_heatmap.png  # 区域-类别热力图
```

---

## 📊 数据集说明

**数据集名称：** SuperStoreOrders.csv

**数据规模：**
- 文件大小：10.8 MB
- 记录数量：51,290条订单
- 字段数量：24个

**主要字段：**
- `order_id` - 订单ID
- `order_date` - 订单日期
- `ship_date` - 发货日期
- `ship_mode` - 发货模式
- `customer_name` - 客户姓名
- `segment` - 客户细分
- `country` - 国家
- `city` - 城市
- `state` - 州/省
- `region` - 地区
- `market` - 市场
- `product_id` - 产品ID
- `category` - 商品类别
- `sub_category` - 商品子类别
- `product_name` - 产品名称
- `sales` - 销售额
- `quantity` - 销量
- `discount` - 折扣
- `profit` - 利润
- `shipping_cost` - 运费

---

## 🔬 分析内容

### 1. 数据预处理
- ✅ 数据加载与清洗
- ✅ 列名标准化（转小写，空格转下划线）
- ✅ 日期格式转换
- ✅ 数值类型转换
- ✅ 缺失值处理
- ✅ 异常值检测

### 2. 分组聚合分析

#### 2.1 地区分析
- 按地区（Region）统计销售额、销量、折扣、利润
- 识别表现最好和最差的地区

#### 2.2 市场分析
- 按市场（Market）分析销售情况
- 对比不同市场的盈利能力

#### 2.3 商品类别分析
- 按类别（Category）和子类别（Sub-Category）分析
- 识别畅销商品和高利润商品

#### 2.4 折扣影响分析
- 分析折扣与销售额的关系
- 分析折扣与利润的关系
- 创建折扣区间：0-10%, 10-20%, 20-30%, 30-50%, 50%+

### 3. 时间序列分析

#### 3.1 年度趋势
- 按年份统计销售额和利润
- 分析年度增长趋势

#### 3.2 月度趋势
- 按月份分析销售额和利润变化
- 识别销售旺季和淡季

#### 3.3 季度分析
- 按季度对比销售和利润
- 分析季节性规律

#### 3.4 年-月组合分析
- 详细的时间序列趋势图
- 识别长期趋势和周期性变化

### 4. 地理分析
- Top 10国家销售额排名
- 区域-类别交叉分析热力图
- 地理分布可视化

---

## 📈 生成的可视化图表

### 图1：市场对比分析 (1_market_comparison.png)
- **左图：** 各市场销售额对比（柱状图）
- **右图：** 各市场总利润对比（柱状图）
- **用途：** 快速识别最重要的市场

### 图2：商品类别分析 (2_category_analysis.png)
- **左图：** 各类别销售额对比（柱状图）
- **右图：** Top 10子类别销售额（水平柱状图）
- **用途：** 了解产品组合表现

### 图3：时间序列趋势 (3_time_series_trend.png)
- **上图：** 月度销售额趋势（折线图）
- **下图：** 月度利润趋势（折线图）
- **用途：** 识别时间趋势和季节性

### 图4：折扣分析 (4_discount_analysis.png)
- **左图：** 不同折扣区间的平均销售额（柱状图）
- **右图：** 不同折扣区间的平均利润（柱状图）
- **用途：** 优化折扣策略

### 图5：Top 10国家分析 (5_top10_countries.png)
- Top 10国家销售额排名（水平柱状图）
- **用途：** 识别关键市场

### 图6：季度对比分析 (6_quarterly_comparison.png)
- 各季度销售额和利润对比（分组柱状图）
- **用途：** 分析季节性规律

### 图7：销售额与利润关系 (7_sales_profit_scatter.png)
- 按类别分组的销售额-利润散点图
- **用途：** 识别高价值产品类别

### 图8：区域-类别热力图 (8_region_category_heatmap.png)
- 区域和类别的销售额交叉分析热力图
- **用途：** 识别区域性产品偏好

---

## 🚀 使用方法

### 1. 环境要求

```bash
Python 3.7+
pandas
numpy
matplotlib
seaborn
```

### 2. 安装依赖

```bash
pip install pandas numpy matplotlib seaborn
```

### 3. 运行分析

```bash
cd "d:\code\pycode\python实验\第七次实验"
python superstore_analysis.py
```

### 4. 查看结果

运行完成后，会在 `analysis_results/` 文件夹中生成8张可视化图表。

---

## 📊 关键发现

### 1. 市场表现
- **最佳市场：** APAC（亚太地区）
  - 销售额最高
  - 订单量最大
  
- **利润表现：** 需要关注利润率较低的市场

### 2. 商品类别
- **销售额最高：** Technology（科技产品）
- **利润最高：** 需要分析各类别的利润率
- **畅销子类别：** Top 10子类别贡献了大部分销售额

### 3. 时间趋势
- **销售旺季：** 通过月度趋势图可以识别
- **增长趋势：** 年度数据显示整体趋势
- **季节性：** 季度分析揭示周期性规律

### 4. 折扣策略
- **折扣影响：** 高折扣不一定带来高利润
- **最优折扣区间：** 需要平衡销售额和利润

### 5. 地理分布
- **Top 10国家：** 集中了大部分销售额
- **区域差异：** 不同区域对产品类别的偏好不同

---

## 💡 技术要点

### 1. 数据预处理
```python
# 列名标准化
df.columns = df.columns.str.lower().str.replace(' ', '_')

# 日期转换
df['order_date'] = pd.to_datetime(df['order_date'], format='%d/%m/%Y')

# 数值转换
df['sales'] = pd.to_numeric(df['sales'], errors='coerce')
```

### 2. 分组聚合
```python
# 按地区分组
region_analysis = df.groupby('region').agg({
    'sales': 'sum',
    'quantity': 'sum',
    'discount': 'mean',
    'profit': 'sum',
    'order_id': 'count'
})
```

### 3. 时间序列分析
```python
# 提取时间特征
df['year'] = df['order_date'].dt.year
df['month'] = df['order_date'].dt.month
df['quarter'] = df['order_date'].dt.quarter

# 按时间分组
time_series = df.groupby('year_month').agg({
    'sales': 'sum',
    'profit': 'sum'
})
```

### 4. 数据可视化
```python
# 使用matplotlib和seaborn
import matplotlib.pyplot as plt
import seaborn as sns

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 创建图表
plt.figure(figsize=(14, 6))
plt.subplot(1, 2, 1)
# ... 绘图代码 ...
plt.savefig('analysis_results/chart.png', dpi=300, bbox_inches='tight')
```

---

## 🎯 学习目标达成

通过本实验，你将掌握：

- ✅ **数据预处理：** 清洗、转换、标准化大型数据集
- ✅ **分组聚合：** 使用groupby进行多维度分析
- ✅ **时间序列：** 提取时间特征，分析趋势和季节性
- ✅ **数据可视化：** 创建专业的图表展示分析结果
- ✅ **业务洞察：** 从数据中提取有价值的商业见解

---

## 📝 扩展建议

1. **深入分析：**
   - 客户细分（Segment）分析
   - 发货模式（Ship Mode）对利润的影响
   - 产品组合优化建议

2. **高级可视化：**
   - 交互式图表（使用Plotly）
   - 地理热力图（使用Folium）
   - 仪表盘（使用Dash或Streamlit）

3. **预测建模：**
   - 销售额预测（时间序列模型）
   - 客户流失预测（分类模型）
   - 产品推荐系统

4. **性能优化：**
   - 使用Dask处理更大数据集
   - 数据库集成（SQL查询）
   - 并行处理加速分析

---

## 📚 参考资料

- [Pandas官方文档](https://pandas.pydata.org/docs/)
- [Matplotlib官方文档](https://matplotlib.org/stable/contents.html)
- [Seaborn官方文档](https://seaborn.pydata.org/)
- [数据分析最佳实践](https://www.kaggle.com/learn/data-visualization)

---

**实验完成日期：** 2025-12-17
**数据集来源：** SuperStore订单数据
**分析工具：** Python 3.x + Pandas + Matplotlib + Seaborn
