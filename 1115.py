#1115 Counting Nodes in a BST (30分)
def insertNode(i: int, key: int, Tree: dict):
    Tree[i] = [key, None, None]
    if len(Tree) > 1:
        cur = 0
        while True:
            if key <= Tree[cur][0]:
                if Tree[cur][1] == None:
                    Tree[cur][1] = i
                    break
                else:
                    cur = Tree[cur][1]
            else:
                if Tree[cur][2] == None:
                    Tree[cur][2] = i
                    break
                else:
                    cur = Tree[cur][2]
    return


def dfs(i: int, Tree: dict, layer: int):
    global Layer, max_layer
    if i != None:
        Layer[i] = layer
        if layer > max_layer:
            max_layer = layer
        dfs(Tree[i][1], Tree, layer + 1)
        dfs(Tree[i][2], Tree, layer + 1)
    return

import sys
sys.setrecursionlimit(3000)
N = int(input())
lst01 = list(map(int, input().split()))
Layer = [0] * N
max_layer = 0
#create BST
Tree = dict()
root = 0
for i in range(N):
    node = lst01[i]
    insertNode(i, node, Tree)
dfs(0, Tree, 1)
n1 = Layer.count(max_layer)
n2 = Layer.count(max_layer - 1)
print("{} + {} = {}".format(n1, n2, n1 + n2))