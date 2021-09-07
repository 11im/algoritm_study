//https://leetcode.com/contest/weekly-contest-254/problems/number-of-strings-that-appear-as-substrings-in-word/

//pattern에 주어지는 문자들이 word에 주어지는 문자열에 substring으로 포함되는가??
//pattern에는 중복 가능하지만 word에는 중복X : {a,a,a}&abc = 3, {a}&aaaaaa = 1

#include <vector>
#include <string>

using namespace std;

public:
    int numOfStrings(vector<string>& patterns, string word) {
        
        int count = 0;

        for(int i = 0; i < patterns.size(); i++){
            string target = patterns[i];
            //std::string size_type find(const) -> const를 문자열에서 찾는 함수, 찾을 경우 시작 위치 return, else return npos ::npos = -1
            if(word.find(target) >= 0){
                count++;
                break;
            }
        }
        return count;
    }