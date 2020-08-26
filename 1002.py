# 1002
lst01 = []
lst02 = []
tmp1 = input().split()
tmp2 = input().split()
for i in range(1, 2 * int(tmp1[0]) + 1, 2):
    lst01.extend([int(tmp1[i]), float(tmp1[i + 1])])
for i in range(1, 2 * int(tmp2[0]) + 1, 2):
    lst02.extend([int(tmp2[i]), float(tmp2[i + 1])])

i = -2
j = -2
lst03 = []
while i >= -len(lst01) and j >= -len(lst02):
    if lst01[i] > lst02[j]:
        lst03.extend([lst02[j], lst02[j + 1]])
        j = j - 2
    elif lst01[i] < lst02[j]:
        lst03.extend([lst01[i], lst01[i + 1]])
        i = i - 2
    else:
        if lst01[i + 1] + lst02[j + 1] != 0.0:
            lst03.extend([lst01[i], lst01[i + 1] + lst02[j + 1]])
        i = i - 2
        j = j - 2

if i >= -len(lst01):
    while i >= -len(lst01):
        lst03.extend([lst01[i], lst01[i + 1]])
        i = i - 2
elif j >= -len(lst02):
    while j >= -len(lst02):
        lst03.extend([lst02[j], lst02[j + 1]])
        j = j - 2

if lst03:
    print(len(lst03) // 2, end=' ')
    for i in range(-2, -len(lst03) + 1, -2):
        print('{} {:.1f}'.format(lst03[i], lst03[i + 1]), end=' ')
    print('{} {:.1f}'.format(lst03[0], lst03[1]))
else:
    print('0')