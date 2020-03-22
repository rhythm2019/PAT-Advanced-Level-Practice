#1013
# union-find
def find(node: int, parent_lst: int):
    root = parent_lst[node]
    while (root != node):
        node = root
        root = parent_lst[node]
    return root


def solve(node: int, N: int, connect: list) -> int:
    '''
    UNION and SOLVE 
    '''
    parent_lst = [elem for elem in range(N + 1)]
    for elem in connect:
        c1, c2 = elem
        if node != c1 and node != c2 and find(c1, parent_lst) != find(
                c2, parent_lst):
            parent_lst[find(c1, parent_lst)] = find(c2, parent_lst)
    count = 0
    for i in range(1, N + 1):
        if parent_lst[i] == i:
            count += 1
    return (count - 2)


N, M, K = map(int, input().split())
connection_lst = []
for _ in range(M):
    c1, c2 = input().split()
    connection_lst.append((int(c1), int(c2)))
lostcity_map = map(int, input().split())
# begin UF
result = []
for elem in lostcity_map:
    count = solve(elem, N, connection_lst)
    print(count)