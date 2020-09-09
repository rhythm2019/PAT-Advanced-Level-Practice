#1020
def get_simple(post_order: list, in_order: list):
    if post_order == []:
        return
    elif len(post_order) == 1:
        return [post_order[0]]
    elif len(post_order) == 2:
        return [post_order[-1], [[post_order[0]], [post_order[0]]]]
    else:
        index_i = in_order.index(post_order[-1])
        return [post_order[-1],[ post_order[0:index_i],in_order[0:index_i] ],\
                [post_order[index_i : len(post_order)-1],in_order[index_i+1:]]]


N = int(input())
lst01 = list(map(int, input().split()))
lst02 = list(map(int, input().split()))
lst03 = [(lst01, lst02)]
result_lst = []
while lst03:
    x = lst03.pop(0)
    result = get_simple(x[0], x[1])
    if result:
        result_lst.append(result[0])
        for _ in result[1:]:
            lst03.append(_)
print(*result_lst)