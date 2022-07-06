class StockPrice {
public:
    multiset <int> count;
    map<int , int> last;
    StockPrice() {
       count.clear();
       last.clear();
    }
    
    void update(int timestamp, int price) {
     if(last.count(timestamp))
         count.erase(count.find(last[timestamp]));
      last[timestamp] = price;
      count.insert(price);
    }
    
    int current() {
       return last.rbegin()->second;
    }
    
    int maximum() {
      return *count.rbegin();
    }
    
    int minimum() {
       return *count.begin(); 
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */