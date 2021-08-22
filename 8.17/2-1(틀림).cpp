//구간 합 구하기 https://www.acmicpc.net/problem/2042
#include <iostream>
#include <deque>
#include <vector>

#define MAX 1000001

using namespace std;

int N, M, K;
long long Answer; //n은 수의 개수, m은 변경 횟수, k는 구간합 횟수
//2 ~ n+1까지 숫자, n+2 ~ n+m+k+1까지 a,b,c: a = 1이면 b 번째 수를 c로 바꿈, a = 2 이면 b부터 c까지 합
vector<long long> V;
deque<vector<long long>> DQ;
long long Array[MAX];

void Input(){
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        cin >> Array[i];
    }

    for(int i = 0; i < M+K; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        V.push_back(a);
        V.push_back(b);
        V.push_back(c);
        DQ.push_back(V);
        V.clear();
    }

    return;
}

void Change(int idx, long long num){
    Array[idx] = num;
    return;
}

int Sum(int start, int end){
    long long sum = 0;
    for(int i = start - 1; i < end; i++){
        sum += Array[i];
    }
    return sum;
}

int main(){
    Input();
    for(int i = 0; i < DQ.size(); i++){
        V = DQ.front();
        DQ.pop_front();

        if(V[0] == 1){
            Change(V[1],V[2]);
        }
        
        else if(V[0] == 2){
            Answer = Sum(V[1],V[2]);
            cout << Answer << endl;
        }
    }
    return 0;
}