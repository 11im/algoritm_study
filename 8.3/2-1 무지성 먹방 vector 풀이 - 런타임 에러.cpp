//2-1 https://programmers.co.kr/learn/courses/30/lessons/42891?language=cpp
#include <string>
#include <vector>

using namespace std;

//foodtime[i]에서 i는 음식 번호, foodtime[i]의 값은 음식의 시간, k는 방송이 정지된 시간
int solution(vector<int> food_times, long long k) {
    


    int answer = 0;
    long long temp = k;
    bool flag = true;

    for(int i = 0; i < food_times.size(); i++){ //남은 음식 시간 합이 입력된 시간 k보다 작으면 flag는 false
        temp - food_times[i];
        if(temp <= 0){
            flag = false;
            break;
        }
    }

    if(flag == true){ //한 바퀴 돌면서 음식 먹기
        int temp = 1;
        while(k){
            for(int i = 0; i < food_times.size(); i++){
                if(k == 0){
                    break;
                }

                int food = food_times[i];
                
                if(food > 0){ //남은 시간 -1
                    food_times.erase(i);
                    food_times.insert(i,food - 1);
                    k--;
                }

                temp = i + 1; //temp는 음식 순서
            }
        }
        answer = temp
    }
    else answer = -1;
  
    return answer;
}