import os
import shutil #shell utility
import random

# 路径定义
base = r'D:\aaa'
bbb = os.path.join(base, 'bbb')
ccc = os.path.join(bbb, 'ccc')
f_zzz = os.path.join(bbb, 'zzz.txt')
f_yyy = os.path.join(base, 'yyy.txt')
# 1. 创建多级目录 aaa/bbb/ccc
os.makedirs(ccc, exist_ok=True)
print("创建目录: D:\\aaa\\bbb\\ccc")
# 2. 删除 ccc 目录
shutil.rmtree(ccc) #递归remove
print("删除目录: D:\\aaa\\bbb\\ccc")
# 3. 在 bbb 中创建 zzz.txt
with open(f_zzz, 'w') as f:
    pass
print("创建文件: D:\\aaa\\bbb\\zzz.txt")
# 4. 写入 "hello world"
with open(f_zzz, 'w', encoding='utf-8') as fp:
    fp.write("hello world\n")
print("写入文本: hello world")
# 5. 写入 20 个随机整数
nums = [random.randint(1, 100) for _ in range(20)]
with open(f_zzz, 'a', encoding='utf-8') as fp:
    fp.write(' '.join(map(str, nums)) + '\n')
print(f"写入随机数: {' '.join(map(str, nums))}")
# 6. 读取并排序后追加写入
with open(f_zzz, 'r', encoding='utf-8') as fp:
    lines = fp.readlines()
data = list(map(int, lines[1].split()))
data.sort()
with open(f_zzz, 'a', encoding='utf-8') as fp:
    fp.write('sorted: ' + ' '.join(map(str, data)) + '\n')
print(f"排序后追加: sorted: {' '.join(map(str, data))}")
# 7. 求和后追加写入
s = sum(data)
with open(f_zzz, 'a', encoding='utf-8') as fp:
    fp.write(f'sum: {s}\n')
print(f"追加求和: sum: {s}")
# 8. 复制到 aaa/yyy.txt
shutil.copy(f_zzz, f_yyy)
print("复制文件: zzz.txt → yyy.txt")
# 9. 美化打印目录结构（树形）
print("\n当前目录结构 (D:\\aaa):")
print("┌" + "─" * 40)
def show_tree(p, prefix=""):
    try:
        items = sorted(os.listdir(p))
        for i, name in enumerate(items):
            path = os.path.join(p, name)
            is_last = (i == len(items) - 1)
            branch = "└── " if is_last else "├── "
            if os.path.isdir(path):
                print(f"{prefix}{branch}[{name}]")
                ext = "    " if is_last else "│   "
                show_tree(path, prefix + ext)
            else:
                size = os.path.getsize(path)
                print(f"{prefix}{branch}{name}  ({size} B)")
    except PermissionError:
        print(f"{prefix}├── [拒绝访问]")
show_tree(base)
# 10. 删除整个 aaa 目录
shutil.rmtree(base)
print("\n 最终清理: 已删除 D:\\aaa 及其所有内容")
