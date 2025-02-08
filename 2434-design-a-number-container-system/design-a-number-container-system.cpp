class NumberContainers {
public:
    map<int, set<int>> pos;
    map<int, int> indicies;
    NumberContainers() {
        pos.clear();
        indicies.clear();
    }
    
    void change(int index, int number) {
        if (indicies.find(index) != indicies.end()){
            int num = indicies[index];
            pos[num].erase(index);
        }
        pos[number].insert(index);
        indicies[index] = number;
    }
    
    int find(int number) {
        if(pos[number].size() == 0) {
            return -1;
        }
        int res = int(*pos[number].begin());
        return res;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */