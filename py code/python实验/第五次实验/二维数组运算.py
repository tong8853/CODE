import numpy as np

def main():
    print("NumPy二维数组运算演示")
    
    #1创建两个二维数组
    X = np.array([[1, 2, 3],
                     [2, 4, 5],
                     [3, 5, 6]])
    
    Y = np.array([[9, 8, 7],
                     [6, 5, 4],
                     [3, 2, 1]])
    
    print("\n【1.创建的二维数组】")
    print("数组X:")
    print(X)
    print("\n数组Y:")
    print(Y)
    
    #2矢量化运算 - 相加
    print("\n【2.矢量化运算 - 相加】")
    res_add = X + Y
    print("X + Y =")
    print(res_add)
    
    #3矢量化运算 - 相乘（逐元素相乘）
    print("\n【3.矢量化运算 - 逐元素相乘】")
    res_mul = X * Y
    print("X * Y =")
    print(res_mul)
    
    #4矩阵乘法
    print("\n【4.矩阵乘法】")
    res_matmul = np.dot(X, Y)
    print("X @ Y =")
    print(res_matmul)
    
    #5线性代数运算: inv(X.T X)X.T Y
    print("\n【5.线性代数运算:inv(X.T X)X.T Y】")
    result = np.dot(np.dot(np.linalg.inv(np.dot(X.T, X)), X.T), Y)
    print("结果:")
    print(result)
    
    #6验证结果（使用最小二乘法）
    print("\n【6.验证结果（使用最小二乘法）】")
    result_lstsq = np.linalg.lstsq(X, Y, rcond=None)[0]
    print("使用 np.linalg.lstsq 的结果:")
    print(result_lstsq)

if __name__ == "__main__":
    main()
