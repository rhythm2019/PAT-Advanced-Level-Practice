#1119 Pre- and Post-order Traversals (30?)
def judge(pre: list, post: list):
    global UniFlag, Tree
    if len(pre) == 1:
        Tree[pre[0]] = [None, None]
    elif len(pre) == 2:
        UniFlag = False
        Tree[pre[0]] = [pre[1], None]
        Tree[pre[1]] = [None, None]
    elif len(pre) > 2:
        root = pre[0]
        left = pre[1]
        right = post[-2]
        index_left = post.index(left)
        if left == right:
            UniFlag = False
            Tree[root] = [left, None]
            judge(pre[1:], post[0:-1])
        else:
            Tree[root] = [left, right]
            judge(pre[1:index_left + 2], post[0:index_left + 1])
            judge(pre[index_left + 2:], post[index_left + 1:-1])
    return


def inorder(root: int):
    global Tree, result
    if root != None:
        inorder(Tree[root][0])
        result.append(root)
        inorder(Tree[root][1])
    return


UniFlag = 1
result = []
Tree = dict()
N = int(input())
prelist = list(map(int, input().split()))
postlist = list(map(int, input().split()))
judge(prelist, postlist)
inorder(prelist[0])
if UniFlag:
    print("Yes")
else:
    print("No")
print(*result)