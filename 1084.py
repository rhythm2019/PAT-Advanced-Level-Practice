# 1084
str1 = input().upper()
str2 = input().upper()
i = 0
j = 0
lst01 = []
while j < len(str2):
    if str1[i] == str2[j]:
        i += 1
        j += 1
    else:
        if str1[i] not in lst01:
            lst01.append(str1[i])
        i += 1
else:
    while i < len(str1):
        if str1[i] not in lst01:
            lst01.append(str1[i])
        i += 1
print(''.join(lst01))