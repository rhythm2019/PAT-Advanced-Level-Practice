#1094
dict01 = dict()
N, M = map(int, input().split())
for i in range(M):
    lst01 = input().split()
    dict01[lst01[0]] = lst01[2:]

root = '01'

cur_layer = [root]
v_max = 0
v_layer = 0
layer = 0
#开始层式遍历
while cur_layer:
    v1 = len(cur_layer)
    layer += 1
    if v1 > v_max:
        v_max = v1
        v_layer = layer

    next_layer = []
    for x in cur_layer:
        if x in dict01:
            next_layer.extend(dict01[x])
    cur_layer = next_layer

print(v_max, v_layer)