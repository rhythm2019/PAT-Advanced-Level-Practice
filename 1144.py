#1144
N = int(input())
set01 = set(map(int, input().split()))
i = 1
while True:
    if i not in set01:
        print(i)
        break
    else:
        i += 1
