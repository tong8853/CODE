#元组tuple,注：如果元组中只有一个元素，元素后的逗号不能省略。
t1 = ()#创建空元组
t2 = (1,)
t3 = (1, 2, 3)
t4 = (1, "c", ("c", 2))

#类型转换tuple()函数传入可迭代对象创建非空元组
t5 = tuple(range(5))
print(t5)
print(t1)

#元组是不可变类型，不支持添加元素、删除元素、排序操作
for element in t3:
    print(element, end = " ")
