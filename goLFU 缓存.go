package main

import (
	"container/list"
	"fmt"
)

// LFUCache is a cache that implements LFU algorithm
type LFUCache struct {
	capacity int                      // capacity of the cache
	size     int                      // current size of the cache
	minFreq  int                      // minimum frequency in the cache
	keyMap   map[int]*list.Element    // map from key to list element
	freqMap  map[int]*list.List       // map from frequency to list of entries
}

// entry is a node in the cache
type entry struct {
	key   int // key of the entry
	value int // value of the entry
	freq  int // frequency of the entry
}

// NewLFUCache creates a new LFUCache with given capacity
func NewLFUCache(capacity int) *LFUCache {
	return &LFUCache{
		capacity: capacity,
		size:     0,
		minFreq:  0,
		keyMap:   make(map[int]*list.Element),
		freqMap:  make(map[int]*list.List),
	}
}

// Get returns the value of the key if it exists, otherwise returns -1
// It also updates the frequency and recency of the key
func (c *LFUCache) Get(key int) int {
	if elem, ok := c.keyMap[key]; ok {
		c.increaseFreq(elem) // update the frequency and recency of the key
		return elem.Value.(*entry).value
	}
	return -1
}

// Put sets or inserts the value if the key is not already present
// It also updates the frequency and recency of the key
// When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item.
func (c *LFUCache) Put(key int, value int) {
	if c.capacity == 0 {
		return // do nothing if capacity is zero
	}
	if elem, ok := c.keyMap[key]; ok {
		elem.Value.(*entry).value = value // update the value of the existing key
		c.increaseFreq(elem)              // update the frequency and recency of the key
	} else {
		if c.size == c.capacity { // cache is full, need to evict the least frequently and recently used key
			c.removeMinFreqKey()
		}
		c.addNewKey(key, value) // add a new key to the cache
	}
}

// increaseFreq updates the frequency and recency of a given list element in the cache
func (c *LFUCache) increaseFreq(elem *list.Element) {
	en := elem.Value.(*entry) // get the entry of the element
	c.freqMap[en.freq].Remove(elem) // remove the element from the list of current frequency
	if c.freqMap[en.freq].Len() == 0 { // if the list is empty, delete the entry of current frequency from the freqMap
		delete(c.freqMap, en.freq)
		if en.freq == c.minFreq { // if the current frequency is the minimum frequency, increase the minFreq by one
			c.minFreq++
		}
	}
	en.freq++ // increase the frequency of the entry by one
	if _, ok := c.freqMap[en.freq]; !ok { // if the new frequency is not in the freqMap, create a new list for it
		c.freqMap[en.freq] = list.New()
	}
	newElem := c.freqMap[en.freq].PushFront(en) // push the entry to the front of the list of new frequency
	c.keyMap[en.key] = newElem                  // update the element in the keyMap
}

// removeMinFreqKey removes a key with minimum frequency and recency from the cache
func (c *LFUCache) removeMinFreqKey() {
	l := c.freqMap[c.minFreq]          // get the list of minimum frequency
	elem := l.Back()                   // get the last element of the list, which is the least recently used one
	l.Remove(elem)                     // remove the element from the list
	if l.Len() == 0 {                  // if the list is empty, delete the entry of minimum frequency from the freqMap
		delete(c.freqMap, c.minFreq)
	}
	delete(c.keyMap, elem.Value.(*entry).key) // delete the key from the keyMap
	c.size--                                  // decrease the size of the cache by one
}

// addNewKey adds a new key to the cache with initial value and frequency
func (c *LFUCache) addNewKey(key int, value int) {
	en := &entry{key: key, value: value, freq: 1} // create a new entry with frequency 1
	if _, ok := c.freqMap[1]; !ok {               // if there is no list for frequency 1, create a new one
		c.freqMap[1] = list.New()
	}
	elem := c.freqMap[1].PushFront(en) // push the entry to the front of the list of frequency 1
	c.keyMap[key] = elem               // put the element in the keyMap
	c.minFreq = 1                      // set the minFreq to 1
	c.size++                           // increase the size of the cache by one
}

func main() {
	cache := NewLFUCache(2)
	cache.Put(1, 10)
	cache.Put(2, 20)
	fmt.Println(cache.Get(1)) // returns 10 and updates (1,10) to freq 2
	fmt.Println(cache.Get(2)) // returns 20 and updates (2,20) to freq 2
	cache.Put(3, 30)          // evicts (1,10) because it has min freq and recency
	fmt.Println(cache.Get(1)) // returns -1 because (1,10) is evicted
	fmt.Println(cache.Get(3)) // returns 30 and updates (3,30) to freq 2
}
