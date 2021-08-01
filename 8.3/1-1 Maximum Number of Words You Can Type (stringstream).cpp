// https://leetcode.com/contest/weekly-contest-250/problems/maximum-number-of-words-you-can-type/
class Solution {
public:
    bool canBeTypedWords(string text, string brokenLetters) {
        
        int Check(string text, int temp[]){
            for(auto x:text){
               int count = x - 'a';
               if(temp[count] > 0) {
                   return false;
               }   
            }
            return true;
        }

        int answer = 0;
        stringstream temp(text);
        string word;
        int hash[26] = 0;

        for(char c :brokenLetters){
            int x = c - 'a';
            hash[x]++;
        }

        while(temp >> word){
            if(Check(word,hash)){
                answer++;
            }
        }

        return answer;
    }
};