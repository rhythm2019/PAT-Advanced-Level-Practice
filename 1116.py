#1116 Come on! Let's C (20)
def get_prime():
    global prime
    N = len(prime)
    for i in range(2, N):
        if prime[i] == 1:
            for j in range(2 * i, N, i):
                prime[j] = 0


N = int(input())
prime = [1] * (N + 1)
get_prime()
dict01 = dict()
for rank in range(N):
    dict01[input()] = rank + 1
N = int(input())
lst02 = list()
for _ in range(N):
    lst02.append(input())
for i in range(N):
    per = lst02[i]
    if per in dict01:
        rank = dict01[per]
        dict01[per] = -1
        if rank == -1:
            print("{}: {}".format(per, "Checked"))
        elif rank == 1:
            print("{}: {}".format(per, "Mystery Award"))
        elif prime[rank] == 1:
            print("{}: {}".format(per, "Minion"))
        else:
            print("{}: {}".format(per, "Chocolate"))
    else:
        print("{}: {}".format(per, "Are you kidding?"))