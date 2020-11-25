#1112 Stucked Keyboard (20分)
#DATE:202008
k = int(input())
str01 = input()
list01 = list(str01)
set01 = set(str01)
i = 0
while (i < len(list01)):
    if list01[i] not in set01:
        i += 1
        continue
    j = 1
    while (i + j < len(list01) and list01[i + j] == list01[i]):
        j += 1
    if (j % k != 0):
        set01.remove(list01[i])
    i += j

ch = ''
set01 = list(set01)
set01.sort(key=str01.find)
for ele in set01:
    ch = ch + ele
print(ch)
for ele in set01:
    ch = k * ele
    str01 = str01.replace(ch, ele)
print(str01)