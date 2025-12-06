import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# 读取CSV文件
df = pd.read_csv('douban_top250.csv')

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 创建一个综合图表
fig, axes = plt.subplots(2, 2, figsize=(15, 12))

# 1. 评分分布
axes[0,0].hist(df['评分'], bins=20, color='skyblue', edgecolor='black')
axes[0,0].set_title('评分分布')
axes[0,0].set_xlabel('评分')
axes[0,0].set_ylabel('电影数量')

# 2. 前10评分最高
top_10_rating = df.nlargest(10, '评分')
axes[0,1].barh(top_10_rating['标题'], top_10_rating['评分'], color='lightcoral')
axes[0,1].set_title('评分最高的前10部电影')
axes[0,1].set_xlabel('评分')
axes[0,1].invert_yaxis()

# 3. 前10评价人数最多
top_10_popular = df.nlargest(10, '评价人数')
axes[1,0].barh(top_10_popular['标题'], top_10_popular['评价人数'], color='orange')
axes[1,0].set_title('评价人数最多的前10部电影')
axes[1,0].set_xlabel('评价人数')
axes[1,0].invert_yaxis()

# 4. 评分与评价人数关系
axes[1,1].scatter(df['评分'], df['评价人数'], alpha=0.6, color='green')
axes[1,1].set_title('评分与评价人数关系')
axes[1,1].set_xlabel('评分')
axes[1,1].set_ylabel('评价人数')

plt.tight_layout()
plt.show()