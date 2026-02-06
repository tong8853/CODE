#输入身高和体重
h = float(input("请输入身高（m）："))
w = float(input("请输入体重（kg）："))

#计算BMI, 保留两位小数
BMI = round(w / (h ** 2), 2)

#输出BMI
print(f"BMI值为：{BMI}")

#输出类别
if BMI < 18.5:
    print("类别：偏瘦")
elif 18.5 <= BMI < 24:
    print("类别：正常")
elif 24 <= BMI < 28:
    print("类别：偏胖")
else:
    print("类别：肥胖")