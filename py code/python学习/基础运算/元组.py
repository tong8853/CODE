a = input(["输入列表1"])
for x in list(a)[0 : len(a)]:
    print(x, end = " ")

a[2] = 3
len1 = len(a)
print(len1)
for x in a[0 : len1]:
    print(x, end = " ")
