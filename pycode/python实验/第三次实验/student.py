import os
# 文件名
STUDENT_FILE = 'D:\code\py code\python实验\第三次实验\student.txt'
LOG_FILE = 'D:\code\py code\python实验\第三次实验\log.txt'

def log(msg):
    """记录日志"""
    with open(LOG_FILE, 'a', encoding='utf-8') as f:
        f.write(f"{msg}\n")

def load_students():
    """从文件加载所有学生，返回列表"""
    if not os.path.exists(STUDENT_FILE):
        return []
    with open(STUDENT_FILE, 'r', encoding='utf-8') as f:
        lines = f.readlines()
    students = []
    for line in lines:
        line = line.strip()
        if line:
            students.append(line.split(','))
    return students

def save_students(students):
    """将学生列表保存到文件"""
    with open(STUDENT_FILE, 'w', encoding='utf-8') as f:
        for s in students:
            f.write(','.join(s) + '\n')

def add():
    print("\n--- 添加学生 ---")
    sid = input("学号: ").strip()
    if not sid:
        print("学号不能为空！")
        return
    students = load_students()
    if any(s[0] == sid for s in students):
        print("学号已存在！")
        return
    name = input("姓名: ")
    age = input("年龄: ")
    gender = input("性别: ")
    score = input("成绩: ")
    students.append([sid, name, age, gender, score])
    save_students(students)
    print("添加成功！")
    log(f"添加: {sid},{name},{age},{gender},{score}")

def search():
    print("\n--- 查询学生 ---")
    sid = input("学号: ")
    students = load_students()
    found = None
    for s in students:
        if s[0] == sid:
            found = s
            break
    if found:
        print(f"学号: {found[0]}, 姓名: {found[1]}, 年龄: {found[2]}, 性别: {found[3]}, 成绩: {found[4]}")
        log(f"查询: {found}")
    else:
        print("未找到！")
        log(f"查询失败: 学号 {sid} 不存在")

def update():
    print("\n--- 修改学生 ---")
    sid = input("学号: ")
    students = load_students()
    index = -1
    for i, s in enumerate(students):
        if s[0] == sid:
            index = i
            break
    if index == -1:
        print("未找到！")
        log(f"修改失败: 学号 {sid} 不存在")
        return
    s = students[index]
    print(f"当前: {s[1]}, {s[2]}, {s[3]}, {s[4]}")
    s[1] = input("新姓名(回车不改): ") or s[1]
    s[2] = input("新年龄: ") or s[2]
    s[3] = input("新性别: ") or s[3]
    s[4] = input("新成绩: ") or s[4]
    save_students(students)
    print("修改成功！")
    log(f"修改: {sid} -> {s[1]},{s[2]},{s[3]},{s[4]}")

def delete():
    print("\n--- 删除学生 ---")
    sid = input("学号: ")
    students = load_students()
    new_students = [s for s in students if s[0] != sid]
    if len(new_students) == len(students):
        print("未找到！")
        log(f"删除失败: 学号 {sid} 不存在")
        return
    save_students(new_students)
    print("删除成功！")
    log(f"删除: {sid}")

def show_all():
    print("\n--- 所有学生 ---")
    students = load_students()
    if not students:
        print("暂无数据")
        return
    for s in students:
        print(f"{s[0]} {s[1]} {s[2]} {s[3]} {s[4]}")
    log("查看全部学生")

def main():
    # 初始化日志文件
    if not os.path.exists(LOG_FILE):
        open(LOG_FILE, 'w').close()

    while True:
        print("\n=== 学生管理 ===")
        print("1. 添加  2. 查询  3. 修改")
        print("4. 删除  5. 查看  0. 退出")
        choice = input("选择: ")

        if choice == '1': add()
        elif choice == '2': search()
        elif choice == '3': update()
        elif choice == '4': delete()
        elif choice == '5': show_all()
        elif choice == '0':
            log("系统退出")
            print("再见！")
            break
        else:
            print("无效选择")

if __name__ == "__main__":
    main()