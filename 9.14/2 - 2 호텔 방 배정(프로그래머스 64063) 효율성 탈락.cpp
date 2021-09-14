//https://programmers.co.kr/learn/courses/30/lessons/64063
//방 개수 k개, k <= 10^12 자연수, room number 크기는 1:200,000, 

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    set<long long> S;
    for(int i = 0; i < room_number.size(); i++){
        long long temp = room_number[i];

        if(S.find(temp) == S.end()){
            S.insert(temp);
            answer.push_back(temp);
        }

        else{
            while(S.find(temp) != S.end()){
                temp++;
            }
            S.insert(temp);
            answer.push_back(temp);
        }
    }
    
    return answer;
}