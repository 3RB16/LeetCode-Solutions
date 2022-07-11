class SmallestInfiniteSet {
public:
    set <int> have;
    SmallestInfiniteSet() {
     for(int i = 1;i <= 1000;i++)
        have.insert(i);
    }

    int popSmallest() {
        int response = *have.begin();
        have.erase(response);
        return response;
    }

    void addBack(int num) {
        have.insert(num);
    }
};