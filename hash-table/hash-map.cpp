#include <vector>
using namespace std;

class MyHashMap {
private:
    struct keyval {
        int key;
        int value;
        keyval(int k, int v) : key(k), value(v) {};
    };
    vector<vector<keyval>> table;
    int hash(int key) {
        return key % (int)1e5;
    }
public:
    MyHashMap() {
        table.resize(1e5);
    }
    
    void put(int key, int value) {
        int k = hash(key);
        for (int i = 0; i < table[k].size(); i++) {
            if (table[k][i].key == key) {
                table[k][i].value = value;
                return;
            }
        }
        table[k].push_back(keyval(key, value));
    }
    
    int get(int key) {
        int k = hash(key);
        for (int i = 0; i < table[k].size(); i++) {
            if (table[k][i].key == key)
                return table[k][i].value;
        }
        return -1;
    }
    
    void remove(int key) {
        int k = hash(key);
        int i;
        for (i = 0; i < table[k].size(); i++) {
            if (table[k][i].key == key)
                break;
        }
        if (i == table[k].size())
            return;
        if (i != table[k].size() - 1)
            swap(table[k][i], table[k].back());
        table[k].pop_back();
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */