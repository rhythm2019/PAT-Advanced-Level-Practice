# 1069
num = input()
if num == num[-1] * 4:
    print("{} - {} = 0000".format(num, num))
else:
    num = int(num)
    # while num != 6174:
    while True:
        num = list('{:04d}'.format(num))
        n1 = int(''.join(sorted(num, reverse=True)))
        n2 = int(''.join(sorted(num)))
        num = n1 - n2
        print("{:04d} - {:04d} = {:04d}".format(n1, n2, num))
        if num == 6174:
            break