#列表元素可以是整型、浮点型、字符串等基本类型
#也可以是列表、元组、字典等组合类型，还可以是其他自定义类型
a = [] #创建空列表
c = [1,'a','&',2.3]
b = [1,'a','&',2.3, c]

#类型转换list(),将可迭代数据转换成一个列表
d = list("python")
#列表中的元素可以通过索引和切片两种方式访问
#索引格式访问
print(b[2])
#切片格式访问 list[m:n:step]
'''
    list[m:n:step]
    step默认为1
    m可以省略，省略表示从列表第一个元素开始
    n可以省略，省略表示切片到列表最后一个元素
'''
my_list = ['p','y','t','h','o','n']
print(my_list[1:4:2])  #获取列表my_list中索引1-4的元素，步长为2
print(my_list[2:])   #获取列表中索引2-最后一个元素的元素
print(my_list[:3])   #获取列表中索引0-3的元素
print(my_list[:])  #获取列表中的所有元素

#在循环中依次访问列表中的元素
list = list("python")
for char in list:
    print(char, end = " ")
print()
#在列表的末尾添加新元素,直接修改了原列表
list.append("java")
print(list)
#在列表后末尾直接接上另一列表元素
list.extend(["java", "c"])
print(list)
#插入元素
list.insert(1, "c")
print(list)
#元素排序
#1.sort(key=None,reverse=False),直接修改，不产生新的
#key：指定排序规则，该参数可以是列表支持的函数，默认值为None
#reverse：指定列表元素的排序方式，该参数可以取值True或False，为True时表示降序排序，为False时表示升序排序
list.sort()
print(list)
#2. reverse()方法：用于逆置列表，该方法不会产生新的列表,会直接改变原列表
list.reverse()
print(list)
#3.sorted方法产生新的字符串，不会修改原有的，只有sorted不是类内方法
h = sorted(list)
print(h)
print(list)

#del语句：删除列表中指定索引的列表元素或删除整个列表。
list = ["a", "b", "c", "d"]#重新赋值会全部覆盖
print(list)
del list
#print(list)此时打印list会报错

#remove()方法：移除列表中匹配到的第一个元素,会直接修改列表
list = ["a", "c", "b", "c", "d"]
print(list)
list.remove("c")
print(list)

#pop方法 按索引删除列表元素，并返回被删除的元素，如果未指定索引，则删除列表中的最后一个元素
list = ["a", "c", "b", "c", "d"]
print(list.pop(0))
print(list.pop(0))
print(list)

#clear()方法：清空列表，与del区别在del会使list消失
list = ["a", "c", "b", "c", "d"]
list.clear()
print(list)