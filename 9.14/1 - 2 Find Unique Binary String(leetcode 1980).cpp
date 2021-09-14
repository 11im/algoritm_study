//https://leetcode.com/contest/weekly-contest-255/problems/find-unique-binary-string/

//nums를 2차원 배열이라고 생각한다면 대각선에 있는 element들의 반대를 쭉 이어준다면 nums에 없는 binary가 될 것

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i][i] = '0') s += '1';
            else s += '0';
        }
        return s;
    }
};