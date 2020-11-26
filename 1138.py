# 1138 Postorder Traversal (25分)
N = int(input())
lst01 = input().split()
lst02 = input().split()
set01 = {lst02[i]: i for i in range(N)}
begin_1 = 0
end_1 = N - 1
begin_2 = 0
end_2 = N - 1
while N > 2:
    i = set01[lst01[begin_1]]
    #仅有右树
    if i == begin_2:
        begin_1 += 1
        begin_2 += 1
        N = N - 1
    #有左树
    else:
        end_1 = begin_1 + i - begin_2
        begin_1 = begin_1 + 1
        end_2 = i - 1
        N = end_1 - begin_1 + 1
print(lst01[end_1])