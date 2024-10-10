class LRUCache {
public:
    map<int , list<pair<int , int>> ::iterator> cache;
    list<pair<int , int>> lru;
    int cap;
    LRUCache(int capacity) {
      cap = capacity;
    }
    
    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;
        }
        auto it = cache[key];
        auto [_key, val] = *it;

        lru.erase(it);
        lru.push_front({_key, val});
        cache[_key] = lru.begin();

        return val;
    }
    
    void put(int key, int value) {
        // update key
        if (cache.count(key) > 0) {
            auto it = cache[key];
            auto [_key, val] = *it;

            cache.erase(key);
            lru.erase(it);

            lru.push_front({key, value});
            cache[key] = lru.begin();
            return;
        } 
        if (lru.size() == cap) {
            auto it = lru.back();
            cache.erase(it.first);
            lru.pop_back();
        }
        lru.push_front({key,value});
        cache[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */