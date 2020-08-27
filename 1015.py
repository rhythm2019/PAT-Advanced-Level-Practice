#1015
def isPrime(num1: int):
    if num1 <= 1:
        return False
    elif num1 == 2:
        return True

    N = int(num1**0.5) + 2
    for i in range(2, N):
        if num1 % i == 0:
            return False
    else:
        return True


def getDbase(num1: int, D: int) -> str:
    str1 = ''
    while num1 // D:
        str1 = str(num1 % D) + str1
        num1 = num1 // D
    str1 = str(num1 % D) + str1
    return str1


lst01 = []
while True:
    str1 = input().split()
    if int(str1[0]) < 0:
        break
    else:
        lst01.append(str1)

for x in lst01:
    num1 = getDbase(int(x[0]), int(x[1]))
    num1 = num1[::-1]
    num1 = int(num1, int(x[1]))
    if isPrime(int(x[0])) and isPrime(num1):
        print('Yes')
    else:
        print('No')