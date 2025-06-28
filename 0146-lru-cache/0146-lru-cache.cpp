class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1; // not found
        }
        // Move the accessed node to the front
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            // Update value
            it->second->second = value;
            // Move to front
            cache.splice(cache.begin(), cache, it->second);
        } else {
            // Insert new node
            cache.emplace_front(key, value);
            map[key] = cache.begin();
            if (cache.size() > capacity) {
                // Remove least recently used
                auto last = cache.end();
                last--;
                map.erase(last->first);
                cache.pop_back();
            }
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */