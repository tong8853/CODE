num = input("请输入要转换的数字：")
base = int(input("请输入原始进制（2、8、10、16）："))

# 先将数字转换为十进制
num = int(num, base)
print(f"转换为十进制：{num}")
# 从十进制转换为其他进制
print(f"转换为二进制：{bin(num)[2:]}")
print(f"转换为八进制：{oct(num)[2:]}")
print(f"转换为十六进制：{hex(num)[2:].upper()}")