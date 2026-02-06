#学生信息管理系统
stus = {}
#添加
def AddStu():
    id = input("请输入学号：")
    if id in stus:
        print("学号已存在")
        return
    name = input("请输入姓名: ")
    age = input("请输入年龄: ")
    _class = input("请输入班级: ")
    stus[id] = {'姓名': name, '年龄': age, '班级': _class}
    print("添加成功")
#查询    
def QStu():
    id = input("请输入要查询的学号: ")
    if id in stus:
        print(f"学号: {id}")
        for key, val in stus[id].items():
            print(f"{key}: {val}")
    else:
        print("未找到该学生")
#修改   
def XStu():
    id = input("请输入要修改的学号: ")
    if id not in stus:
        print("学号不存在！")
        return
    print("当前信息：", stus[id])
    name = input("请输入新的姓名（直接回车表示不修改）: ") or stus[id]['姓名']
    age = input("请输入新的年龄（直接回车表示不修改）: ") or stus[id]['年龄']
    _class = input("请输入新的班级（直接回车表示不修改）: ") or stus[id]['班级']
    stus[id] = {'姓名': name, '年龄': age, '班级': _class}
    print("修改成功！")
#删除
def DelStu():
    sid = input("请输入要删除的学号: ")
    if sid in stus:
        del stus[sid]
        print("删除成功！")
    else:
        print("学号不存在！")

def main():
    while True:
        print("\n=== 学生学籍管理系统 ===")
        print("1. 添加学生")
        print("2. 查询学生")
        print("3. 修改学生")
        print("4. 删除学生")
        print("0. 退出")
        choice = input("请选择操作（0-4）: ")

        if choice == '1':
            AddStu()
        elif choice == '2':
            QStu()
        elif choice == '3':
            XStu()
        elif choice == '4':
            DelStu()
        elif choice == '0':
            print("系统退出，再见！")
            break
        else:
            print("无效选择，请重新输入。")
#运行
if __name__ == "__main__":
    main()