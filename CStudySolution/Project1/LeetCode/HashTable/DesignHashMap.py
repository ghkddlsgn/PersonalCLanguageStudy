# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)

class MyHashMap:

    def __init__(self):
        self.HashMap = {}

    def put(self, key: int, value: int) -> None:
        self.HashMap[key] = value

    def get(self, key: int) -> int:
        if key in self.HashMap:
            return self.HashMap[key]
        else:
            return -1

    def remove(self, key: int) -> None:
        if key in self.HashMap:
            del self.HashMap[key]


myHashMap = MyHashMap()
myHashMap.put(1, 1)
myHashMap.put(2, 2)
myHashMap.get(1)
myHashMap.get(3)
myHashMap.put(2, 1)
myHashMap.get(2)
myHashMap.remove(2)
myHashMap.get(2)