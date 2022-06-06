class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      priority_queue <int> fuel;
      int stationIndex = 0 , range = startFuel;
      int refuel = 0;
      while(range < target) {
        while(stationIndex < stations.size() && range >= stations[stationIndex][0]){
            fuel.push(stations[stationIndex++][1]);
        }
        if(fuel.empty())return -1;
        range += fuel.top();
        fuel.pop();
        ++refuel;
      }
      return refuel;
    }
};