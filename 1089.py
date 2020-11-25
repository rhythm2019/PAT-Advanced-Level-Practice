# 1089 Insert or Merge (25分)
def InsertSort(lst01, lst02):
    flag = 0
    for i in range(1, len(lst01)):
        for j in range(i, 0, -1):
            if lst01[j] < lst01[j - 1]:
                lst01[j], lst01[j - 1] = lst01[j - 1], lst01[j]
            else:
                break
        if flag == 1:
            break
        if lst01 == lst02:
            flag = 1
            continue
    return flag


def MergeSort(lst01, lst02):
    N = len(lst01)
    tmp_lst = [None] * N
    flag = 0
    # sort
    space = 1
    while space < N:
        for j in range(0, N, 2 * space):
            begin = j
            left = j
            left_end = j + space
            right = j + space
            right_end = min(j + 2 * space, N)
            while left < left_end and right < right_end:
                if lst01[left] <= lst01[right]:
                    tmp_lst[begin] = lst01[left]
                    left += 1
                    begin += 1
                else:
                    tmp_lst[begin] = lst01[right]
                    right += 1
                    begin += 1
            if left < left_end:
                tmp_lst[begin:right_end] = lst01[left:left_end]
            if right < right_end:
                tmp_lst[begin:right_end] = lst01[right:right_end]
            lst01[j:right_end] = tmp_lst[j:right_end]
        space *= 2
        if flag == 1:
            break
        if lst01 == lst02:
            flag = 1
            continue
    return flag


N = int(input())
lst01 = list(map(int, input().split()))
lst02 = list(map(int, input().split()))
lst03 = lst01.copy()

flag1 = InsertSort(lst01, lst02)
flag2 = MergeSort(lst03, lst02)
if flag1 != 0:
    print("Insertion Sort")
    print(*lst01)
elif flag2 != 0:
    print("Merge Sort")
    print(*lst03)
