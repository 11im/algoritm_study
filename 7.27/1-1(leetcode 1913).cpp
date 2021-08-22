// 7.27 https://leetcode.com/contest/weekly-contest-247/problems/maximum-product-difference-between-two-pairs/

#include <iostream>
#include <alogorithm>

using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max, min;
        int size = sizeof(nums);

        sort(nums,nums+size);
        min = nums[0]*nums[1];
        max = nums[size-2]*nums[size-1];

        return max - min;
    }
};