#1120
N = int(input())
lst01 = input().split()
set01 = set()
for num in lst01:
    count = 0
    for ch in num:
        count += int(ch)
    set01.add(count)
lst02 = sorted(set01)
print(len(lst02))
print(*lst02)