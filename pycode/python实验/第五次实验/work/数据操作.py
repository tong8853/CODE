import numpy as np

def main():
    print("NumPy数组操作演示")
    
    #创建两个一维数组
    arr1 = np.array([10, 25, 30, 45, 50, 65, 70, 85, 90, 100])
    arr2 = np.array([5, 15, 20, 35, 40, 55, 60, 75, 80, 95])
    
    print("\n【1.创建的数组】")
    print(f"数组1: {arr1}")
    print(f"数组2: {arr2}")
    
    #2切片操作
    print("\n【2.切片操作】")
    print(f"arr1[2:5]: {arr1[2:5]}")  # 取索引2到4的元素
    print(f"arr1[:4]: {arr1[:4]}")    # 取前4个元素
    print(f"arr1[5:]: {arr1[5:]}")    # 取索引5之后的所有元素
    print(f"arr1[::2]: {arr1[::2]}")  # 每隔一个取一个
    print(f"arr2[-3:]: {arr2[-3:]}")  # 取最后3个元素
    
    #花式索引（条件筛选）
    print("\n【3.花式索引（条件筛选）】")
    mask1 = arr1 > 50
    print(f"arr1 > 50 的元素: {arr1[mask1]}")
    
    mask2 = (arr2 >= 20) & (arr2 <= 60)
    print(f"arr2 在 [20, 60] 范围内的元素: {arr2[mask2]}")
    
    #4指定索引取值
    idx = [0, 2, 4, 6]
    print(f"arr1 索引 {idx} 的元素: {arr1[idx]}")
    
    #通用函数运算
    print("\n【4.通用函数运算】")
    print(f"arr1 + arr2 = {arr1 + arr2}")
    print(f"arr1 * 2 = {arr1 * 2}")
    print(f"arr2 的平方 = {np.square(arr2)}")
    print(f"arr1 的平方根 = {np.sqrt(arr1)}")
    print(f"arr1 和 arr2 的最大值 = {np.maximum(arr1, arr2)}")
    
    #数组排序
    print("\n【5.数组排序】")
    arr3 = np.array([45, 12, 78, 23, 56, 89, 34, 67])
    print(f"原数组: {arr3}")
    print(f"升序排序: {np.sort(arr3)}")
    print(f"降序排序: {np.sort(arr3)[::-1]}")
    
    #返回排序后的索引
    sort_idx = np.argsort(arr3)
    print(f"排序索引: {sort_idx}")
    print(f"按索引排序: {arr3[sort_idx]}")
    
    #统计运算
    print("\n【6.统计运算】")
    print(f"arr1 的和: {np.sum(arr1)}")
    print(f"arr1 的均值: {np.mean(arr1)}")
    print(f"arr1 的中位数: {np.median(arr1)}")
    print(f"arr1 的标准差: {np.std(arr1)}")
    print(f"arr1 的方差: {np.var(arr1)}")
    print(f"arr1 的最大值: {np.max(arr1)}")
    print(f"arr1 的最小值: {np.min(arr1)}")
    print(f"arr1 最大值索引: {np.argmax(arr1)}")
    print(f"arr1 最小值索引: {np.argmin(arr1)}")
    
    print("\n" + "=" * 50)

if __name__ == "__main__":
    main()
