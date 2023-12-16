# LFU 缓存算法实现
class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity # 缓存的容量
        self.cache = {} # 存储 key 到 value 和 frequency 的映射
        self.freq = {} # 存储 frequency 到双向链表的映射
        self.minFreq = 0 # 最小使用频率
        self.size = 0 # 当前缓存大小

    def get(self, key: int) -> int:
        if key not in self.cache: return -1 # 如果 key 不存在，返回 -1
        node = self.cache[key] # 获取 key 对应的节点
        self._increaseFreq(node) # 更新节点的访问频率和最近使用时间
        return node.value # 返回节点的值

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0: return # 如果容量为零，直接返回
        if key in self.cache: # 如果 key 已存在，更新其值和访问频率
            node = self.cache[key]
            node.value = value
            self._increaseFreq(node)
        else: # 如果 key 不存在，插入新的键值对
            if self.size == self.capacity: # 如果缓存已满，淘汰最不经常使用且最久未使用的键值对
                node = self.freq[self.minFreq].pop() # 获取最低频率链表中的尾部节点
                del self.cache[node.key] # 在 cache 中删除该节点
                self.size -= 1 # 减少缓存大小
            node = Node(key, value) # 创建新的节点
            node.freq = 1 # 设置初始访问频率为 1
            self.cache[key] = node # 在 cache 中插入新节点
            if node.freq not in self.freq: # 如果 freq 中没有频率为 1 的映射，创建一个新的双向链表
                self.freq[node.freq] = DoubleLinkedList()
            self.freq[node.freq].append(node) # 在频率为 1 的链表中添加新节点
            self.minFreq = node.freq # 设置最低访问频率为 1
            self.size += 1 # 增加缓存大小

    def _increaseFreq(self, node): # 更新节点的访问频率和最近使用时间
        freq = node.freq # 获取节点的当前访问频率
        self.freq[freq].remove(node) # 在当前频率的链表中删除节点
        if self.freq[freq].size == 0: # 如果当前频率的链表为空
            del self.freq[freq] # 删除 freq 中该频率的映射
            if freq == self.minFreq: # 如果当前频率是最低频率，更新最低频率为下一个非空频率
                self.minFreq += 1
        freq += 1 # 增加节点的访问频率
        node.freq = freq # 更新节点的访问频率
        if freq not in self.freq: # 如果 freq 中没有新频率的映射，创建一个新的双向链表
            self.freq[freq] = DoubleLinkedList()
        self.freq[freq].append(node) # 在新频率的链表中添加节点

# 双向链表节点类
class Node:

    def __init__(self, key, value):
        self.key = key # 节点的键
        self.value = value # 节点的值
        self.freq = 0 # 节点的访问频率
        self.prev = None # 节点的前驱指针
        self.next = None # 节点的后继指针

# 双向链表类
class DoubleLinkedList:

    def __init__(self):
        self.head = Node(None, None) # 链表的头哨兵节点
        self.tail = Node(None, None) # 链表的尾哨兵节点
        self.head.next = self.tail # 头尾相连
        self.tail.prev = self.head # 尾头相连
        self.size = 0 # 链表的大小

    def append(self, node): # 在链表尾部添加节点
        node.prev = self.tail.prev # 设置新节点的前驱为原尾部节点的前驱
        node.next = self.tail # 设置新节点的后继为尾哨兵节点
        node.prev.next = node # 设置原尾部节点的前驱的后继为新节点
        self.tail.prev = node # 设置尾哨兵节点的前驱为新节点
        self.size += 1 # 增加链表大小
        return node

    def pop(self): # 在链表尾部删除节点并返回该节点
        if self.size == 0: return None # 如果链表为空，返回空值
        node = self.tail.prev # 获取尾部节点
        return self.remove(node) # 删除并返回该节点

    def remove(self, node): # 在链表中删除指定节点并返回该节点
        if self.size == 0: return None # 如果链表为空，返回空值
        node.prev.next = node.next # 设置被删除节点的前驱的后继为被删除节点的后继
        node.next.prev = node.prev # 设置被删除节点的后继的前驱为被删除节点的前驱
        node.prev = None # 设置被删除节点的前驱为空值，方便垃圾回收器回收内存空间
        node.next = None # 设置被删除节点的后继为空值，方便垃圾回收器回收内存空间
        self.size -= 1 # 减少链表大小
        return node
