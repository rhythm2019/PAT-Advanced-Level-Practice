#1005
lst01 = list('0123456789')
lst02 = [
    'zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight',
    'nine'
]
dict01 = dict(zip(lst01, lst02))
str1 = input()
sum = 0
for ch in str1:
    sum += int(ch)
result = ''
for ch in str(sum):
    result = result + ' ' + dict01[ch]

print(result.strip())