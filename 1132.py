#1132 Cut Integer (20分)
#DATE:20200821
N = int(input())
lst01 = []
for i in range(N):
    N1 = input()
    LL = len(N1) // 2
    N2 = int(N1[0:LL]) * int(N1[LL:])
    if (N2 > 0 and int(N1) % N2 == 0):
        lst01.append("Yes")
    else:
        lst01.append("No")
for i in range(N):
    print(lst01[i])