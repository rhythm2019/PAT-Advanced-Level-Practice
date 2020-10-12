# 1061 Dating
day_lst = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
s1 = input()
s2 = input()
s3 = input()
s4 = input()

i = 0
count = 0
result = []
while i < min(len(s1), len(s2)):
    if s1[i] == s2[i]:
        if 'A' <= s1[i] <= 'G' and count == 0:
            count += 1
            d1 = ord(s1[i]) - ord('A') + 1
            result.append(day_lst[d1 - 1])
        elif 'A' <= s1[i] <= 'N' and count == 1:
            h1 = "{:0>2}".format(ord(s1[i]) - ord('A') + 10)
            result.append(h1)
            break
        elif '0' <= s1[i] <= '9' and count == 1:
            h1 = "{:0>2}".format(s1[i])
            result.append(h1)
            break
    i += 1

i = 0
while i < min(len(s3), len(s4)):
    if s3[i] == s4[i] and 'A' <= s3[i].upper() <= 'Z':
        break
    i += 1
result.append("{:0>2}".format(i))
print("{day[0]} {day[1]}:{day[2]}".format(day=result))