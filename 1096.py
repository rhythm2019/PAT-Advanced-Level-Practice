#1096 Consecutive Factors
'''
Among all the factors of a positive integer N, there may exist several consecutive numbers. 
For example, 630 can be factored as 3 5*6*7, where 5, 6, and 7 are the three consecutive numbers. 
Now given any positive N, you are supposed to find the maximum number of consecutive factors, 
and list the smallest sequence of the consecutive factors.
'''
N = int(input())
result = []
maxV = N**0.5 + 1
i = 2
while i < maxV:
    j = i
    N1 = N
    while N1 % j == 0:
        N1 = N1 / j
        j += 1
    if j > i:
        if not result:
            result = [i, j - i]
        elif j - i > result[1]:
            result = [i, j - i]
            maxV = N**(1 / result[1]) + 1
    i += 1
if not  result:
    print(1)
    print(N)
else:
    result = [str(ele) for ele in range(result[0], sum(result))]
    print(len(result))
    print('*'.join(result))