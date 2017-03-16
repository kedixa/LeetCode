class LRUCache {
    // list<int> L 保存最近访问的key，越靠前的key访问时间越近
    list<int> L;
    // unordered_map um保存键值信息<key, <value, iterator>>
    // 其中iterator是L中key对应的结点的迭代器
    unordered_map<int, pair<int, list<int>::iterator>> um;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = um.find(key);
        // 如果key不在cache中，返回-1
        if(it == um.end()) return -1;
        
        // 如果key在，将访问时间提到最前，返回value
        auto lit = it->second.second; // list<int>::iterator
        L.erase(lit);
        L.push_front(key);
        it->second.second = L.begin();
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = um.find(key);
        // 如果key不在cache中
        if(it == um.end())
        {
            // 若cache 满了，则删除一个最早访问的key
            if(um.size() == cap)
            {
                int delete_key = L.back();
                L.pop_back();
                um.erase(delete_key);
            }
            // 把key插入到最近访问的位置
            L.push_front(key);
            um.insert(make_pair(key, make_pair(value, L.begin())));
        }
        // 如果key在cache 中，则更新value，并将访问时间提前
        else
        {
            auto lit = it->second.second;
            L.erase(lit);
            L.push_front(key);
            it->second = make_pair(value, L.begin());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 