# 1059 Prime Factors
def get_prime(num: int):
    result = [1] * (num + 1)
    i = 2
    while i < num + 1:
        if result[i]:
            for ele in range(i, num + 1, i):
                result[ele] = 0
            result[i] = 1
        i += 1
    return [i for i in range(2, num + 1) if result[i] == 1]


num = int(input())
str02 = '{}='.format(num)
if num == 1:
    print(str02 + '1')
else:
    prime_lst = get_prime(int(num**0.5) + 1)
    result = []
    ele = 0
    while ele <= num**0.5:
        for ele in prime_lst:
            if ele < num and num % ele == 0:
                result.append(ele)
                num = num // ele
                ele = 0
                break
        else:
            result.append(num)
            break

    dict01 = dict()
    for ele in result:
        if ele in dict01:
            dict01[ele] += 1
        else:
            dict01[ele] = 1
    lst01 = sorted(dict01.items())
    str01 = ''
    for ele in lst01:
        if ele[1] > 1:
            str01 = str01 + '*{x[0]}^{x[1]}'.format(x=ele)
        else:
            str01 = str01 + '*' + str(ele[0])
    str01 = str02 + str01[1:]
    print(str01)
