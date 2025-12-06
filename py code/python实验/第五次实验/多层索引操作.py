import pandas as pd
import numpy as np

#创建多层索引
idx = pd.MultiIndex.from_arrays([
    ['1班', '1班', '1班', '2班', '2班', '2班'],
    ['张三', '李四', '王五', '鲁班', '张三丰', '张无忌']
], names=['班级', '姓名'])

cols = pd.MultiIndex.from_product([
    ['期中', '期末'],
    ['语文', '数学', '英语']
], names=['时间', '科目'])

data = [
    [40, 51, 30, 16, 57, 45],
    [74, 45, 70, 48, 75, 1],
    [57, 45, 35, 25, 22, 76],
    [93, 80, 69, 31, 17, 29],
    [90, 38, 36, 77, 56, 30],
    [35, 50, 79, 45, 38, 76]
]

df = pd.DataFrame(data, index=idx, columns=cols)

print("原始数据：")
print(df)

#选取子集
print("1. 选取1班的数据：")
print(df.loc['1班'])

print("2. 选取张三的成绩：")
print(df.loc[('1班', '张三')])

print("3. 选取期中成绩：")
print(df['期中'])

print("4. 选取期末数学成绩：")
print(df[('期末', '数学')])

#交换分层
print("5. 交换行索引层级：")
df_swap = df.swaplevel('班级', '姓名')
print(df_swap)

print("6. 交换列索引层级：")
df_swap_col = df.swaplevel('时间', '科目', axis=1)
print(df_swap_col)

#排序
print("7. 按索引排序：")
print(df.sort_index())

print("8. 按姓名排序：")
print(df.sort_index(level='姓名'))

print("9. 按期中语文成绩排序：")
print(df.sort_values(by=('期中', '语文'), ascending=False))

#计算总分
df['总分'] = df.sum(axis=1)
print("10. 添加总分列：")
print(df)

#统计
print("11. 各班平均分：")
print(df.groupby(level='班级').mean())

print("12. 期中语文最高分：")
max_idx = df[('期中', '语文')].idxmax()
print(f"学生: {max_idx}, 分数: {df.loc[max_idx, ('期中', '语文')]}")