#1009
#This time, you are supposed to find A×B where A and B are two polynomials.
list01 = input().split()
list02 = input().split()
dict01 = dict()
dict02 = dict()
dict03 = dict()
for i in range(1, len(list01), 2):
    dict01[int(list01[i])] = float(list01[i + 1])
for i in range(1, len(list02), 2):
    dict02[int(list02[i])] = float(list02[i + 1])
for exp1, coe1 in dict01.items():
    for exp2, coe2 in dict02.items():
        if dict03.get(exp1 + exp2):
            dict03[exp1 + exp2] += coe1 * coe2
        else:
            dict03[exp1 + exp2] = coe1 * coe2
list01 = list(dict03.items())
list01.sort(reverse=True)
list02 = []
for ele in list01:
    if '{:.1f}'.format(ele[1]) != '0.0':
        list02.append(ele[0])
        list02.append('{:.1f}'.format(ele[1]))
list02.insert(0, len(list02) // 2)
print(*list02)