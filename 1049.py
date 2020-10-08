# 1049
def get_one(lst01: list):
    N = len(lst01)
    if N > 1:
        num = 0
        for i in range(1, N):
            num += lst01[-i] * 10**(i - 1)

        if lst01[0] > 1:
            return 10**(N - 1) + lst01[0] * (10**(N - 2)) * (N - 1) + get_one(
                lst01[1:])
        elif lst01[0] == 1:
            return (N - 1) * 10**(N - 2) + num + 1 + get_one(lst01[1:])
        else:
            return get_one(lst01[1:])
    else:
        if lst01[0] == 0:
            return 0
        else:
            return 1


str1 = list(map(int, list(input())))
num = get_one(str1)
print(num)