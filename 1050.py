#1050
s1 = input()
s2 = input()
s = []
for ch in s1:
    if ch not in s2:
        s.append(ch)
print(''.join(s))