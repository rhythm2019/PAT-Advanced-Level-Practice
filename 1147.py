# 1147
def dfs(node: int, heap: list, lst01: list):
    N = len(heap)
    if 2 * node + 1 < N:
        dfs(2 * node + 1, heap, lst01)
    if 2 * node + 2 < N:
        dfs(2 * node + 2, heap, lst01)
    lst01.append(heap[node])


def isMax(heap: list):
    N = len(heap)
    for i in range(N):
        left = 2 * i + 1
        right = 2 * i + 2
        if (left < N and heap[i] < heap[left]) or (right < N
                                                   and heap[i] < heap[right]):
            return False
    else:
        return True


def isMin(heap: list):
    N = len(heap)
    for i in range(N):
        left = 2 * i + 1
        right = 2 * i + 2
        if (left < N and heap[i] > heap[left]) or (right < N
                                                   and heap[i] > heap[right]):
            return False
    else:
        return True


M, N = input().split()
result = []
for _ in range(int(M)):
    heap = list(map(int, input().split()))
    if isMax(heap):
        result.append('Max Heap')
    elif isMin(heap):
        result.append('Min Heap')
    else:
        result.append('Not Heap')
    lst01 = []
    dfs(0, heap, lst01)
    result.append(lst01)

for ele in result:
    if type(ele) == str:
        print(ele)
    else:
        print(*ele)