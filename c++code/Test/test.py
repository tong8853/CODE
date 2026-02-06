n,k = map(int,input().split())
s = input()
ans = [0] * (n + 1)
x = 0
lst = -1
for i in range(n):
    if s[i] == '0':
        if i - lst >= k:
            ans[x] = i
            x += 1
            lst = i
    else:
        lst = i

for i in range(x,n + 1):
    ans[i] = n
print(*ans)