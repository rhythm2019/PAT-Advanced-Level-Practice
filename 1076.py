# 1076 Forwards on Weibo (30分)
N, layer = map(int, input().split())
dict01 = dict()
for i in range(N):
    lst01 = input().split()[1:]
    for ele in lst01:
        if ele in dict01:
            dict01[ele].append(str(i + 1))
        else:
            dict01[ele] = [str(i + 1)]
lst01 = input().split()[1:]
for ele in lst01:
    visit = [0] * N
    visit[int(ele) - 1] = 1
    queue = [(ele, 0)]
    while queue:
        cur_node = queue.pop(0)
        if cur_node[1] > layer - 1:
            break
        else:
            for x in dict01[cur_node[0]]:
                if visit[int(x) - 1] == 0:
                    queue.append((x, cur_node[1] + 1))
                    visit[int(x) - 1] = 1
    count = 0
    for ele in visit:
        if ele:
            count += 1
    print(count - 1)