# 1017
endTime = [8 * 3600, 8 * 3600, 8 * 3600]
startTime = []
waitTime = []
N, K = map(int, input().split())
for _ in range(N):
    ele = input().split()
    if ele[0] <= '17:00:00':
        startTime.append(
            (int(ele[0][0:2]) * 3600 + int(ele[0][3:5]) * 60 + int(ele[0][6:]),
             int(ele[1]) * 60))
startTime.sort()

while endTime:
    # 通道正忙
    if len(endTime) == K:
        t1 = endTime.pop(0)
        if startTime and t1 > startTime[0][0]:
            t2 = startTime.pop(0)
            endTime.append(t1 + t2[1])
            endTime.sort()
            waitTime.append(t1 - t2[0])

    # 通道有空闲
    else:
        if startTime:
            t2 = startTime.pop(0)
            endTime.append(t2[0] + t2[1])
            endTime.sort()
            waitTime.append(0)
        else:
            del endTime[0]
print('%.1f' % (sum(waitTime) / len(waitTime) / 60))