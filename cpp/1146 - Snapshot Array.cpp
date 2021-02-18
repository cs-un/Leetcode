class SnapshotArray {
public:
    vector<map<int, int>> snapshot{};
    int curr;
    
    SnapshotArray(int length) {
        for(auto i{0}; i < length; ++i)
        {
            snapshot.push_back({{0, 0}});
        }
        curr = 0;
    }
    
    void set(int index, int val) {
        snapshot[index][curr] = val;
    }
    
    int snap() {
        return curr++;
    }
    
    int get(int index, int snap_id) {
        auto it = snapshot[index].upper_bound(snap_id);
        return prev(it)->second;
    }
};