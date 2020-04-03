# 1018 Public Bike Management (30?)
'''
collect[]:已经确认过的节点
node_graph:有向带权图,graph[i]=[(node,time)]
path:记录路径
Time[]:记录最短time
capacity:station的当前容量
'''


def Dijkstra(begin: int, end: int):
    global collect, path, Time, uncollect
    global node_graph

    cur_node = begin
    while cur_node != end:
        for i in range(len(node_graph[cur_node])):
            next_node = node_graph[cur_node][i][0]
            next_time = node_graph[cur_node][i][1]
            if collect[next_node] == 0:
                if Time[cur_node] + next_time < Time[next_node]:
                    Time[next_node] = Time[cur_node] + next_time
                    path[next_node] = [cur_node]
                elif Time[cur_node] + next_time == Time[next_node]:
                    if path[next_node] == None:
                        path[next_node] = [cur_node]
                    else:
                        path[next_node].append(cur_node)
                uncollect.add(next_node)
        min_time = float('inf')
        for ele in uncollect:
            if Time[ele] < min_time:
                min_time = Time[ele]
                cur_node = ele
        uncollect.remove(cur_node)
        collect[cur_node] = 1


def get_sendAndback(begin: int, path: list):
    global capacity, Cmax
    send = 0
    back = 0
    for cur_node in path:
        if cur_node != begin:
            if capacity[cur_node] > Cmax // 2:
                if capacity[cur_node] - Cmax // 2 - send > 0:
                    back += (capacity[cur_node] - Cmax // 2 - send)
                    send = 0
                else:
                    send -= (capacity[cur_node] - Cmax // 2)

            elif capacity[cur_node] < Cmax // 2:
                send += Cmax // 2 - capacity[cur_node]
        else:
            return (send, back)


def dfs(node: int, pathlist: list):
    global start, path
    global routie, solution
    if node != start:
        for ele in path[node]:
            pathlist.append(ele)
            dfs(ele, pathlist)
            pathlist.pop()
    else:
        solu_01 = get_sendAndback(start, pathlist)
        if solu_01 < solution:
            solution = solu_01
            routie = pathlist.copy()


Cmax, N, end, M = map(int, input().split())
capacity = list(map(int, input().split()))
capacity.insert(0, float('inf'))
########
start = 0
node_graph = dict()
collect = [0] * (N + 1)
path = [None] * (N + 1)
collect[0] = 1
uncollect = set()

#最短时间
Time = [float('inf')] * (N + 1)
Time[0] = 0

for _ in range(M):
    city1, city2, interval = map(int, input().split())
    if city1 in node_graph:
        node_graph[city1].append((city2, interval))
    else:
        node_graph[city1] = [(city2, interval)]
    if city2 in node_graph:
        node_graph[city2].append((city1, interval))
    else:
        node_graph[city2] = [(city1, interval)]

Dijkstra(start, end)
routie = []
solution = (float('inf'), float('inf'))
dfs(end, [end])
routie = reversed(list(map(str, routie)))
print(str(solution[0]), '->'.join(routie), str(solution[1]))