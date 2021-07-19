//7.20 1-1 1920. Build Array from Permutation https://leetcode.com/contest/weekly-contest-248/problems/build-array-from-permutation/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vecotr<int> ans;
        for(int i = 0; i < sizeof(nums); i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};