class MyCalendar {
public:
    map<int , int> events;
    MyCalendar() {
     events.clear();   
    }
    
    bool book(int start, int end) {
      auto next = events.upper_bound(start);
      if(next == events.end() || end <= next->second){
         events[end] = start; 
         return true;
      } else {
        return false;
      }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */