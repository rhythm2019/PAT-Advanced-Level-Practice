#1146 Topological Order (25分)
'''
Graph 
InDegree[]
'''


def judge(lst01: list, InD: list, Graph: list) -> bool:
    for node in lst01:
        if InD[node] != 0:
            return False
        else:
            for ele in Graph[node]:
                InD[ele] -= 1
    return True


N, M = map(int, input().split())
#create Graph
Graph = [[] for _ in range(N + 1)]
InDegree = [0] * (N + 1)
for _ in range(M):
    n1, n2 = map(int, input().split())
    Graph[n1].append(n2)
    InDegree[n2] += 1
#input and judge
result = []
K = int(input())
for i in range(K):
    lst01 = list(map(int, input().split()))
    if judge(lst01, InDegree.copy(), Graph) == False:
        result.append(i)
print(*result)