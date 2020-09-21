str1 = input()
length = len(str1)
for N1 in range((length + 2) // 3, 1, -1):
    N2 = length + 2 - 2 * N1
    if N2 >= N1 and N2 >= 3:
        break
for i in range(N1 - 1):
    print(str1[i] + ' ' * (N2 - 2) + str1[-i - 1])
print(str1[N1 - 1:N1 + N2 - 1])
