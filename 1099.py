#1099
def inorder(root: int):
    global lst01
    global dict01
    child_node = dict01[root]
    if child_node[0] != -1:
        inorder(child_node[0])
    lst01.append(root)
    if child_node[1] != -1:
        inorder(child_node[1])


dict01 = dict()
N = int(input())
for i in range(N):
    dict01[i] = list(map(int, input().split()))
node_lst = list(map(int, input().split()))
node_lst.sort()
root = 0
lst01 = []
lst02 = [None] * N
#中序遍历
inorder(root)
for i in range(N):
    lst02[lst01[i]] = node_lst[i]

#开始层式遍历
lst01 = [root]
node_lst = []
while lst01:
    cur = lst01.pop(0)
    node_lst.append(lst02[cur])
    for next_node in dict01[cur]:
        if next_node != -1:
            lst01.append(next_node)
print(*node_lst)