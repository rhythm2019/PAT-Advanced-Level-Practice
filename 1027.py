#1027
dict01_lst = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C']


def get_13(number: int):
    global dict01_lst
    result = ''
    while number // 13:
        result = dict01_lst[number % 13] + result
        number = number // 13
    result = dict01_lst[number % 13] + result
    return '{:0>2}'.format(result)


str01 = '#'
for ch in input().split():
    str01 = str01 + get_13(int(ch))
print(str01)