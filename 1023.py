N1 = int(input())
N2 = N1 * 2
a = list(str(N1))
a.sort()
b = list(str(N2))
b.sort()

if a == b:
    print('Yes')
    print(N2)
else:
    print('No')
    print(N2)