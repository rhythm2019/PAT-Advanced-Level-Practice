# 1056
def get_win(rank: list, score: int):
    global lst01
    global win_lst
    if len(rank) == 0:
        return
    elif len(rank) == 1:
        lst01[rank[0]] = score
        win_lst.append(rank[0])
    else:
        v_max = -1
        v_index = -1
        for i in range(len(rank)):
            if lst01[rank[i]] > v_max:
                if v_index != -1:
                    lst01[v_index] = score
                v_index = rank[i]
                v_max = lst01[rank[i]]
            else:
                lst01[rank[i]] = score
        win_lst.append(v_index)


N, M = input().split()
N, M = int(N), int(M)
lst01 = list(map(int, input().split()))
lst02 = list(map(int, input().split()))

while len(lst02) > 1:
    win_lst = []
    n = len(lst02) // M
    if len(lst02) % M:
        score_grade = n + 2
    else:
        score_grade = n + 1

    for i in range(n):
        get_win(lst02[i * M:(i + 1) * M], score_grade)
    if len(lst02) % M > 0:
        if n:
            get_win(lst02[(i + 1) * M:], score_grade)
        else:
            get_win(lst02, score_grade)
    lst02 = win_lst[:]
    # print(*lst02)

lst01[lst02[0]] = 1
print(*lst01)  #1108 Finding Average (20分)
#DATE:20200818
list01 = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
set01 = set(list01)


def isLegal(num):
    k = num.find('.')
    str02 = num[:]
    ###########################################
    if k != -1:
        str02 = num[:k]
        str03 = num[k + 1:]
        if len(str03) > 2:
            return False
        for ch in str03:
            if ch not in set01:
                return False
    ###########################################
    if str02 == "-" or (str02[0] == '0' and len(str02) > 1):
        return False
    if str02[0] == "-":
        str02 = str02[1:]
    for i in range(len(str02)):
        if str02[i] not in set01:
            return False
    if float(num) > 1000 or float(num) < -1000:
        return False
    else:
        return True


N = int(input())
str01 = input().split()
count = 0
sum = 0
for ele in str01:
    if (isLegal(ele) == False):
        print("ERROR: {} is not a legal number".format(ele))
    else:
        count += 1
        sum += float(ele)
if (count > 1):
    print("The average of {} numbers is {:.2f}".format(count, sum / count))
elif (count == 1):
    print("The average of 1 number is {:.2f}".format(sum))
else:
    print("The average of 0 numbers is Undefined")