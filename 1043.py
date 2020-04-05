# 1043 Is It a Binary Search Tree
def postTravel(Tree: dict, lst01: list, root: int, postOrder: list):
    if root in Tree:
        postTravel(Tree, lst01, Tree[root][0], postOrder)
        postTravel(Tree, lst01, Tree[root][1], postOrder)
    if root != None:
        postOrder.append(lst01[root])
    return


def preTravel(Tree: dict, lst01: list, node: int, preOrder: list):
    if node != None:
        preOrder.append(lst01[node])
        if node in Tree:
            preTravel(Tree, lst01, Tree[node][0], preOrder)
            preTravel(Tree, lst01, Tree[node][1], preOrder)
    return


def createBST(preOrder: list):
    Tree = dict()
    for i in range(1, len(preOrder)):
        cur = 0
        while True:
            if cur not in Tree:
                Tree[cur] = [None, None]
            if preOrder[i] < preOrder[cur]:
                if Tree[cur][0] == None:
                    Tree[cur][0] = i
                    break
                else:
                    cur = Tree[cur][0]
            else:
                if Tree[cur][1] == None:
                    Tree[cur][1] = i
                    break
                else:
                    cur = Tree[cur][1]
    return Tree

import sys
sys.setrecursionlimit(3000)
N = int(input())
preOrder = list(map(int, input().split()))
BSTree = createBST(preOrder)
LIST01 = []
preTravel(BSTree, preOrder, 0, LIST01)
if LIST01 == preOrder:
    result = []
    postTravel(BSTree, preOrder, 0, result)
    print("YES")
    print(*result)
else:
    for ele in BSTree:
        BSTree[ele][0], BSTree[ele][1] = BSTree[ele][1], BSTree[ele][0]
    LIST01 = []
    preTravel(BSTree, preOrder, 0, LIST01)
    if LIST01 == preOrder:
        result = []
        postTravel(BSTree, preOrder, 0, result)
        print("YES")
        print(*result)
    else:
        # print(BSTree)
        print("NO")