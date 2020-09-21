#1039 Course List for Student (25åˆ†)
N, C = map(int, input().split())
dict01 = dict()
for _ in range(C):
    course, tmp = input().split()
    if tmp != '0':
        course = int(course)
        student = input().split()
        for element in student:
            if element in dict01:
                dict01[element].append(course)
            else:
                dict01[element] = [course]

lst01 = input().split()
for element in lst01:
    if element in dict01:
        result = dict01[element][:]
        result.sort()
    else:
        result = []
    print(element, len(result), *result)
