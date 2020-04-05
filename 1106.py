# 1106 Lowest Price in Supply Chain (25分)
N, P, R = map(float, input().split())
dict01 = dict()
for i in range(int(N)):
    str01 = input().split()
    if str01[0] != '0':
        dict01[str(i)] = str01[1:]        

lst03=[('0',1)]
layer = 0
i = 0
while i < len(lst03):
    cur_node = lst03[i]
    #非叶节点
    if cur_node[0] in dict01:
        for ele in dict01[cur_node[0]]:
                lst03.append((ele, cur_node[1] + 1))
    else:
        if layer == cur_node[1]:
            count += 1 
        elif layer == 0:
            layer = cur_node[1]
            count = 1 
        else:
            break  
    i += 1
print('{:.4f} {}'.format(P*(1+R/100)**(layer-1), count))
