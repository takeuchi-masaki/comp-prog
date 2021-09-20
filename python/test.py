from math import trunc
N = int(input())
# N = 1001
tax = 1.08
maxN = 50000
found = False
ans = 0
for x in range(1, maxN):
    res = trunc(x * tax)
    if res == N: 
        found = True
        ans = x
        break
if found:
    print(ans)
else:
    print(":(")