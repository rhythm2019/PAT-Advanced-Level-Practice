# 1053 Path of Equal Weight (30分)
def dfs(node, node_graph, weight_lst):
    global lst01, W
    if node not in dict01:
        lst01.append(weight_lst[int(node)])
        if sum(lst01) == W:
            result.append(lst01[:])
        lst01.pop()
    else:
        lst01.append(weight_lst[int(node)])
        for ele in dict01[node]:
            dfs(ele, node_graph, weight_lst)
        lst01.pop()


N, M, W = map(int, input().split())
dict01 = dict()
weight = list(map(int, input().split()))
for _ in range(M):
    str1 = input().split()
    dict01[str1[0]] = str1[2:]
root = '00'
lst01 = []
result = []
dfs(root, dict01, weight)
result.sort(reverse=True)
for ele in result:
    print(*ele)