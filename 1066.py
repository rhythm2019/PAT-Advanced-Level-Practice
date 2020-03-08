# 1066 Root of AVL Tree
'''
AVL 的创建和调整
An AVL tree is a self-balancing binary search tree. 
In an AVL tree, the heights of the two child subtrees of any node differ by at most one; 
if at any time they differ by more than one, rebalancing is done to restore this property. 
Figures 1-4 illustrate the rotation rules.

Each input file contains one test case. For each case, 
the first line contains a positive integer N (≤20) which is the total number of keys to be inserted. 
Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

For each test case, print the root of the resulting AVL tree in one line.
'''
def rjust(bst: list, path, path_diff):
    '''
    调整AVL树，实现自平衡，更新bst
    返回 root 值
    '''
    global lst01
    length = len(path)
    if length <= 1:
        return path[0]
    else:
        i = -1
        while -i <= length and path_diff[i] < 2:
            i -= 1
        if -i > length:
            return path[0]

        n2 = path[i]
        n3 = path[i + 1]
        n4 = path[i + 2]
        #旋转类型LL, n2不平衡节点
        if lst01[n4] < lst01[n3] < lst01[n2]:
            bst[n2][0] = bst[n3][1]
            bst[n3][1] = n2
            if -i < length:
                n1 = path[i - 1]
                if lst01[n1] > lst01[n3]:
                    bst[n1][0] = n3
                    return path[0]
                else:
                    bst[n1][1] = n3
                    return path[0]
            else:
                return n3

        #旋转类型RR
        elif lst01[n4] > lst01[n3] > lst01[n2]:
            bst[n2][1] = bst[n3][0]
            bst[n3][0] = n2
            if -i < length:
                n1 = path[i - 1]
                if lst01[n1] > lst01[n3]:
                    bst[n1][0] = n3
                    return path[0]
                else:
                    bst[n1][1] = n3
                    return path[0]
            else:
                return n3

        #旋转类型LR
        elif lst01[n4] > lst01[n3] < lst01[n2]:
            bst[n2][0] = bst[n4][1]
            bst[n3][1] = bst[n4][0]
            bst[n4] = [n3, n2]
            if -i < length:
                n1 = path[i - 1]
                if lst01[n1] > lst01[n4]:
                    bst[n1][0] = n4
                    return path[0]
                else:
                    bst[n1][1] = n4
                    return path[0]                
            else:
                return n4

        #旋转类型RL
        elif lst01[n4] < lst01[n3] > lst01[n2]:
            bst[n2][1] = bst[n4][0]
            bst[n3][0] = bst[n4][1]
            bst[n4] = [n2, n3]
            if -i < length:
                n1 = path[i - 1]
                if lst01[n1] > lst01[n4]:
                    bst[n1][0] = n4
                    return path[0]
                else:
                    bst[n1][1] = n4
                    return path[0]                
            else:
                return n4

def get_height(bst: list, node: int):
    if node == None or bst[node] == None:
        return 0
    else:
        if bst[node] == [None, None]:
            return 1
        else:
            return (max(get_height(bst, bst[node][0]),
                        get_height(bst, bst[node][1])) + 1)


def get_diff(bst: list, node: int):
    return (abs(get_height(bst, bst[node][0]) - get_height(bst, bst[node][1])))


def insert_bst(bst: list, root: int, node: int) -> list:
    '''
    bst插入节点，返回插入路径
    '''
    global lst01
    path = []
    if root == -1:
        root = node
        bst[root] = [None, None]
        path.append(root)
        return path
    else:
        cur_node = root
        while bst[cur_node]:
            path.append(cur_node)
            if lst01[node] > lst01[cur_node]:
                if bst[cur_node][1] == None:
                    bst[cur_node][1] = node
                    bst[node] = [None, None]
                    path.append(node)
                    break
                else:
                    cur_node = bst[cur_node][1]
            else:
                if bst[cur_node][0] == None:
                    bst[cur_node][0] = node
                    bst[node] = [None, None]
                    path.append(node)
                    break
                else:
                    cur_node = bst[cur_node][0]
    return path


N = int(input())
lst01 = list(map(int, input().split()))
child_lst = [None] * N
root = -1
for i in range(N):
    path_lst = insert_bst(child_lst, root, i)
    if len(path_lst) == 1:
        root = i
    else:
        #寻找不平衡节点
        path_height = [get_diff(child_lst, ele) for ele in path_lst]
        root = rjust(child_lst, path_lst, path_height)
# print(root)
print(lst01[root])