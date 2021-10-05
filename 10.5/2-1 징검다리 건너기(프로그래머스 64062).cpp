//https://programmers.co.kr/learn/courses/30/lessons/64062

//이분 탐색 : 탐색 기준 = 디딤 돌을 밟을 수 있는 횟수
//binary search 조건 : 0인 디딤돌이 연속되는 횟수가 k 보다 큰 경우 last = mid -1
//연속되는 횟수가 k 보다 작은 경우 first = mid + 1

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(int&n, int&k, vector<int>& v){
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] - n <= 0) count++;
        else count = 0;
        if(count >= k) return true;
    }
    return false;
}


int solution(vector<int> stones, int k) {
    int first = 1;
    int last = *max_element(stones.begin(), stones.end());

    while(first <= last){
        int mid = (first + last) / 2;
        if(binary_search(mid, k, stones)){
            last = mid - 1;
        }
        else first = mid +1;
    }

    return first;
}