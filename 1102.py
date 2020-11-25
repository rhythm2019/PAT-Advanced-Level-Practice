# 1102
def in_order(node_graph: dict, root: int):
    global result
    lst01 = node_graph[root]
    if lst01[0] != None:
        in_order(node_graph, lst01[0])
    result.append(root)
    if lst01[1] != None:
        in_order(node_graph, lst01[1])


N = int(input())
dict01 = dict()
set01 = set()
for i in range(N):
    str01 = input().split()
    for index in range(2):
        if str01[index] == '-':
            str01[index] = None
        else:
            str01[index] = int(str01[index])
            set01.add(str01[index])
    dict01[i] = (str01[1], str01[0])
#find root
root = set(range(N)).difference(set01).pop()

lst03 = [root]
i = 0
while i < len(lst03):
    cur_node = lst03[i]
    for ele in dict01[cur_node]:
        if ele != None:
            lst03.append(ele)
    i += 1
print(*lst03)

result = []
in_order(dict01, root)
print(*result)