#1013
#dfs
def dfs(node: int, graph: list, visit: list):
    if visit[node] == 0:
        visit[node] = 1
        for i in range(len(graph[node])):
            if visit[graph[node][i]] == 0:
                dfs(graph[node][i], graph, visit)

N, M, K = map(int, input().split())
road_lst = [[] for i in range(N + 1)]
for _ in range(M):
    c1, c2 = map(int, input().split())
    road_lst[c1].append(c2)
    road_lst[c2].append(c1)
lostcity_map = map(int, input().split())

# begin DFS
result = []
for elem in lostcity_map:
    linkNUM = 0
    road = road_lst.copy()
    road[elem] = []
    cityStatus_lst = [0] * (N + 1)
    cityStatus_lst[elem] = 1
    for city in range(1, N + 1):
        if cityStatus_lst[city] == 0:
            linkNUM += 1
            dfs(city, road, cityStatus_lst)
    result.append(linkNUM - 1)
for ele in result:
    print(ele)