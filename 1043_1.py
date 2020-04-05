# 1043 Is It a Binary Search Tree
def postTravel(Tree: dict, lst01: list, root: int, postOrder: list):

    if root != None:
        postTravel(Tree, lst01, Tree[root][0], postOrder)
        postTravel(Tree, lst01, Tree[root][1], postOrder)
        postOrder.append(lst01[root])
    return


def judge(Tree: dict, preOrder: list, inOrder: list, base: int, reverse=False):
    Tree = dict()
    queue = [(preOrder, inOrder, base)]
    Flag = True
    while queue:
        cur = queue.pop(0)
        pre_lst = cur[0]
        inorder_lst = cur[1]
        base = cur[2]
        #create tree
        if len(pre_lst) > 0:
            root = pre_lst[0]
            if root not in inorder_lst:
                Flag = False
                break
            else:
                index_i = inorder_lst.index(root) if reverse == False else len(
                    inorder_lst) - inorder_lst[::-1].index(root) - 1
                if len(pre_lst) == 1:
                    BSTree[base] = [None, None]
                else:
                    if index_i == 0:
                        BSTree[base] = [None, base + 1]
                    elif index_i == len(pre_lst) - 1:
                        BSTree[base] = [base + 1, None]
                    else:
                        BSTree[base] = [base + 1, base + index_i + 1]
                    queue.append((pre_lst[1:index_i + 1],
                                  inorder_lst[0:index_i], base + 1))
                    queue.append(
                        (pre_lst[index_i + 1:], inorder_lst[index_i + 1:],
                         base + index_i + 1))
    return Flag

import sys
sys.setrecursionlimit(3000)
N = int(input())
preOrder = list(map(int, input().split()))
inOrder = sorted(preOrder)
BSTree = dict()
if judge(BSTree, preOrder, inOrder, 0) or judge(BSTree, preOrder,
                                                inOrder[::-1], 0, True):
    root = 0
    result = []
    postTravel(BSTree, preOrder, root, result)
    # print(BSTree)
    print("YES")
    print(*result)
else:
    # print(BSTree)
    print("NO")