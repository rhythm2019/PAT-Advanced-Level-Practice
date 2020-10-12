# 1058
def trans(num: int):
    n1 = num % 29
    n3 = num // 29
    n2 = n3 % 17
    n3 = n3 // 17
    return '{}.{}.{}'.format(n3, n2, n1)


str1 = input().split()
A = str1[0].split('.')
B = str1[1].split('.')
a = int(A[0]) * 17 * 29 + int(A[1]) * 29 + int(
    A[2]) + int(B[0]) * 17 * 29 + int(B[1]) * 29 + int(B[2])
print(trans(a))