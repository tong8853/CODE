#创建空集合的时候只能用set(),因为{}创建的是空字典
s1 = {}#会被认成空字典
print(type(s1))
print(s1)

s2 = set()
print(type(s2))
s3 = {1}
s4 = {1, "b", (2, 5)}
