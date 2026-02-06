s1 = "python"
word = "th"
res = s1.find(word)
print(res)
#没找到打印-1
word = "l"
res = s1.find(word)
print(res)
#可以指定范围
res = s1.find("p", 1, 5)
print(res)
