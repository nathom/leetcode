class ehrlich_iter:
    def __init__(self, n):
        self.n = n
        self.b = range(0, n)
        self.c = [0] * (n + 1)

    def __iter__(self):
        return self

    def next(self):
        k = 1
        while self.c[k] == k:
            self.c[k] = 0
            k += 1
        if k == self.n:
            raise StopIteration
        self.c[k] += 1
        self.b[1 : k - 1].reverse
        return self.b[k]


mylist = [1, 2, 3]  # test it
# print(list(ehrlich_iter(6)))
for v in ehrlich_iter(len(mylist)):
    mylist[0], mylist[v] = mylist[v], mylist[0]
    print(v, mylist)
