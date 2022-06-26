class Solution {
    unordered_map<char, int> frequency;
    bool is_valid() {
        return (frequency['c'] >= frequency['r']) &&
               (frequency['r'] >= frequency['o']) &&
               (frequency['o'] >= frequency['a']) &&
               (frequency['a'] >= frequency['k']);
    }

  public:
    int minNumberOfFrogs(string croakSequence) {
        int numCroakingFrogs = 0;
        int answer = 0;
        for (char &sound: croakSequence) {
            frequency[sound]++;
            if (!is_valid()) {
                return -1;
            }
            if (sound == 'c') {
                numCroakingFrogs++;
            } else if (sound == 'k') {
                numCroakingFrogs--;
            }
            answer = max(answer, numCroakingFrogs);
        }
        return numCroakingFrogs == 0 ? answer : -1;
    }
};
