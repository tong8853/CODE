import random
# 定义父类People
class People:
    def __init__(self, name, age):
        self.name = name  # 姓名属性
        self.age = age    # 年龄属性

    def work(self):
        # 父类work方法，子类需重写
        return f"{self.name}在从事本职工作"

# 子类Teacher：继承People，新增属性并扩展方法
class Teacher(People):
    def __init__(self, name, age, salary, phone):
        # 调用父类构造方法初始化姓名和年龄
        super().__init__(name, age)
        self.salary = salary  # 新增薪水属性
        self.phone = phone    # 新增电话属性

    def work(self):
        # 重写work方法，输出"在授课"
        return f"{self.name}在授课"

    def play(self, sport):
        # 带参play方法，输出指定运动
        return f"{self.name}在从事{sport}运动"

# 子类Student：继承People，重写work方法
class Student(People):
    def work(self):
        return f"{self.name}在学习"

# 子类Driver：继承People，重写work方法
class Driver(People):
    def work(self):
        return f"{self.name}在驾驶车辆"

# 子类PoliceOfficer：继承People，重写work方法
class PoliceOfficer(People):
    def work(self):
        return f"{self.name}在维护社会治安"

# 测试代码
if __name__ == "__main__":
    # 创建子类对象列表
    people_list = [
        Teacher("张老师", 35, 8000, "13800138000"),
        Student("李同学", 18),
        Driver("王师傅", 42),
        PoliceOfficer("赵警官", 30),
        Teacher("刘老师", 28, 7500, "13900139000")
    ]

    # 循环调用所有对象的work()方法
    print("=== 所有对象工作状态 ===")
    for people in people_list:
        print(people.work())

    # 测试Teacher类的play()方法
    print("\n=== 教师运动状态 ===")
    teacher1 = people_list[0]
    print(teacher1.play("篮球"))
    teacher2 = people_list[-1]
    print(teacher2.play("跑步"))