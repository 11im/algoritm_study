//https://leetcode.com/contest/weekly-contest-250/problems/maximum-number-of-points-with-cost/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {

        queue<pair<int,int>> Q;
        int index, point;
        
        
        int n = points.size(); //n은 세로
        int m = points[0].size(); //m은 가로
        
        for(int i = 0; i < n; i++){
            index = point = 0;
            for(int j = 0; j < m; j++){
                if(points[i][j] > point){
                    index = j;
                    point = points[i][j];
                }
            }
            Q.push(make_pair(index, point));
        }
        
        int answer;
        int plus = Q.front().second;
        int minus = Q.front().first;
        Q.pop();

        while(!Q.empty()){
            plus += Q.front().second; //plus에는 point 합 저장
            answer = abs(minus - Q.front().first); //answer에 미리 빼야하는 index 저장
            minus = Q.front().first; //인접한 애들끼리 구해야하니까 minus에 index 업데이트
        }

        answer += plus;

        return answer;
    }
};