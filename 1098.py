# 1098 Insertion or Heap Sort (25分)
def InsertSort(lst01, lst02):
    flag = 0
    for i in range(1, len(lst01)):
        for j in range(i, 0, -1):
            if lst01[j] < lst01[j - 1]:
                lst01[j], lst01[j - 1] = lst01[j - 1], lst01[j]
            else:
                break
        if lst01 == lst02:
            flag = 1
            continue
        if flag == 1:
            break
    return flag


def down(lst01, i, length):
    N = length
    if (2 * i + 2) < N:
        if lst01[2 * i + 2] >= max(lst01[i], lst01[2 * i + 1]):
            lst01[i], lst01[2 * i + 2] = lst01[2 * i + 2], lst01[i]
            down(lst01, 2 * i + 2, N)
        elif lst01[2 * i + 1] >= max(lst01[i], lst01[2 * i + 2]):
            lst01[i], lst01[2 * i + 1] = lst01[2 * i + 1], lst01[i]
            down(lst01, 2 * i + 1, N)
    elif (2 * i + 1) < N and lst01[2 * i + 1] > lst01[i]:
        lst01[i], lst01[2 * i + 1] = lst01[2 * i + 1], lst01[i]
        down(lst01, 2 * i + 1, N)


def HeapSort(lst01, lst02):
    # create max heap
    N = len(lst01)
    flag = 0
    for i in range(N // 2 - 1, -1, -1):
        down(lst01, i, N)

    # sort
    for i in range(N - 1, 0, -1):
        lst01[i], lst01[0] = lst01[0], lst01[i]
        down(lst01, 0, i)
        if lst01 == lst02:
            flag = 1
            continue
        if flag == 1:
            break
    return flag


N = int(input())
lst01 = list(map(int, input().split()))
lst02 = list(map(int, input().split()))
lst03 = lst01.copy()
flag1 = InsertSort(lst01, lst02)
flag2 = HeapSort(lst03, lst02)
if flag1 != 0:
    print("Insertion Sort")
    print(*lst01)
elif flag2 != 0:
    print("Heap Sort")
    print(*lst03)