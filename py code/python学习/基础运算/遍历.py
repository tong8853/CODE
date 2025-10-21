for i in "hello":
    print(i, end = "")
print()
for i in range(1, 11):
    if i % 2 == 0:
        print(i, "是偶数")
    else:
        print(i, "是奇数")
sum = 0
for i in range(1, 11):
    sum += i
print(sum)
