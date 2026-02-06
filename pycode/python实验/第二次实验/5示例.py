# 学生信息管理系统
students = {}

def add_student():
    """添加学生"""
    sid = input("请输入学号: ")
    if sid in students:
        print("学号已存在！")
        return
    name = input("请输入姓名: ")
    age = input("请输入年龄: ")
    class_name = input("请输入班级: ")
    students[sid] = {'姓名': name, '年龄': age, '班级': class_name}
    print("添加成功！")

def query_student():
    """查询学生"""
    sid = input("请输入要查询的学号: ")
    if sid in students:
        print(f"学号: {sid}")
        for key, value in students[sid].items():
            print(f"{key}: {value}")
    else:
        print("未找到该学生！")

def modify_student():
    """修改学生信息"""
    sid = input("请输入要修改的学号: ")
    if sid not in students:
        print("学号不存在！")
        return
    print("当前信息：", students[sid])
    name = input("请输入新的姓名（直接回车表示不修改）: ") or students[sid]['姓名']
    age = input("请输入新的年龄（直接回车表示不修改）: ") or students[sid]['年龄']
    class_name = input("请输入新的班级（直接回车表示不修改）: ") or students[sid]['班级']
    students[sid] = {'姓名': name, '年龄': age, '班级': class_name}
    print("修改成功！")

def delete_student():
    """删除学生"""
    sid = input("请输入要删除的学号: ")
    if sid in students:
        del students[sid]
        print("删除成功！")
    else:
        print("学号不存在！")

def show_all():
    """显示所有学生"""
    if not students:
        print("暂无学生信息。")
    else:
        for sid, info in students.items():
            print(f"学号: {sid}, 信息: {info}")

def main():
    while True:
        print("\n=== 学生学籍管理系统 ===")
        print("1. 添加学生")
        print("2. 查询学生")
        print("3. 修改学生")
        print("4. 删除学生")
        print("5. 显示所有学生")
        print("0. 退出")
        choice = input("请选择操作（0-5）: ")

        if choice == '1':
            add_student()
        elif choice == '2':
            query_student()
        elif choice == '3':
            modify_student()
        elif choice == '4':
            delete_student()
        elif choice == '5':
            show_all()
        elif choice == '0':
            print("系统退出，再见！")
            break
        else:
            print("无效选择，请重新输入。")

# 运行程序
if __name__ == "__main__":
    main()