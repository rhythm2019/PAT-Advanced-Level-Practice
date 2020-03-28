#1034 Head of a Gang
def get_root(p: str) -> str:
    global d1
    global gang
    if p not in d1:
        d1[p] = [p, 0]
        gang[p] = [p]
        return p
    else:
        root = d1[p][0]
        while root != p:
            p = root
            root = d1[p][0]
        return root


gang = dict()
d1 = dict()
N, K = map(int, input().split())
for _ in range(N):
    p1, p2, t = input().split()
    t = int(t)
    r1 = get_root(p1)
    r2 = get_root(p2)
    d1[p1][1] += t
    d1[p2][1] += t
    if r1 != r2:
        d1[r2][0] = r1
        gang[r1].extend(gang[r2])
        del gang[r2]
result = []
for k, v in gang.items():
    if len(v) > 2:
        TOTAL = 0
        T = 0
        HEAD = None
        for peop in v:
            TOTAL += d1[peop][1]
            if d1[peop][1] > T:
                T = d1[peop][1]
                HEAD = peop
        if TOTAL > 2 * K:
            result.append([HEAD, len(v)])
print(len(result))
if result:
    result.sort()
    for ele in result:
        print(*ele)