# 1010 Radix (25分)
def get_num(str1: str, radix: int):
    num = 0
    i = 0
    for ch in str1[::-1]:
        num += dict01[ch] * (radix**i)
        i += 1
    return num


lst01 = list('0123456789abcdefghijklmnopqrstuvwxyz')
dict01 = {ele: lst01.index(ele) for ele in lst01}
N1, N2, tag, radix = input().split()
radix = int(radix)
if tag == '2':
    N1, N2 = N2, N1
i = 0
num1 = 0
for ch in N1[::-1]:
    num1 += dict01[ch] * radix**i
    i += 1
ch = max(list(N2))
i_left = max(dict01[ch] + 1, 2)
i_right = 10**10
left = get_num(N2, i_left)
right = get_num(N2, i_right)
if left == num1:
    print(i_left)
elif right == num1:
    print(i_right)
elif left > num1 or num1 > right:
    print("Impossible")
else:
    i_left += 1
    i_right -= 1
    while i_left <= i_right:
        i_median = (i_left + i_right) // 2
        median = get_num(N2, i_median)
        if median == num1:
            print(i_median)
            break
        elif median > num1:
            i_right = i_median - 1
        else:
            i_left = i_median + 1
    else:
        print("Impossible")
