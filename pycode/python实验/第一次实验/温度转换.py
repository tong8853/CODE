def CToF(c):
    return round(c * 9/5 + 32, 2) #保留两位小数
def FToC(f):
    return round((f - 32) * 5/9, 2)

choice = input("请选择转换类型（1：摄氏度转华氏度；2：华氏度转摄氏度）：")
if choice == '1':
    c = float(input("请输入摄氏度数值："))
    print(f"{c} 摄氏度 = {CToF(c)} 华氏度")
elif choice == '2':
    f = float(input("请输入华氏度数值："))
    print(f"{f} 华氏度 = {FToC(f)} 摄氏度")
else:
    print("输入错误")