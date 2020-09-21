# 1030
# 1030 Travel Plan (30分)
'''
lst01:已经确认过的节点
lst02:剩余周边节点
node_graph:有向带权图，graph[i]=[[节点号],[节点距离],[节点COST]]
path
distance
'''
N, M, start, end = map(int, input().split())
node_graph = dict()
for _ in range(M):
    city1, city2, distance, cost = map(int, input().split())
    if city1 in node_graph:
        node_graph[city1][0].append(city2)
        node_graph[city1][1].append(distance)
        node_graph[city1][2].append(cost)
    else:
        node_graph[city1] = [[city2], [distance], [cost]]

    if city2 in node_graph:
        node_graph[city2][0].append(city1)
        node_graph[city2][1].append(distance)
        node_graph[city2][2].append(cost)
    else:
        node_graph[city2] = [[city1], [distance], [cost]]

lst01 = [start]
lst02 = []
path = [None] * N
distance = [None] * N
cost = [None] * N
cost[start] = 0
distance[start] = 0

cur_node = start
# Dijkstra
while cur_node != end:
    for i in range(len(node_graph[cur_node][0])):
        next_node = node_graph[cur_node][0][i]
        next_distance = node_graph[cur_node][1][i]
        next_cost = node_graph[cur_node][2][i]

        #邻接节点没有distance
        if distance[next_node] == None:
            lst02.append(next_node)
            distance[next_node] = distance[cur_node] + next_distance
            path[next_node] = cur_node
            cost[next_node] = cost[cur_node] + next_cost

        #邻接节点已经有distance
        elif next_node not in lst01:
            if distance[cur_node] + next_distance < distance[next_node]:
                distance[next_node] = distance[cur_node] + next_distance
                path[next_node] = cur_node
                cost[next_node] = cost[cur_node] + next_cost
            elif distance[cur_node] + next_distance == distance[next_node]:
                if cost[cur_node] + next_cost < cost[next_node]:
                    path[next_node] = cur_node
                    cost[next_node] = cost[cur_node] + next_cost

    #寻找distance最小值
    min_distance = float('inf')
    for i in range(len(lst02)):
        if distance[lst02[i]] < min_distance:
            min_distance = distance[lst02[i]]
            min_index = i
    cur_node = lst02[min_index]
    lst01.append(cur_node)
    del (lst02[min_index])

routie = []
cur_node = end
while cur_node != None:
    routie.insert(0, cur_node)
    cur_node = path[cur_node]

routie.append(distance[end])
routie.append(cost[end])
print(*routie)