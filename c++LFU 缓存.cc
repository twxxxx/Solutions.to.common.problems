#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        // 如果 key 不存在，返回 -1
        if (keyToValFreq.count(key) == 0) {
            return -1;
        }
        // 更新 key 的使用频率和最近使用时间
        update(key);
        // 返回 key 对应的值
        return keyToValFreq[key].first;
    }
    
    void put(int key, int value) {
        // 如果容量为 0，直接返回
        if (capacity == 0) {
            return;
        }
        // 如果 key 已存在，更新其值和使用频率
        if (keyToValFreq.count(key) > 0) {
            keyToValFreq[key].first = value;
            update(key);
            return;
        }
        // 如果缓存已满，淘汰最不经常使用且最久未使用的键值对
        if (size == capacity) {
            // 找到最小频率对应的链表的尾部元素
            auto it = freqToList[minFreq].back();
            // 在三个数据结构中删除该元素
            freqToList[minFreq].pop_back();
            keyToValFreq.erase(it);
            keyToListNode.erase(it);
            size--;
        }
        // 插入新的键值对到缓存中
        // 设置新键值对的频率为 1
        keyToValFreq[key] = {value, 1};
        // 将新键值对插入到频率为 1 的链表的头部
        freqToList[1].push_front(key);
        // 记录新键值对在链表中的位置
        keyToListNode[key] = freqToList[1].begin();
        // 更新最小频率为 1
        minFreq = 1;
        size++;
    }

private:
    // 定义四个数据结构
    unordered_map<int, pair<int, int>> keyToValFreq; // 存储 key 到 value 和 frequency 的映射
    unordered_map<int, list<int>> freqToList; // 存储 frequency 到双向链表的映射
    unordered_map<int, list<int>::iterator> keyToListNode; // 存储 key 在双向链表中的位置
    int minFreq; // 记录最小使用频率
    int capacity; // 记录缓存容量
    int size; // 记录缓存大小

    // 定义一个辅助函数，用来更新 key 的使用频率和最近使用时间
    void update(int key) {
        // 获取 key 对应的值和频率
        int value = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;
        // 在三个数据结构中删除原来的键值对
        keyToValFreq.erase(key);
        freqToList[freq].erase(keyToListNode[key]);
        keyToListNode.erase(key);
        // 如果原来的频率是最小频率，且对应的链表为空，更新最小频率
        if (freq == minFreq && freqToList[freq].empty()) {
            minFreq++;
        }
        // 在三个数据结构中插入更新后的键值对
        // 更新后的频率为原来的频率加一
        freq++;
        keyToValFreq[key] = {value, freq};
        freqToList[freq].push_front(key);
        keyToListNode[key] = freqToList[freq].begin();
    }
};
