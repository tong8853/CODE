# 第六次实验 - 鸢尾花数据集分析

## 实验内容

基于本地鸢尾花（Iris）数据集完成数据分析与可视化。

## 数据来源

- **数据文件**: `iris.csv` (本地CSV文件)
- **样本数量**: 150个样本
- **特征**: Sepal.Length, Sepal.Width, Petal.Length, Petal.Width
- **物种**: setosa, versicolor, virginica

## 文件列表

- `iris.csv` - 本地鸢尾花数据集
- `iris_analysis.py` - 完整的分析代码
- `iris_violin_plot.png` - 小提琴图（特征分离效果）
- `iris_pairplot.png` - 散点图矩阵（特征关系）
- `iris_heatmap.png` - 相关性热力图
- `iris_boxplot.png` - 箱线图（异常值检测）

## 运行方法

```bash
python iris_analysis.py
```

## 实验任务

1. **数据加载与检查**
   - 从本地CSV文件加载数据
   - 查看数据基本信息和统计特征
   - 计算方差分析特征分布

2. **特征分离效果可视化**
   - 使用小提琴图展示特征对物种的区分能力

3. **特征关系可视化**
   - 使用散点图矩阵展示特征两两之间的关系

4. **特征相关性分析**
   - 计算相关系数矩阵
   - 使用热力图可视化相关性

5. **按物种分组统计**
   - 计算各物种的均值和标准差
   - 使用箱线图检测异常值

## 依赖库

```bash
pip install pandas numpy matplotlib seaborn
```

## 实验亮点

✨ 使用本地CSV数据集，更贴近实际数据分析场景  
✨ 增强的可视化效果（网格线、配色方案）  
✨ 详细的相关性分析和解读  
✨ 新增箱线图用于异常值检测  
✨ 完整的实验总结和关键发现  

---

**实验日期**: 2025年12月5日
