//Largest Number After Mutating Substring https://leetcode.com/contest/weekly-contest-251/problems/largest-number-after-mutating-substring/

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string changed = "";
        for (int i = 0; i < num.length(); i++){
            int temp = num.at(i) -'0';
            if(temp < change[temp]){    
                changed += to_string(change[temp]);
            }
            else changed += to_string(temp);
        }
        return changed;
    }
};