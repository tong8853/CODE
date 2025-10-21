# 初始化用户数据库（列表中存储字典）
users = []

# 注册5个用户
with open("D:/code/py code/python实验/第二次实验/users.txt", 'r') as f:
    for line in f:
        phone, password = line.strip().split(',') #拆分手机号和密码
        users.append({"phone": phone, "password": password})

#检验4种情况
for i in range(4):
    # 登录验证
    phone = input("请输入手机号: ")
    password = input("请输入密码: ")
    found = False
    for user in users:
        if user['phone'] == phone:
            found = True
            if user['password'] == password:
                print("登录成功！")
            else:
                print("密码错误。")
            break

    if not found:
        print("手机号不存在，用户还未注册。")