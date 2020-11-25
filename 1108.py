#1108 Finding Average (20分)
#DATE:20200818
list01 = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
set01 = set(list01)


def isLegal(num):
    k = num.find('.')
    str02 = num[:]
    ###########################################
    if k != -1:
        str02 = num[:k]
        str03 = num[k + 1:]
        if len(str03) > 2:
            return False
        for ch in str03:
            if ch not in set01:
                return False
    ###########################################
    if str02 == "-" or (str02[0] == '0' and len(str02) > 1):
        return False
    if str02[0] == "-":
        str02 = str02[1:]
    for i in range(len(str02)):
        if str02[i] not in set01:
            return False
    if float(num) > 1000 or float(num) < -1000:
        return False
    else:
        return True


N = int(input())
str01 = input().split()
count = 0
sum = 0
for ele in str01:
    if (isLegal(ele) == False):
        print("ERROR: {} is not a legal number".format(ele))
    else:
        count += 1
        sum += float(ele)
if (count > 1):
    print("The average of {} numbers is {:.2f}".format(count, sum / count))
elif (count == 1):
    print("The average of 1 number is {:.2f}".format(sum))
else:
    print("The average of 0 numbers is Undefined")