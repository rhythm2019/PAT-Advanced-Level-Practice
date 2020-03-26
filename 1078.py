#1078
class HASH():
    # 最小的HASH TABLESIZE
    MinTableSize = 97
    def __init__(self, tableSize: int = MinTableSize):
        # get tablseSize
        if tableSize <= 2:
            self.TableSize = 2
            self.data = [0] * self.TableSize
            return
        if tableSize % 2 == 0:
            tableSize += 1
        while True:
            for i in range(2, int(tableSize**0.5) + 1):
                if tableSize % i == 0:
                    tableSize += 2
                    break
            else:
                self.TableSize = max(tableSize, HASH.MinTableSize)
                self.data = [0] * self.TableSize
                return

    def Find(self, element: int) -> int:
        '''
        二次探测，成功返回newpos，失败返回-1
        '''
        # 二次探测
        pos = element % self.TableSize
        i = 0
        while (i <= self.TableSize
               and self.data[(pos + i**2) % self.TableSize] != 0):
            i += 1
        if i > int(self.TableSize):
            return (-1)
        else:
            return ((pos + i**2) % self.TableSize)

    def Insert(self, element: int):
        pos = self.Find(element)
        if pos != -1:
            self.data[pos] = 1
            return (True)
        else:
            return (False)


if __name__ == "__main__":
    M, N = map(int, input().split())
    in01 = map(int, input().split())
    H = HASH(M)
    out01 = []
    for ele in in01:
        pos = H.Find(ele)
        if (pos != -1):
            out01.append(pos)
            H.data[pos] = 1
        else:
            out01.append('-')
    print(*out01)
