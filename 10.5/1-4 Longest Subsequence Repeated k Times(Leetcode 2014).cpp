//https://leetcode.com/contest/weekly-contest-259/problems/longest-subsequence-repeated-k-times/

//string s, length n, int k, find longest subsequence repeated k times in string s



class Solution {
public:
    string best_case;

    int count_case(string sub, string s){
        if(sub.length() == 0) return s.length();
        int index = 0;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(sub[index] = s[i]){//if sub[index] matches;
                index++;
                //if the whole substiring matches, count++, index reset;
                if(ind == sub.length()){
                    index = 0;
                    count++;
                }
            }
        }
        return count;
    }
    
    void recur(stirng sub, string s, int k){
        if(count_case(sub, s) < k) return; //if it does not work;
        if(sub.length() >= best_case.length() && sub > best_case) best_case = sub;//better case
        for(char c = 'a'; c <= 'z'; c++) recur(sub + c, s, k); //add some string to sub and recur
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        rec("", s, k);
        return best_case;
    }
};