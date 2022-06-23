#include <vector>
using namespace std;

class MyHashSet {
private:
    vector<vector<int>> table;
    int hash(int key) {
        return key % (int)1e6;
    }
public:
    MyHashSet() {
        table.resize(1e6);
    }
    
    void add(int key) {
        if (contains(key))
            return;
        int k = hash(key);
        table[k].push_back(key);
    }
    
    void remove(int key) {
        int k = hash(key);
        int pos;
        for (pos = 0; pos < table[k].size(); pos++) {
            if (table[k][pos] == key)
                break;
        }
        if (pos == table[k].size())
            return;
        if (pos != table[k].size() - 1)
            swap(table[k][pos], table[k][table[k].size() - 1]);
        table[k].pop_back();
    }
    
    bool contains(int key) {
        int k = hash(key);
        for (int i = 0; i < table[k].size(); i++) {
            if (table[k][i] == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */