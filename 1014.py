# 1014 Waiting in Line (30分)
def get_time(min: int):
    h1 = min // 60 + 8
    min1 = min % 60
    return ("{0:02d}:{1:02d}".format(h1, min1))


N, M, K, Q = map(int, input().split())
custom = list(map(int, input().split()))
Qcustom = list(map(int, input().split()))
lst01 = []
for _ in range(N):
    lst01.append([])
result = [None] * Q
endTime = 60 * 9

if M == 0:
    M == 1
for i in range(min(N * M, K)):
    index = i % N
    if lst01[index]:
        lst01[index].append(custom[i] + lst01[index][-1])
    else:
        lst01[index].append(custom[i])

    #写入结果文件
    if i + 1 in Qcustom and lst01[index][-1] < endTime + custom[i]:
        loc = Qcustom.index(i + 1)
        result[loc] = lst01[index][-1]

for i in range(N * M, K):
    # 最小值
    min_value = float('inf')
    for index in range(N):
        if lst01[index] and lst01[index][0] < min_value:
            min_index = index
            min_value = lst01[index][0]

    # 满足最后时间要求
    if min_value < endTime:
        lst01[min_index].append(custom[i] + lst01[min_index][-1])
        del (lst01[min_index][0])
        #写入结果文件
        if i + 1 in Qcustom:
            if lst01[min_index][-1] < endTime + custom[i]:
                loc = Qcustom.index(i + 1)
                result[loc] = lst01[min_index][-1]
        i += 1
    else:
        break
for ele in result:
    if ele != None:
        print(get_time(ele))
    else:
        print('Sorry')