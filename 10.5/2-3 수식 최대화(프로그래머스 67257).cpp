//https://programmers.co.kr/learn/courses/30/lessons/67257
// + - * 만으로 이루어진 수식, 가장 큰 숫자 제출;
// 우선순위 정하기, 우선 순위는 한 번에 하나만;
// 절댓값으로 변환 제출;

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> Operation;
vector<long long> Num;
vector<char> Oper_List = {'*', '+', '-'};

long long calc(long long a, long long b, char op){
    if(op == '*'){
        return a * b;
    }
    else if(op == '+'){
        return a + b;
    }
    else return a - b;
}

long long solution(string expression) {
    string num = "";
    for(int i = 0; i < expression.length(); i++){
        if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-'){
           Operation.push_back(expression[i]);
           Num.push_back(atoi(num.c_str()));
           num = "";
        }
        else num += expression[i];
    }
    Num.push_back(atoi(num.c_str()));
    long long max = 0;
    do{
        vector<char> temp_oper = Operation;
        vector<long long> temp_num = Num;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < temp_oper.size(); j++){
                if(temp_oper[j] == Oper_List[i]){
                    temp_num[j] = calc(temp_num[j], temp_num[j + 1], Oper_List[i]);
                    temp_num.erase(temp_num.begin() + j + 1);
                    temp_oper.erase(temp_oper.begin() + j);
                    j--;
                }
            }
        }
        if(max < abs(temp_num[0])) max = abs(temp_num[0]);
    }while(next_permutation(Oper_List.begin(), Oper_List.end()));

    return max;
}