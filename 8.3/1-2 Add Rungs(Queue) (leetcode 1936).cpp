//https://leetcode.com/contest/weekly-contest-250/problems/add-minimum-number-of-rungs/
class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int count = 0;
        queue<int> Q;
        Q.push(0);

        for(int i = 0; i < rungs.size(); i++){
            int next = vector[i];
            int current = Q.front();
            if(current + dist < next){
                for(int j = 0; j < (next - current)/dist; j++){ //만약에 두 개 이상 추가해야하는 경우
                    Q.push(current + j * dist);
                    count++;
                }
            }
            Q.push(next);
        }

    return count;
    }
};