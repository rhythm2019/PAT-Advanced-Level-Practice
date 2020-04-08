# 1083 List Grades (25分)
def get_N(lst01: list):
    global LOW, HIGH
    N = len(lst01)
    # search failer
    if lst01[0][-1] < LOW or lst01[-1][-1] > HIGH:
        return None, None

    if LOW <= lst01[0][-1] <= HIGH:
        N1 = 0
    else:  # index[0] > HIGH
        left = 1
        right = N - 1
        mid = (left + right) // 2
        while left <= right:
            if lst01[mid][-1] > HIGH:
                left = mid + 1
                mid = (left + right) // 2
            elif lst01[mid][-1] < HIGH:
                right = mid - 1
                mid = (left + right) // 2
            else:
                break
        N1 = mid

    if HIGH >= lst01[-1][-1] >= LOW:
        N2 = N - 1
    else:  # index[-1] < LOW
        left = 0
        right = N - 1
        mid = (left + right) // 2
        while left <= right:
            if lst01[mid][-1] < LOW:
                right = mid - 1
                mid = (left + right) // 2
            elif lst01[mid][-1] > LOW:
                left = mid + 1
                mid = (left + right) // 2
            else:
                break
        N2 = mid
    return N1, N2


N = int(input())
lst01 = []
for _ in range(N):
    name, ID, grade = input().split()
    lst01.append([name, ID, int(grade)])
LOW, HIGH = map(int, input().split())
lst01.sort(key=lambda x: x[-1], reverse=True)
if lst01[0][-1] < LOW or lst01[-1][-1] > HIGH:
    print('NONE')
else:
    N1, N2 = get_N(lst01)
    for i in range(N1, N2 + 1):
        print(*lst01[i][:-1])