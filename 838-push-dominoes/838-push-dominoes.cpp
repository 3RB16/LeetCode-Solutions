class Solution {
  public:
    string pushDominoes(string dominoes) {
        int N = dominoes.size();
        queue<int> todo;
        vector<int> fallLevel(N, -1);
        for (int i = 0; i < N; i++) {
            if (dominoes[i] != '.') {
                todo.push(i);
                fallLevel[i] = 0;
            }
        }
        auto is_static = [&](int index) -> bool{
            return index >= 0 and index < N and dominoes[index] == '.';
        };
        while (!todo.empty()) {
            int curIndex = todo.front();
            todo.pop();
            if (dominoes[curIndex] == 'L') {
                if (is_static(curIndex - 1)) {
                    todo.push(curIndex - 1);
                    dominoes[curIndex - 1] = 'L';
                    fallLevel[curIndex - 1] = fallLevel[curIndex] + 1;
                }
            } else if (dominoes[curIndex] == 'R') {
                if (is_static(curIndex + 1)) {
                    todo.push(curIndex + 1);
                    dominoes[curIndex + 1] = 'R';
                    fallLevel[curIndex + 1] = fallLevel[curIndex] + 1;
                }
            }
        }
        for (int i = 1; i < N - 1; i++) {
            if (fallLevel[i - 1] == fallLevel[i + 1] && fallLevel[i] != 0 && dominoes[i - 1] != dominoes[i + 1]) {
                dominoes[i] = '.';
            }
        }
        return dominoes;
    }
};