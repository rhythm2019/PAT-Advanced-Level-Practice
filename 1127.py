# 1127 ZigZagging on a Tree (30分)
def create_tree(inlist: list, postlist: list, node_graph: dict):
    if inlist:
        ele = postlist[-1]
        index = inlist.index(ele)
        if len(inlist) == 1:
            node_graph[ele] = [None, None]
        else:
            if index == 0:
                node_graph[ele] = [None, postlist[-2]]
            elif index == len(inlist) - 1:
                node_graph[ele] = [postlist[-2], None]
            else:
                node_graph[ele] = [postlist[index - 1], postlist[-2]]
            ######
            create_tree(inlist[0:index], postlist[0:index], node_graph)
            create_tree(inlist[index + 1:], postlist[index:-1], node_graph)
    else:
        return


'''
基本规则，所有node都在dict01中
'''
N = int(input())
lst01 = input().split()
lst02 = input().split()
dict01 = dict()
result = []
create_tree(lst01, lst02, dict01)
root = lst02[-1]
lst03 = [(root, 1)]

while lst03:
    cur_node = lst03.pop(0)
    result.append(cur_node)
    if cur_node[0] in dict01:
        for ele in dict01[cur_node[0]]:
            if ele != None:
                lst03.append((ele, cur_node[1] + 1))
i = 1
r1 = []
while len(r1) < len(result):
    index = len(r1)
    lst03 = [ele[0] for ele in result[index:] if ele[1] == i]
    if (i % 2):
        r1.extend(lst03[::-1])
    else:
        r1.extend(lst03)
    i += 1
print(*r1)