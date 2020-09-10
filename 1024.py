N1, step = map(int, input().split())
str1 = str(N1)
str2 = str1[::-1]
i = 0
while str1 != str2 and i < step:
    str1 = str(int(str1) + int(str2))
    str2 = str1[::-1]
    i += 1
    #print(str1,str2,i)
print(str1)
print(i)