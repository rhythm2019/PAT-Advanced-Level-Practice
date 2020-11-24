# 1155
def dfs(node: int, heap: list, lst01: list):
    N = len(heap)
    lst01.append(heap[node])
    if 2 * node + 1 >= N:
        print(*lst01)
    else:
        if 2 * node + 2 < N:
            dfs(2 * node + 2, heap, lst01)
        if 2 * node + 1 < N:
            dfs(2 * node + 1, heap, lst01)
    lst01.pop()


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


N = int(input())
heap = list(map(int, input().split()))
dfs(0, heap, [])
if isMax(heap):
    print('Max Heap')
elif isMin(heap):
    print('Min Heap')
else:
    print('Not Heap')