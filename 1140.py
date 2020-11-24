#1140
N, M = input().split()
str1 = N
for _ in range(int(M) - 1):
    i = 0
    j = 0
    str2 = ''
    while i < len(str1):
        while (j < len(str1) and str1[i] == str1[j]):
            j += 1
        str2 += str1[i] + str(j - i)
        i = j
    str1 = str2
print(str1)