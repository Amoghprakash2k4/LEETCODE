class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // stores (key, value)
    unordered_map<int, list<pair<int, int>>::iterator> map; // key -> iterator in list

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // If not found, return -1
        if (map.find(key) == map.end()) {
            return -1;
        }

        // Move this node to the front (most recently used)
        auto it = map[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});
        map[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        // If key already exists, remove old node
        if (map.find(key) != map.end()) {
            cache.erase(map[key]);
        }

        // Insert new node at front
        cache.push_front({key, value});
        map[key] = cache.begin();

        // If over capacity, remove least recently used (last)
        if (cache.size() > capacity) {
            auto last = cache.end();
            last--;
            int keyToRemove = last->first;
            cache.pop_back();
            map.erase(keyToRemove);
        }
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */