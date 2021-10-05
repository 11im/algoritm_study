//https://programmers.co.kr/learn/courses/30/lessons/64062

//정확성, 효율성
//징검다리 일렬, 디딤돌에 숫자, 한 번 밟을 때 마다 --;
//숫자 = 0; 밟을 수 없음, 그 다음 디딤돌로 여러 칸 건널 수 있음;
//다음으로 밟을 수 있는 디딤돌 중 가장 가까운 디딤돌로;
//개울 왼쪽 -> 오른쪽, 한 번에 한 명씩, 다 건너야 다음 사람;
//디딤돌 배열 stones, 한 번에 건널 수 있는 최대 칸수 k, 최대 몇 명이 건널 수 있는지 return; 

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int min_stone, start, finish;
vector<pair<int,int>> index_stones;

int solve(vector<pair<int,int>> temp, int max){
    vector<pair<int,int>> temp_stones;
    vector<int> non_zero_stones;

    int min = temp[0].first;
    min_stone += min;
    bool flag = true;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i].first - min != 0){
            temp_stones.push_back(make_pair(temp[i].first - min, temp[i].second));
            non_zero_stones.push_back(temp[i].second);
        }
    }
    if(non_zero_stones.size() > 1){
        sort(non_zero_stones.begin(), non_zero_stones.end());
        for(int i = non_zero_stones.size() -1; i > 0; i--){
            if(non_zero_stones.at(i) - non_zero_stones.at(i - 1) > max){
                flag = false;
                break;
            }
        }
    }
    
    if(non_zero_stones.at(0) > max){
        flag = false;
    }
    else if(non_zero_stones.at(non_zero_stones.size() - 1) < finish - max){
        flag = false;
    }

    if(flag == true) return solve(temp_stones, max);
    else return min_stone;
}

int solution(vector<int> stones, int k) {
    finish = stones.size();
    start = 0;
    for(int i = 0; i < stones.size(); i++){
        index_stones.push_back(make_pair(stones[i], i + 1));
    }

    sort(index_stones.begin(), index_stones.end());

    solve(index_stones, k);
    return min_stone;
}