// 7.20 1921. Eliminate Maximum Number of Monsters https://leetcode.com/contest/weekly-contest-248/problems/eliminate-maximum-number-of-monsters/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dist;
vector<int> speed;
int count = 0;
priority_queue<int> PQ;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for(int i = 0; i < dist.size(); i++){
            PQ.push(-dist[i]/speed[i]);
        }
        while(!PQ.empty()){
            int kill = -PQ.top() - count;
            if(kill > 0) count++;
            else break;
        }
        return count;
    }
};