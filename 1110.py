#1110 Complete Binary Tree (25分)
# create tree
N = int(input())
Tree = dict()
root = set(range(N))
for i in range(N):
    n1, n2 = input().split()
    n1 = None if n1 == '-' else int(n1)
    n2 = None if n2 == '-' else int(n2)
    if n1 != None:
        root.remove(n1)
    if n2 != None:
        root.remove(n2)
    Tree[i] = [n1, n2]
#find root and BFS
root = list(root)[0]
Queue = [root]
index = 0
CBTFlag = 1
while Queue:
    cur = Queue.pop(0)
    if Tree[cur][0] != None:
        if 2 * index + 1 < N:
            Queue.append(Tree[cur][0])
        else:
            CBTFlag = 0
            break
    if Tree[cur][1] != None:
        if 2 * index + 2 < N:
            Queue.append(Tree[cur][1])
        else:
            CBTFlag = 0
            break
    index += 1
if CBTFlag:
    print("YES", cur)
else:
    print("NO", root)