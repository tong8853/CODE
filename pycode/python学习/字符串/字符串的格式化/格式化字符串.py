a = 10
b = "我今年%d岁了"
print(b % a)#b中的占位符被a替代

#数据初始化
name = "吴童"
age = 18
address = "地球中国"

print("----------------------")
print("姓名：%s" % name)
print("年龄：%d岁\n家庭住址：%s" % (age, address))
#使用format格式化字符串
print("----------------------")
print("姓名：{}".format(name))
print("年龄：{1}\n家庭住址：{0}".format(address, age))
print("----------------------")
print("姓名：{name}\n年龄：{age}\n家庭住址：{address}".format(name = name, age = age, address = address))
print("----------------------")

#指定精度格式化
print("{valve:.2%}".format(valve = 19/22))
print("{:.2f}".format(19/22))
print("%.2f" % (19 / 22))

#使用f-string格式化文件
print(f"年龄：{age}, 姓名：{name}")
