#1136 A Delayed Palindrome (20分)
#DATE:20200820
str01 = input()
for i in range(10):
    if str01 == str01[::-1]:
        print("{} is a palindromic number.".format(str01))
        break
    str02 = int(str01) + int(str01[::-1])
    print("{} + {} = {}".format(str01, str01[::-1], str02))
    str01 = str(str02)
else:
    print("Not found in 10 iterations.")