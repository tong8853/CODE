import time

#开始
print("---执行开始---")

#模拟
for i in range(0, 101, 10):
    cnt1 = i // 10 #计算星星数
    cnt2 = 10 - cnt1 #计算.的数量
    print(f"{i:3d}%[{'*' * cnt1}{'.' * cnt2}]->") #格式化输出进度条
    time.sleep(1)
    
#结束
print("---执行结束---")
    
    