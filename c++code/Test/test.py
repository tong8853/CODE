from collections import Counter

def solve_by_backtracking(s):
    """使用回溯法（DFS）解决相邻字符不相等的排列计数问题。"""
    
    # 1. 预处理：统计字符频率
    counts = Counter(s)
    n = len(s)
    
    # 初始化结果计数器
    good_strings_count = 0

    def dfs(current_length, last_char):
        nonlocal good_strings_count
        
        # 递归终止条件：已构建完整的字符串
        if current_length == n:
            good_strings_count += 1
            return

        # 遍历所有可能的下一个字符
        # counts.keys() 保持不变，但 counts[char] 会在递归中变化
        for char in list(counts.keys()): 
            
            # 2. 约束检查 (剪枝)
            # 1) 剩余字符数量必须大于 0
            # 2) 当前字符不能等于上一个字符 (相邻不相等)
            if counts[char] > 0 and char != last_char:
                
                # 3. 选择
                counts[char] -= 1
                
                # 4. 递归
                dfs(current_length + 1, char)
                
                # 5. 撤销选择 (回溯)
                counts[char] += 1

    # 从空串开始构建，last_char 设为 None 或一个不可能是字符的值
    dfs(0, None)
    
    return good_strings_count

# 示例测试
# s_test = "abacaba" # 长度7
# s_test = "aabc"   # 长度4, 结果: 6
# s_test = "topcoder" # 长度8, 结果: 40320 (8!)
# s_test = "aabbaa" # 长度6, 结果: 0 (a的个数大于其他字符总和+2，肯定不行，但这里结果是0)

# s_test = "arcaca" # 3a, 2c, 1r
# print(f"字符串 '{s_test}' 的好串数量 (回溯法):", solve_by_backtracking(s_test))