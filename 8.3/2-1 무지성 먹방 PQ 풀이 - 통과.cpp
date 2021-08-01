//2-1 https://programmers.co.kr/learn/courses/30/lessons/42891?language=cpp
//참고 https://mungto.tistory.com/9
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    
    priority_queue<pair<int,int>> PQ;
    long long total_time = 0;
    
    for(int i = 0; i < food_times.size(); i++){ //PQ에 남은 시간이 작은 순서대로 입력
        PQ.push(make_pair(-food_times[i], (i + 1)));
        total_time += food_times[i];
    }
    
    if(total_time <= k) return -1;//전체 시간 합이 k보다 작거나 같으면
    
    long long before = 0;
    while(k >= -(PQ.top().first - before) * PQ.size()){ //중요! 남은 시간이 제일 작은 음식의 남은 시간은 이전에 다 먹은 음식 시간만큼 뺴야함
        k += (PQ.top().first - before) * PQ.size();
        before = PQ.top().first;
        PQ.pop();
    }

    vector<int> Sorted; //음식 번호만 넣을 vector

    while(!PQ.empty()){
        Sorted.push_back(PQ.top().second);
        PQ.pop();
    }

    sort(Sorted.begin(), Sorted.end()); //음식 번호대로 정렬

    int answer = Sorted[k % Sorted.size()]; //전체 음식 수 만큼 돌고 남은 만큼 추가 회전 : 몫이 아니라 나머지
    return answer;
}
