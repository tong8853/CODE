import random

def main():
    #0-1标准正态分布
    u = 0
    sigma = 1
    n = 1000

    #生成随机数，存到nums列表里面
    nums = [random.normalvariate(u, sigma) for _ in range(n)]

    #计数
    cnt1 = 0
    cnt2 = 0
    cnt3 = 0

    #定义区间
    low1, high1 = u - sigma, u + sigma
    low2, high2 = u - 2 * sigma, u + 2 * sigma
    low3, high3 = u - 3 * sigma, u + 3 * sigma

    #计数
    for x in nums:
        if low1 <= x <= high1:
            cnt1 += 1
        if low2 <= x <= high2:
            cnt2 += 1
        if low3 <= x <= high3:
            cnt3 += 1

    #输出结果
    print(f"Total: {n}")
    print(f"[{u-sigma}, {u+sigma}]: {cnt1} ({cnt1/n:.2%})")
    print(f"[{u-2*sigma}, {u+2*sigma}]: {cnt2} ({cnt2/n:.2%})")
    print(f"[{u-3*sigma}, {u+3*sigma}]: {cnt3} ({cnt3/n:.2%})")

if __name__ == "__main__":
    main()
