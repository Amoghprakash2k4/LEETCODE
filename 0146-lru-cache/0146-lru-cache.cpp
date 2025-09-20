// class LRUCache {
// private:
//     int capacity;
//     list<pair<int, int>> cache; // stores {key, value}
//     unordered_map<int, list<pair<int, int>>::iterator> map;

// public:
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//     }

//     int get(int key) {
//         auto it = map.find(key);
//         if (it == map.end()) return -1; // not found

//         // Move the accessed node to the front (most recently used)
//         cache.splice(cache.begin(), cache, it->second);
//         return it->second->second; // return value
//     }

//     void put(int key, int value) {
//         auto it = map.find(key);

//         if (it != map.end()) {
//             // Update the value and move to front
//             it->second->second = value;
//             cache.splice(cache.begin(), cache, it->second);
//         } else {
//             // If cache is full, remove least recently used
//             if (cache.size() == capacity) {
//                 auto lru = cache.back();
//                 map.erase(lru.first);
//                 cache.pop_back();
//             }
//             // Insert new node at front
//             cache.emplace_front(key, value);
//             map[key] = cache.begin();
//         }
//     }
// };



class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> map;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if(it == map.end()) return -1;

        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if(it != map.end())
        {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
        }
        else{
            if( cache.size() == capacity){
                auto lru =  cache.back();
                map.erase(lru.first);
                cache.pop_back();

            }
            cache.emplace_front(key, value);
            map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
