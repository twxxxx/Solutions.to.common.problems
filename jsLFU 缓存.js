// LFU 缓存算法实现
class LFUCache {
  constructor(capacity) {
    this.capacity = capacity; // 缓存的容量
    this.cache = new Map(); // 存储 key 到 value 和 frequency 的映射
    this.freq = new Map(); // 存储 frequency 到双向链表的映射
    this.minFreq = 0; // 最小使用频率
    this.size = 0; // 当前缓存大小
  }

  // 获取键对应的值，如果不存在则返回 -1
  get(key) {
    if (!this.cache.has(key)) return -1; // 如果 key 不存在，返回 -1
    const { value, freq } = this.cache.get(key); // 获取 key 对应的值和频率
    this.freq.get(freq).delete(key); // 在原来的频率链表中删除 key
    if (this.freq.get(freq).size === 0) {
      // 如果原来的频率链表为空
      this.freq.delete(freq); // 删除该频率在 freq 中的映射
      if (freq === this.minFreq) {
        // 如果当前频率是最低频率，更新最低频率为下一个非空频率
        while (!this.freq.has(this.minFreq)) {
          this.minFreq++;
        }
      }
    }
    freq++; // 增加 key 的访问频率
    if (!this.freq.has(freq)) {
      // 如果新的频率在 freq 中没有映射，创建一个新的双向链表
      this.freq.set(freq, new Set());
    }
    this.freq.get(freq).add(key); // 在新的频率链表中添加 key
    this.cache.set(key, { value, freq }); // 更新 cache 中 key 的值和频率
    return value; // 返回 key 对应的值
  }

  // 设置键对应的值，如果已满则淘汰最不经常使用且最久未使用的键值对
  put(key, value) {
    if (this.capacity === 0) return; // 如果容量为零，直接返回
    if (this.cache.has(key)) {
      // 如果 key 已存在，更新其值和访问频率
      this.cache.set(key, { value, freq: this.cache.get(key).freq });
      this.get(key); // 调用 get 方法更新 key 的访问频率和最近使用时间
    } else {
      // 如果 key 不存在，插入新的键值对
      if (this.size === this.capacity) {
        // 如果缓存已满，淘汰最不经常使用且最久未使用的键值对
        const deleteKey = this.freq.get(this.minFreq).values().next().value; // 获取最低频率链表中的第一个 key
        this.freq.get(this.minFreq).delete(deleteKey); // 在最低频率链表中删除该 key
        if (this.freq.get(this.minFreq).size === 0) {
          // 如果最低频率链表为空，删除该频率在 freq 中的映射
          this.freq.delete(this.minFreq);
        }
        this.cache.delete(deleteKey); // 在 cache 中删除该 key
        this.size--; // 减少缓存大小
      }
      this.cache.set(key, { value, freq: 1 }); // 在 cache 中插入新的键值对，初始频率为 1
      if (!this.freq.has(1)) {
        // 如果 freq 中没有频率为 1 的映射，创建一个新的双向链表
        this.freq.set(1, new Set());
      }
      this.freq.get(1).add(key); // 在频率为 1 的链表中添加 key
      this.minFreq = 1; // 更新最低频率为 1
      this.size++; // 增加缓存大小
    }
  }
}
