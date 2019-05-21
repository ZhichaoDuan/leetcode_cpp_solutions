class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        int res = -1;
        unordered_map<int, list<pair<int, int> >::iterator>::iterator it = cachesMap.find(key);
        if (it!=cachesMap.end()) {
            res = it->second->second;
            list<pair<int, int> >::iterator iter = it->second;
            pair<int, int> t_pair = *iter;
            caches.erase(iter);
            caches.push_front(t_pair);
            cachesMap[key] = caches.begin();
        }
        return res;
    }

    void put(int key, int value) {
        unordered_map<int, list<pair<int,int> >::iterator>::iterator it = cachesMap.find(key);
        if (it!=cachesMap.end()) {
            list<pair<int, int> >::iterator iter = it->second;
            iter->second = value;
            pair<int, int> t_pair = *iter;
            caches.erase(iter);
            caches.push_front(t_pair);
            cachesMap[key] = caches.begin();
        }
        else {
            pair<int, int> t_pair = make_pair(key, value);
            if (this->capacity==caches.size()) {
                int del_key = caches.back().first;
                caches.pop_back();
                unordered_map<int, list<pair<int, int> >::iterator>::iterator delIt = cachesMap.find(del_key);
                cachesMap.erase(delIt);
            }

            caches.push_front(t_pair);
            cachesMap[key] = caches.begin();
        }
    }
private:
    int capacity;
    list<pair<int, int>> caches;
    unordered_map<int, list<pair<int, int> >::iterator> cachesMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
