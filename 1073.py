# 1073
# +1.23400E-03
str01 = input().split('E')
exponent = int(str01[-1])
sign = '' if str01[0].split('.')[0][0] == '+' else '-'
integer = str01[0].split('.')[0][1:]
fraction = str01[0].split('.')[-1]
dotflag = True
if exponent > 0:
    if len(fraction) > exponent:
        integer += fraction[0:exponent]
        fraction = fraction[exponent:]
    elif len(fraction) == exponent:
        integer += fraction
        fraction = ''
        dotflag = False
    else:
        integer += fraction + '0' * (exponent - len(fraction))
        fraction = ''
        dotflag = False
elif exponent < 0:
    fraction = '0' * (-exponent - 1) + integer + fraction
    integer = '0'

if dotflag:
    print('{}{}.{}'.format(sign, integer, fraction))
else:
    print('{}{}'.format(sign, integer))
