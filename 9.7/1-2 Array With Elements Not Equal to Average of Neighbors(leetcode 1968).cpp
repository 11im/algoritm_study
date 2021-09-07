//https://leetcode.com/contest/weekly-contest-254/problems/array-with-elements-not-equal-to-average-of-neighbors/

//주어진 nums에서 인자들의 순서를 바꿔서 nums[i] != (nums[i-1] + nums[i+1]) / 2 되도록


public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //정렬
        sort(nums.begin(), nums.end());

        //[1, 2, 3, 4] -> [2, 1, 3, 4] - > [2, 1, 4, 3];
        for(int i = 0; i < nums.size() - 1; i+=2){
            swap(nums[i], nums[i+1]);
        }
        return nums;
    }