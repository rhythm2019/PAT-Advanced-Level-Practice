# 1083 List Grades
N = int(input())
lst01 = []
for _ in range(N):
    name, ID, grade = input().split()
    lst01.append([name, ID, int(grade)])
LOW, HIGH = map(int, input().split())
lst01.sort(key=lambda x: x[-1], reverse=True)
Flag = True
for ele in lst01:
    if LOW <= ele[-1] <= HIGH:
        print(ele[0], ele[1])
        Flag = False
if Flag:
    print("NONE")