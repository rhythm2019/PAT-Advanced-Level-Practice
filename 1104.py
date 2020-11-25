# 1104 Sum of Number Segments (20分)
N = int(input())
lst01 = list(map(float, input().split()))
zh = 0
for i in range(N):
    zh += (N - i) * (i + 1) * lst01[i]
print('{0:.2f}'.format(zh))