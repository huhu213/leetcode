struct LRUNode {
    int key;
    int value;
    LRUNode(int k, int v) : key(k), value(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    //capacity
    int cap;
    //both side list, the most recently used item is always at the head
    std::list<LRUNode> nodes;
    std::unordered_map<int, std::list<LRUNode>::iterator> mp;
    

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        else {
            //move the item to the head
            nodes.splice(nodes.begin(), nodes, mp[key]);
            mp[key] = nodes.begin();
            return mp[key]->value;
        }
    }
    
    void set(int key, int value) {
        if(mp.find(key) == mp.end()) {
            if(nodes.size() == cap) {
                //remove the least recent used item
                mp.erase(nodes.back().key);
                nodes.pop_back();
            }
            //insert the new item
            nodes.push_front(LRUNode(key, value));
            mp[key] = nodes.begin();
        }
        else {
            mp[key]->value = value;
            nodes.splice(nodes.begin(), nodes, mp[key]);
            mp[key] = nodes.begin();
        }
    }

};