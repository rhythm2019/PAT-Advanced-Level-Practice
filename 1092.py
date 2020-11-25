#1092
str1 = input()
str2 = input()
dict01 = dict()
dict02 = dict()
for ch in str1:
    if ch in dict01:
        dict01[ch] += 1
    else:
        dict01[ch] = 1
for ch in str2:
    if ch in dict02:
        dict02[ch] += 1
    else:
        dict02[ch] = 1

#1-2 more or less
more = 0
less = 0
for ch in dict02.keys():
    if ch not in dict01:
        dict01[ch] = -dict02[ch]
    else:
        dict01[ch] -= dict02[ch]
for value in dict01.values():
    if value >= 0:
        more += value
    else:
        less += value
if more >= 0 and less == 0:
    print('Yes', more)
elif less < 0:
    print('No', -less)
