def predict_child_h(father_h, mother_h, gender):
    if gender.lower() in ['女', 'f', 'female']:
        h = (father_h + mother_h - 13) / 2
        return f"预测女孩身高: {h:.1f} ±5 cm"
    elif gender.lower() in ['男', 'm', 'male']:
        h = (father_h + mother_h + 13) / 2
        return f"预测男孩身高: {h:.1f} ±5 cm"
    else:
        return "性别输入错误"

def broca_index(sex, h, w):
    if sex.lower() in ['男', 'm', 'male']:
        standard = h - 100
    else:
        standard = h - 105
    diff = w - standard
    if abs(diff) <= 0.1 * standard:
        return "标准体重"
    elif diff > 0:
        return "过胖"
    else:
        return "过瘦"

def who_bmi(sex, h, w):
    h_m = h / 100
    bmi = w / (h_m ** 2)
    if bmi < 18.5:
        return "过瘦"
    elif 18.5 <= bmi < 24:
        return "标准体重"
    elif 24 <= bmi < 28:
        return "过胖"
    else:
        return "肥胖"

# 测试代码
if __name__ == "__main__":
    gender = input("请输入性别（男/女）: ")
    h = float(input("请输入身高（cm）: "))
    w = float(input("请输入体重（kg）: "))
    father = float(input("请输入父亲身高（cm）: "))
    mother = float(input("请输入母亲身高（cm）: "))

    print(predict_child_h(father, mother, gender))
    print("布罗卡判断:", broca_index(gender, h, w))
    print("WHO BMI判断:", who_bmi(gender, h, w))