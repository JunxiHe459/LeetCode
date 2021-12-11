# 146. LRU Cache

做题前：

1. 用一个 doubly linked list + hash map



做题中：

1. ```python
   # Doubly linked list
   class Node:
       def __init__(self, key: int, value: int):
           self.key = key
           self.value = value
           self.prev: Node
           self.next: Node
   
   
   class LRUCache:
   
       def __init__(self, capacity: int):
           self.capacity = capacity
           self.m = {}
           self.head = Node(-1, -1)
           self.tail = Node(-1, -1)
           self.head.next = self.tail
           self.tail.prev = self.head
   
       def get(self, key: int) -> int:
           if key not in self.m:
               return -1
           
           node = self.m[key]
           
           # remove the node from doubly linked list
           node.prev.next = node.next
           node.next.prev = node.prev
           
           # add the node before tail
           node.prev = self.tail.prev
           self.tail.prev.next = node
           self.tail.prev = node
           node.next = self.tail
           
           return node.value
           
           
           
   
       def put(self, key: int, value: int) -> None:
           # If ket already exsists, update its value
           if key in self.m:
               node = self.m[key]
               node.value = value
               
               # remove the node from doubly linked list
               node.prev.next = node.next
               node.next.prev = node.prev
           
               # add the node before tail
               node.prev = self.tail.prev
               self.tail.prev.next = node
               self.tail.prev = node
               node.next = self.tail
               
               return
           
           # Else, a new key-value pair is inserted
           node = Node(key, value)
           if len(self.m.keys()) < self.capacity:
               node.prev = self.tail.prev
               self.tail.prev.next = node
               self.tail.prev = node
               node.next = self.tail
               self.m[key] = node
           else:
               del self.m[self.head.next.key]
               self.head.next = self.head.next.next
               self.head.next.prev = self.head
               
               node.prev = self.tail.prev
               self.tail.prev.next = node
               self.tail.prev = node
               node.next = self.tail
               self.m[key] = node
           return
   
   
   # Your LRUCache object will be instantiated and called as such:
   # obj = LRUCache(capacity)
   # param_1 = obj.get(key)
   # obj.put(key,value)
   ```

1. 

做题后：

1. 

