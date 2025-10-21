import ccc

gender = "男"
height = 175
weight = 70
father_h = 180
mother_h = 165

# 分别调用三个函数
result1 = ccc.predict_child_h(father_h, mother_h, gender)
result2 = ccc.broca_index(gender, height, weight)
result3 = ccc.who_bmi(gender, height, weight)

# 输出结果
print(result1)
print("布罗卡指数判断:", result2)
print("WHO BMI判断:", result3)