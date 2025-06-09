# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)

class MyHashSet:

    def __init__(self):
        self.container = [[] for _ in range(10)]
        pass
    
    #  ---------my custom function----------
    def hash(self, value : int):
        return value % 10
    
    #if i can't find key value, return (false,-1,-1)
    def get2Didx(self, key) -> tuple[bool,int,int]:
        hash = self.hash(key)
        for idx, value in enumerate(self.container[hash]):
            if value == key:
                return (True, hash, idx)
        else:
            return (False,-1,-1)
    #  ---------my custom function end----------

    def add(self, key: int) -> None:
        find = self.contains(key)
        if not find:
            self.container[self.hash(key)].append(key)

    def remove(self, key: int) -> None:
        find, hash, idx = self.get2Didx(key)
        if find:
            del self.container[hash][idx]

    def contains(self, key: int) -> bool:
        find, hash, idx = self.get2Didx(key)
        return find

myHashSet = MyHashSet()
myHashSet.add(1)
myHashSet.add(2)
myHashSet.contains(1)
myHashSet.contains(3)
myHashSet.add(2)
myHashSet.contains(2)
myHashSet.remove(2)
myHashSet.contains(2)