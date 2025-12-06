import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

#设置中文字体支持
plt.rcParams['font.sans-serif'] = ['SimHei']  #用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  #用来正常显示负号

#读取数据
df = pd.read_csv('Montgomery_County_Employee_Salaries_2020.csv')

#计算总工资
df['Total Salary'] = df['Base Salary'] + df['2020 Overtime Pay'] + df['2020 Longevity Pay']

print("=" * 80)
print("蒙哥马利县雇员工资分析报告")
print("=" * 80)

#==================== 任务1：统计最低和最高工资 ====================
print("\n【任务1】最低和最高工资统计")
print("-" * 80)

#按总工资排序
df_srt = df.sort_values('Total Salary')

#最低10位雇员
print("\n最低10位雇员工资：")
low_10 = df_srt.head(10)[['Department Name', 'Division', 'Base Salary', 
                          '2020 Overtime Pay', '2020 Longevity Pay', 'Total Salary', 'Grade']]
print(low_10.to_string(index=False))

#最高10位雇员
print("\n最高10位雇员工资：")
high_10 = df_srt.tail(10)[['Department Name', 'Division', 'Base Salary', 
                           '2020 Overtime Pay', '2020 Longevity Pay', 'Total Salary', 'Grade']]
print(high_10.to_string(index=False))

#计算最高和最低工资之差
min_sal = df_srt['Total Salary'].iloc[0]
max_sal = df_srt['Total Salary'].iloc[-1]
sal_diff = max_sal - min_sal

print(f"\n最低工资: ${min_sal:,.2f}")
print(f"最高工资: ${max_sal:,.2f}")
print(f"工资差额: ${sal_diff:,.2f}")

#==================== 任务2：各部门和ABS部门各division的平均工资 ====================
print("\n【任务2】部门和分部平均工资分析")
print("-" * 80)

#计算各department的平均工资
dept_avg = df.groupby('Department Name')['Total Salary'].mean().sort_values(ascending=False)
print("\n各部门平均工资（前20个）：")
print(dept_avg.head(20))

#绘制各部门平均工资直方图
plt.figure(figsize=(14, 8))
dept_avg.plot(kind='bar')
plt.title('各部门平均工资', fontsize=16, fontweight='bold')
plt.xlabel('部门名称', fontsize=12)
plt.ylabel('平均工资 ($)', fontsize=12)
plt.xticks(rotation=45, ha='right')
plt.tight_layout()
plt.grid(axis='y', alpha=0.3)
plt.savefig('department_avg_salary.png', dpi=300, bbox_inches='tight')
print("\n部门平均工资图表已保存为: department_avg_salary.png")

#计算ABS部门各division的平均工资
abs_df = df[df['Department'] == 'ABS']
abs_div_avg = abs_df.groupby('Division')['Total Salary'].mean().sort_values(ascending=False)
print(f"\nABS部门各division平均工资（共{len(abs_div_avg)}个division）：")
print(abs_div_avg)

#绘制ABS部门各division平均工资直方图
plt.figure(figsize=(16, 10))
abs_div_avg.plot(kind='bar', color='steelblue')
plt.title('ABS部门各Division平均工资', fontsize=16, fontweight='bold')
plt.xlabel('Division名称', fontsize=12)
plt.ylabel('平均工资 ($)', fontsize=12)
plt.xticks(rotation=45, ha='right')
plt.tight_layout()
plt.grid(axis='y', alpha=0.3)
plt.savefig('abs_division_avg_salary.png', dpi=300, bbox_inches='tight')
print("ABS部门division平均工资图表已保存为: abs_division_avg_salary.png")

#==================== 任务3：工龄工资和加班费占比，级别与总工资关系 ====================
print("\n【任务3】工资组成分析和级别关系")
print("-" * 80)

#计算工龄工资和加班费在总工资中的占比
tot_base = df['Base Salary'].sum()
tot_ot = df['2020 Overtime Pay'].sum()
tot_long = df['2020 Longevity Pay'].sum()
tot_all = df['Total Salary'].sum()

ot_ratio = (tot_ot / tot_all) * 100
long_ratio = (tot_long / tot_all) * 100
base_ratio = (tot_base / tot_all) * 100

print(f"\n工资组成占比：")
print(f"基本工资占比: {base_ratio:.2f}%")
print(f"加班费占比: {ot_ratio:.2f}%")
print(f"工龄工资占比: {long_ratio:.2f}%")

#绘制工资组成饼图
plt.figure(figsize=(10, 8))
lbl = ['基本工资', '加班费', '工龄工资']
sz = [base_ratio, ot_ratio, long_ratio]
clr = ['#ff9999', '#66b3ff', '#99ff99']
exp = (0.05, 0.05, 0.05)

plt.pie(sz, explode=exp, labels=lbl, colors=clr, autopct='%1.2f%%',
        shadow=True, startangle=90, textprops={'fontsize': 12})
plt.title('工资组成占比分析', fontsize=16, fontweight='bold')
plt.axis('equal')
plt.savefig('salary_composition.png', dpi=300, bbox_inches='tight')
print("\n工资组成占比图表已保存为: salary_composition.png")

#分析级别（grade）和总工资之间的关系
#过滤掉非数字的grade
df_num_grd = df[df['Grade'].apply(lambda x: str(x).isdigit())].copy()
df_num_grd['Grade'] = df_num_grd['Grade'].astype(int)

#计算各级别的平均工资
grd_avg = df_num_grd.groupby('Grade')['Total Salary'].agg(['mean', 'count']).sort_index()
print(f"\n各级别(Grade)平均工资统计：")
print(grd_avg)

#绘制级别与平均工资的关系图
plt.figure(figsize=(14, 8))
plt.subplot(2, 1, 1)
plt.plot(grd_avg.index, grd_avg['mean'], marker='o', linewidth=2, markersize=6)
plt.title('级别(Grade)与平均工资关系', fontsize=16, fontweight='bold')
plt.xlabel('级别 (Grade)', fontsize=12)
plt.ylabel('平均工资 ($)', fontsize=12)
plt.grid(True, alpha=0.3)

plt.subplot(2, 1, 2)
plt.bar(grd_avg.index, grd_avg['count'], color='coral', alpha=0.7)
plt.title('各级别人数分布', fontsize=16, fontweight='bold')
plt.xlabel('级别 (Grade)', fontsize=12)
plt.ylabel('人数', fontsize=12)
plt.grid(True, alpha=0.3, axis='y')

plt.tight_layout()
plt.savefig('grade_salary_relationship.png', dpi=300, bbox_inches='tight')
print("\n级别与工资关系图表已保存为: grade_salary_relationship.png")

#计算相关系数
corr = df_num_grd['Grade'].corr(df_num_grd['Total Salary'])
print(f"\n级别与总工资的相关系数: {corr:.4f}")

if corr > 0.7:
    print("结论: 级别与总工资呈强正相关关系")
elif corr > 0.4:
    print("结论: 级别与总工资呈中等正相关关系")
else:
    print("结论: 级别与总工资呈弱正相关关系")

#额外统计信息
print("\n" + "=" * 80)
print("数据集基本信息：")
print(f"总雇员数: {len(df)}")
print(f"总部门数: {df['Department Name'].nunique()}")
print(f"平均工资: ${df['Total Salary'].mean():,.2f}")
print(f"工资中位数: ${df['Total Salary'].median():,.2f}")
print(f"工资标准差: ${df['Total Salary'].std():,.2f}")
print("=" * 80)

plt.show()
