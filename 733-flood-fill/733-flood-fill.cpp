class Solution {
public:
bool visited[55][55];

void flood(int i , int j , vector<vector<int>> &image , int newColor , int originalColor) {
  int m = image.size();
  int n = image[0].size();
  if(i < 0 || j < 0 || j >= n || i >= m)return;
  if(visited[i][j] || image[i][j] != originalColor)return;
  visited[i][j] = 1;
  image[i][j] = newColor;
  flood(i + 1 , j , image , newColor , originalColor);
  flood(i, j + 1 , image , newColor , originalColor);
  flood(i - 1 , j , image , newColor , originalColor);
  flood(i, j - 1, image , newColor , originalColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
  memset(visited , false , sizeof visited);
  flood(sr , sc , image , newColor , image[sr][sc]);
  return image;
 }
};