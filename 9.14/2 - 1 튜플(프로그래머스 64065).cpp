//https://programmers.co.kr/learn/courses/30/lessons/64065

//규칙 - 중복 가능, 순서 있음, 원소 개수 유한
//중복되는 원소가 없는 경우 {}로 묶어서 표현 가능 - 순서가 바뀌어도 같은 튜플을 나타냄
// s는 튜플 표현 집함 : s가 표현하는 튜플을 return 하는 solution 함수 작성

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> temp;
    vector<pair<int,vector<int>>> V;
    
    int size = s.size();
    int num = 0;

    for(int i = 1; i<size - 1; i++){
        if(s[i] == '{') continue;
        if(s[i] == '}'){
            temp.push_back(num);
            V.push_back(make_pair(temp.size(), temp));

            num = 0;
            temp.clear();
        }
        else if(s[i] == ','){
            if(s[i-1] == '}') continue;
            temp.push_back(num);
            num = 0;
        }
        else{
            num *= 10;
            num +=(s[i] - '0');
        }
    }

    sort(V.begin(), V.end());
    set<int> res;
    for(pair<int, vector<int>> p : V){
        for(int num : p.second){
            if(res.find(num) == res.end()){
                res.insert(num);
                answer.push_back(num);
            }
        }
    }

    return answer;
}