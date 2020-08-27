# 1016 Phone Bills
def get_cost(t1: list, t2: list) -> tuple:
    global toll
    if t1[0] == t2[0] and t1[1] == t2[1]:
        ptime = t2[2] - t1[2]
        cost = ptime * toll[t1[1]]
    elif t1[0] == t2[0] and t1[1] != t2[1]:
        ptime = 60 - t1[2] + t2[2] + (t2[1] - t1[1] - 1) * 60
        cost = (60 - t1[2]) * toll[t1[1]] + 60 * sum(
            toll[t1[1] + 1:t2[1]]) + t2[2] * toll[t2[1]]
    else:
        ptime = 60 - t1[2] + t2[2] + (23 - t1[1] +
                                      t2[1]) * 60 + (t2[0] - t1[0] - 1) * 1440
        cost = (60 - t1[2]) * toll[t1[1]] + t2[2] * toll[t2[1]] + 60 * sum(
            toll[t1[1] + 1:]) + 60 * sum(
                toll[0:t2[1]]) + (t2[0] - t1[0] - 1) * 60 * sum(toll)
    return ptime, cost


lst01 = []
dict01 = dict()
result = []
toll = list(map(int, input().split()))
N = int(input())
for _ in range(N):
    lst01.append(input().split())
lst01.sort(key=lambda ele: (ele[0], ele[1]))
for ele in lst01:
    if ele[0] in dict01:
        dict01[ele[0]].append((ele[1], ele[2]))
    else:
        dict01[ele[0]] = [(ele[1], ele[2])]
lst01 = list(dict01.keys())
lst01.sort()
for name in lst01:
    record = dict01[name]
    Total_cost = 0
    Total_time = 0
    result = []
    i = 0
    while i < len(record) - 1:
        if record[i][1] == "off-line" or record[i + 1][1] == "on-line":
            i += 1
        else:
            t1 = list(map(int, record[i][0].split(":")[1:]))
            t2 = list(map(int, record[i + 1][0].split(":")[1:]))
            ptime, cost = get_cost(t1, t2)
            result.append("{} {} {} ${:.2f}".format(record[i][0][3:11],
                                                    record[i + 1][0][3:11],
                                                    ptime, cost / 100.))
            Total_time += ptime
            Total_cost += cost
            i += 2
    if result:
        print(name, record[0][0][0:2])
        for ele in result:
            print(ele)
        print("Total amount: ${:.2f}".format(Total_cost / 100.))