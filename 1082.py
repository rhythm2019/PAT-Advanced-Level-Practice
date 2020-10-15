# 1082 Read Number in Chinese
def get_china(num: list):
    global dict01, lst01
    length = len(num)
    zero_flag = True
    str01 = ''
    i = 1
    while i <= length:
        if num[-i] == '0' and not zero_flag:
            if i in (2, 3, 4) and num[-i + 1] != '0':
                str01 = 'ling' + ' ' + str01
                str01 = str01.strip()
        elif num[-i] != '0':
            str01 = dict01[num[-i]] + ' ' + lst01[-i] + ' ' + str01
            str01 = str01.strip()
            zero_flag = False
        i += 1
    return str01


num = list(input())
dict01 = {
    '-': 'Fu',
    '0': 'ling',
    '1': 'yi',
    '2': 'er',
    '3': 'san',
    '4': 'si',
    '5': 'wu',
    '6': 'liu',
    '7': 'qi',
    '8': 'ba',
    '9': 'jiu'
}
# lst01 = ['Yi', 'Qian', 'Bai', 'Shi', 'Wan', 'Qian', 'Bai', 'Shi', '']
lst01 = ['Qian', 'Bai', 'Shi', '']

if len(num) == 1:
    print(dict01[num[0]])
else:
    if num[0] == '-':
        num = num[1:]
        singal = 'Fu '
    else:
        singal = ''
    str01 = get_china(num[-4:])
    str02 = get_china(num[-8:-4])
    str03 = get_china(num[:-8])
    if str02:
        str01 = str02 + ' Wan ' + str01
    if str03:
        str01 = str03 + ' Yi ' + str01
    print(singal + str01)