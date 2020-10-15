#1071
str1 = input()
N = len(str1)
dict01 = dict()
vmax = 0
i = 0
while i < N:
    str2 = []
    while i < N and ('a' <= str1[i].lower() <= 'z' or '0' <= str1[i] <= '9'):
        str2.append(str1[i].lower())
        i += 1
    str2 = ''.join(str2)
    if str2:
        if str2 not in dict01:
            dict01[str2] = 1
        else:
            dict01[str2] += 1
        if dict01[str2] > vmax or (dict01[str2] == vmax and str2 < vch):
            vmax = dict01[str2]
            vch = str2
    i += 1
print('{} {}'.format(vch, vmax))
