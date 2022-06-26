class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set <string> foodItems;
        set <int> tablesNumber;
        map<string , map<string , int>> count;
        for(auto order : orders){
            int tableNum = stoi(order[1]);
            string food = order[2];
            foodItems.insert(food);
            tablesNumber.insert(tableNum);
            count[order[1]][food]++;
        }
        int m = (int)foodItems.size() + 1;
        int n = (int)tablesNumber.size() + 1;
        vector<vector<string>> display(n , vector<string>(m));
        display[0][0] = "Table";
        int index = 1;
        for(auto foodItem : foodItems){
            display[0][index++] = foodItem;
        }
        index = 1;
        for(auto tableNumber : tablesNumber){
            display[index++][0] = to_string(tableNumber);
        }
        for(int i = 1;i < n;i++){
         string currentTable = display[i][0];
         for(int j = 1;j < m;j++){
          string currentFood = display[0][j];
          display[i][j] = to_string(count[currentTable][currentFood]);
         }
        }
        return display;
    }
};
