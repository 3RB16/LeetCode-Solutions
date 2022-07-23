class NumberContainers {
public:
    map<int , set<int>> container;
    map<int , int> idx;
    NumberContainers() {
        container.clear();
    }

    void change(int index, int number) {
        if(idx.find(index) != idx.end()){
            container[idx[index]].erase(index);
        }
        idx[index] = number;
        container[number].insert(index);
    }

    int find(int number) {
        return container[number].empty() ? -1 : *container[number].begin();
    }
};