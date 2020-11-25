#1100
#对应0~12
lst01 = [
    'tret', 'jan', 'feb', 'mar', 'apr', 'may', 'jun', 'jly', 'aug', 'sep',
    'oct', 'nov', 'dec'
]
#对应进位后的0~12
lst02 = [
    None, 'tam', 'hel', 'maa', 'huh', 'tou', 'kes', 'hei', 'elo', 'syy', 'lok',
    'mer', 'jou'
]

N = int(input())
data = []
for _ in range(N):
    data.append(input().split())
for x in data:
    #地球十进制
    if len(x) == 1 and x[0].isdecimal() == True:
        num = int(x[0])
        ret = []
        while True:
            ret.insert(0, num % 13)
            num = num // 13
            if num == 0:
                break
        if len(ret) == 2 and ret[1] == 0:
            print(lst02[ret[0]])
        elif len(ret) == 2 and ret[1] != 0:
            print(lst02[ret[0]], lst01[ret[1]])
        elif len(ret) == 1:
            print(lst01[ret[0]])
    #火星文
    else:
        if len(x) == 1:
            if x[0] in lst01:
                print(lst01.index(x[0]))
            elif x[0] in lst02:
                print(13 * lst02.index(x[0]))
        elif len(x) == 2:
            print(13 * lst02.index(x[0]) + lst01.index(x[1]))
