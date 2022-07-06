class StockPrice {
public:
    multiset <int> count;
    map<int , int> seen;
    StockPrice() {
       count.clear() , seen.clear();
    }
    
    void update(int timestamp, int price) {
     if(seen.count(timestamp))
         count.erase(count.find(seen[timestamp]));
      seen[timestamp] = price;
      count.insert(price);
    }
    
    int current() {
       return seen.rbegin()->second;
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