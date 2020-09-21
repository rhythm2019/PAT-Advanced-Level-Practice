#1036
F = None
FH = -100
M = None
ML = 101
for _ in range(int(input())):
    lst01 = input().split()
    if lst01[1] == 'F' and int(lst01[-1]) > FH:
        F = (lst01[0], lst01[2])
        FH = int(lst01[-1])
    if lst01[1] == 'M' and int(lst01[-1]) < ML:
        M = (lst01[0], lst01[2])
        ML = int(lst01[-1])
if F:
    print(*F)
else:
    print('Absent')

if M:
    print(*M)
else:
    print('Absent')

if F and M:
    print(FH - ML)
else:
    print('NA')