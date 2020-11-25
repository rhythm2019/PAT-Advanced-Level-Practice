#1130 Infix Expression (25分)
#DATE:20200828
def inorder(root, lst01):
    if root == -1:
        return ""
    left = lst01[root][1]
    right = lst01[root][2]
    if left == -1 and right == -1:
        return lst01[root][0]
    r1 = inorder(left, lst01)
    r2 = inorder(right, lst01)
    return "(" + r1 + lst01[root][0] + r2 + ")"


N = int(input())
lst01 = [0]
root = [1] * (N + 1)
for _ in range(N):
    x = input().split()
    x[1] = int(x[1])
    x[2] = int(x[2])
    lst01.append([x[0], x[1], x[2]])
    if x[1] != -1:
        root[x[1]] = 0
    if x[2] != -1:
        root[x[2]] = 0
i = 1
while (root[i] == 0):
    i = i + 1
result = inorder(i, lst01)
if N > 1:
    print(result[1:-1])
else:
    print(result)