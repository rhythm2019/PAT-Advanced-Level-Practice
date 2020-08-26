#1001 A+B Format (20分)
a, b = map(int, input().split())
result = str(a + b)
if result[0] == '-':
    sign = -1
    result = result[1:]
else:
    sign = 1
m = len(result) % 3
n = len(result) // 3
new = result[:m]
for i in range(n):
    new = new + ',' + result[i * 3 + m:(i + 1) * 3 + m]
if new[0] == ',':
    new = new[1:]
if sign == -1:
    new = '-' + new
print(new)