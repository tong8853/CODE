import random

points = (int)(input("请输入点的数量"))
cnt = 0 #用于统计在圆里面的点的数量
for i in range(points):
    x = random.uniform(-1, 1)
    y = random.uniform(-1, 1)
    if x ** 2 + y ** 2 <= 1:
        cnt += 1
#计算圆周率
pi = 4 * cnt / points
print(f"圆周率为{pi}")
