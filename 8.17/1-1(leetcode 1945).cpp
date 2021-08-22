//Sum of Digits of String After Convert https://leetcode.com/contest/weekly-contest-251/problems/sum-of-digits-of-string-after-convert/
class Solution {
public:
    int getLucky(string s, int k) {
             
        string temp = "";
        for(int i = 0 ; i < s.length(); i++){
            int x = s.at(i) - 'a' + 1;
            temp += to_string(x);
        }
        while(k--){
            int sum = 0;
            for(i = 0; i < temp.length(); i++){
                int y = temp.at(i) - '0';
                sum += y;
            }
            temp = to_string(sum);
        }
        int answer = stoi(temp);
        return answer;
    }
};