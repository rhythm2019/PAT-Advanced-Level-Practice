def main():
    line = input().split(" ")
    n = int(line[0])
    c = line[1]
    records = []
    for x in range(n):
        line = input()
        records.append(line)
    if c == '1':
        records = sorted(records)
    elif c == '2':
        records = sorted(records, key=lambda x: x[:6])
        records = sorted(records, key=lambda x: x[7:-3])
    elif c == '3':
        records = sorted(records, key=lambda x: x[:6])
        records = sorted(records, key=lambda x: x[-2:])

    for x in records:
        print(x)


if __name__ == "__main__":
    main()