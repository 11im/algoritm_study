//https://leetcode.com/contest/weekly-contest-255/problems/find-greatest-common-divisor-of-array/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int smallest = nums[0];
        int largest = nums[sunms.size() - 1];

        for(int i = smallest; i >= smallest; i--){
            if(smallest % i == 0 && largest % i == 0){
                return i;
            }
        }
    }
};