#1123 Is It a Complete AVL Tree (30分)
#DATE:20200827
def get_height(root, dict01):
    if (root) == None:
        return 0
    else:
        left = dict01[root][0]
        right = dict01[root][1]
        return max(get_height(left, dict01), get_height(right, dict01)) + 1


def insert_BST(node, root, dict01):
    nextpos = root
    while (nextpos != None):
        curpos = nextpos
        if node < curpos:
            Flag = 0
        elif node > curpos:
            Flag = 1
        nextpos = dict01[curpos][Flag]
    dict01[curpos][Flag] = node
    dict01[node] = [None, None, curpos]
    return


def search_UBA(node1, dict01):
    while node1 != None:
        left = dict01[node1][0]
        right = dict01[node1][1]
        if abs(get_height(left, dict01) - get_height(right, dict01)) > 1:
            break
        else:
            node1 = dict01[node1][2]
    return node1


N = int(input())
lst01 = list(map(int, input().split()))
dict01 = dict()
root = lst01[0]
dict01[root] = [None, None, None]
for i in range(1, N):
    insert_BST(lst01[i], root, dict01)
    #search unbalanced
    n1 = search_UBA(lst01[i], dict01)
    if n1 != None:
        fa = dict01[n1][2]
        if lst01[i] > n1:
            flag1 = 1
        else:
            flag1 = 0
        n2 = dict01[n1][flag1]
        if lst01[i] > n2:
            flag2 = 1
        else:
            flag2 = 0
        n3 = dict01[n2][flag2]
        # adjust
        if flag1 == 0 and flag2 == 0:
            dict01[n1] = [dict01[n2][1], dict01[n1][1], n2]
            dict01[n2] = [n3, n1, fa]
            if fa != None:
                if n2 < fa:
                    dict01[fa][0] = n2
                else:
                    dict01[fa][1] = n2
            else:
                root = n2
        elif flag1 == 1 and flag2 == 1:
            dict01[n1] = [dict01[n1][0], dict01[n2][0], n2]
            dict01[n2] = [n1, n3, fa]
            if fa != None:
                if n2 < fa:
                    dict01[fa][0] = n2
                else:
                    dict01[fa][1] = n2
            else:
                root = n2
        elif flag1 == 0 and flag2 == 1:
            dict01[n1] = [dict01[n3][1], dict01[n1][1], n3]
            dict01[n2] = [dict01[n2][0], dict01[n3][0], n3]
            dict01[n3] = [n2, n1, fa]
            if dict01[n2][1] != None:
                dict01[dict01[n2][1]][2] = n2
            if dict01[n1][0] != None:
                dict01[dict01[n1][0]][2] = n1
            if fa != None:
                if n3 < fa:
                    dict01[fa][0] = n3
                else:
                    dict01[fa][1] = n3
            else:
                root = n3
        else:
            dict01[n1] = [dict01[n1][0], dict01[n3][0], n3]
            dict01[n2] = [dict01[n3][1], dict01[n2][1], n3]
            dict01[n3] = [n1, n2, fa]
            if dict01[n2][0] != None:
                dict01[dict01[n2][0]][2] = n2
            if dict01[n1][1] != None:
                dict01[dict01[n1][1]][2] = n1
            if fa != None:
                if n3 < fa:
                    dict01[fa][0] = n3
                else:
                    dict01[fa][1] = n3
            else:
                root = n3
#BFS and judge is Complete tree
lst02 = [root]
i, j = 0, 0
flag = 1
while i <= j:
    curnode = lst02[i]    
    if dict01[curnode][0] != None:
        lst02.append(dict01[curnode][0])
        j += 1
        if (flag == 1 and 2 * i + 1 > N - 1):
            flag = 0
    if dict01[curnode][1] != None:
        lst02.append(dict01[curnode][1])
        if (flag == 1 and 2 * i + 2 > N - 1):
            flag = 0
        j += 1
    i += 1
print(*lst02)
if (flag == 1):
    print("YES")
else:
    print("NO")