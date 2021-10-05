//https://leetcode.com/contest/weekly-contest-259/problems/sum-of-beauty-in-the-array/

// 1 <= i <= nums.length - 2
// 2  :  nums[j]<nums[i]<nums[k]    all 0 <= j < i < k <= nums.length - 1
// 1  :  nums[i-a] < nums[i] < nums[i+1]
// 0  :  둘 다 아님

//일단 작성
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int beauty = 0;
        for(int i = 1; i <= nums.size() - 2; i++){
            for(int j = 0; j < i; j++){
               for(int k = i + 1; k <= nums.size() - 1; k++){
                    if(nums[j] < nums[i] && nums[i] < nums[k]) {
                        if(j = i - 1 && k = nums.size() - 1) beauty += 2;
                        else continue;
                    }
                    else break;
                }
            }
            if(nums[i-1] < nums[i] < nums[i+1]) beauty += 1;
        }
        return beauty;
    }
};



// 좌 우 나눠서
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int size = nums.size();
        vector<int> right(n);
        right[n-1] = nums[size -1];
        int left = nums[0];
        int beauty = 0;

        for(int i = n - 2; i >= 0; i--){
            post[n - 1] = min(post[i + 1], nums[i]);
        }
        
        for(int i = 1; i < size - 2; i++){
            if(nums[i] > left && nums[i] < right[i + 1]) beauty += 2;
            else if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) beauty += 1;
            left = max(left, nums[i]);
        }

        return beauty;
    }
};