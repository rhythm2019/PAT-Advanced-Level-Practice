#1064
# tree node dict
dict01 = dict()


def inorder(node_num: int, N: int, index_lst: list):
    if 2 * node_num + 1 < N:
        inorder(2 * node_num + 1, N, index_lst)
    index_lst.append(node_num)
    if 2 * node_num + 2 < N:
        inorder(2 * node_num + 2, N, index_lst)


N = int(input())
lst01 = list(map(int, input().split()))
lst01.sort()
lst02 = []
inorder(0, N, lst02)
lst03 = [None] * N
for i in range(N):
    lst03[lst02[i]] = lst01[i]
print(*lst03)