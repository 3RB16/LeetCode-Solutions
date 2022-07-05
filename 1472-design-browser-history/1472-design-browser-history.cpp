class BrowserHistory {
  public:
    unordered_map <int, string> history;
    int moves = 0, index = 0;
    BrowserHistory(string homepage) {
        moves = index = 0;
        history.clear();
        history[0] = homepage;
    }

    void visit(string url) {
        history[++moves] = url;
        index = moves;
    }

    string back(int steps) {
        moves -= steps;
        moves = max(moves , 0);
        return history[moves];
    }

    string forward(int steps) {
        moves += steps;
        moves = min(moves , index);
        return history[moves];
    }
};