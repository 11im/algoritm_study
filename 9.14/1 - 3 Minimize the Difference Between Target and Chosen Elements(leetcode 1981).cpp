//https://leetcode.com/contest/weekly-contest-255/problems/minimize-the-difference-between-target-and-chosen-elements/

class Solution {
public:
    int n, m;
    int dp[71][4901];
    int solve(vector<vector<int>>&mat, int row, int sum, const int& target){
        //row와 입력 받은 mat의 row수인 m이 같을 경우
        if(row == m) return abs(sum - target);
        
        //이미 계산된 적 있는지
        if(dp[row][sum] != -1) return dp[row][sum];

        int mindiff = INT_MAX;
        //다음 줄을 돌면서 min 값 return
        for(int i = 0; i < n; i++){
            mindiff = min(mindiff, solve(mat, row + 1, sum + mat[row][i], target);
            return dp[row][sum] = mindiff;
        }

    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m = mat.length();
        n = mat[0].length();
        memset(dp, -1, sizeof(dp));
        solve(mat, 0, 0, target);
    }
};