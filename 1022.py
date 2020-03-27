#1022
'''
1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
'''
D_id = dict()
D_title = dict()
D_author = dict()
D_keyword = dict()
D_pub = dict()
D_repre = dict()
D_query = {
    "1:": D_title,
    "2:": D_author,
    "3:": D_keyword,
    "4:": D_pub,
    "5:": D_repre
}
N = int(input())
for _ in range(N):
    ID = input()
    if len(ID) < 6:
        ID = '0' * (6 - len(ID)) + ID
    Title = input()
    Author = input()
    Keyword = input().split()
    Publisher = input()
    Represent = input()
    D_id[ID] = [Title, Author, Keyword, Publisher, Represent]
    if Title in D_title:
        D_title[Title].append(ID)
    else:
        D_title[Title] = [ID]

    if Author in D_author:
        D_author[Author].append(ID)
    else:
        D_author[Author] = [ID]

    for ele in Keyword:
        if ele in D_keyword:
            D_keyword[ele].append(ID)
        else:
            D_keyword[ele] = [ID]

    if Publisher in D_pub:
        D_pub[Publisher].append(ID)
    else:
        D_pub[Publisher] = [ID]

    if Represent in D_repre:
        D_repre[Represent].append(ID)
    else:
        D_repre[Represent] = [ID]
if __name__ == "__main__":
    M = int(input())
    query = []
    for _ in range(M):
        query.append(input())
    for i in range(M):
        ele = query[i]
        print(query[i])
        if ele[0:2] in D_query:
            D = D_query[ele[0:2]]
            if ele[3:] in D:
                D[ele[3:]].sort()
                for x in D[ele[3:]]:
                    print(x)
            else:
                print("Not Found")
        else:
            print("Not Found")
