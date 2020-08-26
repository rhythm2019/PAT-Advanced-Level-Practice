# 1003
# 1003 Emergency (25分)
'''
lst01:已经确认过的节点及其最短距离
lst02:剩余节点及其距离，[[节点编号],[节点距离]]
node_graph:有向带权图，graph[i]=[[节点号],[节点距离]]
path:前节点
'''


def DFS(node: int, path: list):
    global v1
    cur_node = path[node]
    if cur_node != None:
        lst01 = []
        for ele in cur_node:
            lst01.append(DFS(ele, path))
        return node_rescue[node] + max(lst01)
    else:
        v1 += 1
        return node_rescue[node]


N, M, start, end = map(int, input().split())
node_rescue = list(map(int, input().split()))
node_graph = dict()
for _ in range(M):
    city1, city2, distance = map(int, input().split())
    if city1 in node_graph:
        node_graph[city1][0].append(city2)
        node_graph[city1][1].append(distance)
    else:
        node_graph[city1] = [[city2], [distance]]

    if city2 in node_graph:
        node_graph[city2][0].append(city1)
        node_graph[city2][1].append(distance)
    else:
        node_graph[city2] = [[city1], [distance]]

lst01 = [[start], [0]]
lst02 = [[], []]
path = [None] * N
cur_node = start
# Dijkstra
while cur_node != end:
    for i in range(len(node_graph[cur_node][0])):
        next_node = node_graph[cur_node][0][i]
        next_distance = node_graph[cur_node][1][i]

        #邻接节点没有distance
        if (next_node not in lst01[0]) and (next_node not in lst02[0]):
            lst02[0].append(next_node)
            lst02[1].append(lst01[1][-1] + next_distance)
            path[next_node] = [cur_node]

        #邻接节点已经有distance
        elif next_node in lst02[0]:
            if lst01[1][-1] + next_distance < lst02[1][lst02[0].index(
                    next_node)]:
                lst02[1][lst02[0].index(
                    next_node)] = lst01[1][-1] + next_distance
                path[next_node] = [cur_node]
            elif lst01[1][-1] + next_distance == lst02[1][lst02[0].index(
                    next_node)]:
                # 相等情况
                lst02[1][lst02[0].index(
                    next_node)] = lst01[1][-1] + next_distance
                path[next_node].append(cur_node)

    #寻找distance最小值
    min_distance = float('inf')
    for i in range(len(lst02[0])):
        if lst02[1][i] < min_distance:
            min_distance = lst02[1][i]
            min_index = i

    cur_node = lst02[0][min_index]
    lst01[0].append(cur_node)
    lst01[1].append(min_distance)
    for ele in lst02:
        del (ele[min_index])

v1 = 0
v2 = DFS(end, path)
print(v1, v2)
