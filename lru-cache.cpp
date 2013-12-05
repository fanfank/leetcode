struct node {
    int value, count;
    node(int v, int c) : value(v), count(c) {}
};
class LRUCache{//a way to improve effeiciency is to use list rather than map to store count numbers. and use hashtable
public:
    int count, cap, sz;
    map<int, int> ck;
    map<int, node> kv;
    LRUCache(int capacity) : count(0x80000000), cap(capacity), sz(0){
        
    }
    
    int get(int key) {
        if(cap <= 0)
            return -1;
        map<int, node>::iterator p = kv.find(key);
        if(p != kv.end()) {
            ++count;
            ck.erase(p->second.count);
            p->second.count = count;
            ck.insert(pair<int, int>(count, key));
            return p->second.value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if(cap <= 0)
            return;
        ++count;
        map<int, node>::iterator p = kv.find(key);
        if(p != kv.end()) {
            ck.erase(p->second.count);
            p->second.count = count;
            ck.insert(pair<int, int>(count, key));
            p->second.value = value;
        } else {
            if(sz < cap) {
                kv.insert(pair<int, node>(key, node(value, count)));
                ck.insert(pair<int, int>(count ,key));
                ++sz;
            } else {
                int tmpKey = ck.begin()->second;
                kv.erase(tmpKey);
                ck.erase(ck.begin());
                kv.insert(pair<int, node>(key, node(value, count)));
                ck.insert(pair<int, int>(count ,key));
            }
        }
    }
};