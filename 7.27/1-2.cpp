// 7.27 https://leetcode.com/contest/weekly-contest-247/problems/cyclically-rotating-a-grid/
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.length; //m= x, n = y
        int n = grid[i].length;
        int numOfLayer = min(m/2,n/2); //num of layer         
        
        deque<int> Q;

        for(int layer = 0; layer < numOfLayer; layer++){
            int xMin = layer;
            int xMax = m - layer - 1;
            int yMin = layer;
            int yMax = n - layer -1;

            //read
            for(int x1 = xMin; x1 < xMAX; x1++){ 
                Q.push_back(grid[x1][yMin]);
            }

            for(int y1 = yMin; y1 < yMax; y1++){
                Q.push_back(grid[xMax][y1]);
            }
            for(int x2 = xMmx; x2 > xMin; x2--){
                Q.push_back(grid[x2][yMax]);
            }
            for(int y2 = yMax; y2 > yMin; y2--){
                Q.push_back(grid[xMax][y2]);
            }
            //rotate
            for(int count = 0; count < k; count++){
                int first = Q.front();
                Q.push_back(first);
                Q.pop_front();
            }
            
            //write
            for(int x1 = xMin; x1 < xMAX; x1++){ 
                grid[x1][yMin] = Q.front();
                Q.pop_front();
            }

            for(int y1 = yMin; y1 < yMax; y1++){
                grid[xMax][y1] = Q.front();
                Q.pop_front();
            }
            for(int x2 = xMmx; x2 > xMin; x2--){
               grid[x2][yMax] = Q.front();
               Q.pop_front();
            }
            for(int y2 = yMax; y2 > yMin; y2--){
                grid[xMax][y2] = Q.front();
                Q.pop_front();
            }
        }
    }
};