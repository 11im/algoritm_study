////https://programmers.co.kr/learn/courses/30/lessons/64063
//union-find로 효율성 통과 : map<현재 번호, 부모 번호> -> 부모 번호는 +1 해서 다음 빈 방을 가리키도록

#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> M;

long long NextEmptyRoom(long long num){
    if(M[num] == 0) return num;
    else return M[num] = NextEmptyRoom(M[num]);
}


vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for(long long i : room_number){
        long long EmptyRoom = NextEmptyRoom(i);
        answer.push_back(EmptyRoom);
        M[EmptyRoom] = EmptyRoom + 1;
    }

    return answer;
}