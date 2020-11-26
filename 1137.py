#1137
def sirewuru(G: float) -> int:
    G = format(G, '.2f')
    if (G[-2] >= '5'):
        return int(float(G)) + 1
    else:
        return int(float(G))


P, M, N = map(int, input().split())
s1 = dict()
s2 = dict()
s3 = dict()
for _ in range(P):
    in1 = input().split()
    s1[in1[0]] = int(in1[1])
for _ in range(M):
    in1 = input().split()
    s2[in1[0]] = int(in1[1])
for _ in range(N):
    in1 = input().split()
    s3[in1[0]] = int(in1[1])
s4 = set(s1.keys()).intersection(set(s3.keys()))
lst01 = []
for stu_number in s4:
    if s1[stu_number] >= 200:
        if stu_number in s2:
            if s2[stu_number] < s3[stu_number]:
                G = s3[stu_number]
            else:
                G = sirewuru(0.4 * s2[stu_number] + 0.6 * s3[stu_number])

            if G >= 60:
                lst01.append((stu_number, s1[stu_number], s2[stu_number],
                              s3[stu_number], G))
        else:
            if s3[stu_number] >= 60:
                lst01.append((stu_number, s1[stu_number], -1, s3[stu_number],
                              s3[stu_number]))
lst01.sort(key=lambda x: x[0])
lst01.sort(key=lambda x: x[4], reverse=True)
for x in lst01:
    print(*x[:-1], round(x[-1]))