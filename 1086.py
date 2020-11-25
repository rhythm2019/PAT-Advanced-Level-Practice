# 1086 Tree Traversals Again
def post_travel(Tree: dict, root: int):
    global lst01, result
    if root != None:
        post_travel(Tree, Tree[root][0])
        post_travel(Tree, Tree[root][1])
        result.append(lst01[root])
    return


dict01 = dict()
N = int(input())
lst01 = []
lst02 = []
result = []
stack = []
for _ in range(2 * N):
    str01 = input().split()
    if str01[0] == 'Push':
        lst01.append(str01[1])
        stack.append(str01[1])
    elif str01[0] == "Pop":
        lst02.append(stack.pop())
# create tree
lst03 = [(lst01, lst02, 0)]
root = 0
while lst03:
    pre_lst = lst03[0][0]
    inorder_lst = lst03[0][1]
    base = lst03[0][2]
    lst03.pop(0)
    if len(pre_lst) == 0:
        continue
    elif len(pre_lst) == 1:
        dict01[base] = [None, None]
    elif len(pre_lst) == 2:
        if pre_lst[0] == inorder_lst[0]:
            dict01[base] = [None, base + 1]
            dict01[base + 1] = [None, None]
        else:
            dict01[base] = [base + 1, None]
            dict01[base + 1] = [None, None]
    else:
        index_i = inorder_lst.index(pre_lst[0])
        if index_i == 0:
            dict01[base] = [None, base + 1]
        elif index_i == len(pre_lst) - 1:
            dict01[base] = [base + 1, None]
        else:
            dict01[base] = [base + 1, base + index_i + 1]
        lst03.append(
            (pre_lst[1:index_i + 1], inorder_lst[0:index_i], base + 1))
        lst03.append((pre_lst[index_i + 1:], inorder_lst[index_i + 1:],
                      base + index_i + 1))

post_travel(dict01, 0)
print(*result)