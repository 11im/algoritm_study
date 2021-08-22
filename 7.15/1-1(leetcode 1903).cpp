#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string largestOddNumber(string num) {

    /* 어디까지 substring 할 지 저장*/
    int index = 0;

    /*num 길이 구하기*/
    int length = num.length();

    /*반복문 : num 맨 뒤에서부터 맨 앞까지*/
    for (int i = length - 1; i >= 0; --i) {
        /*target에 num 뒤에서부터 한 자리씩 저장*/
        char target = num.at(i);

        /*int로 변경 후 홀/짝 테스트, 홀이면 index에 i 저장하고 break 아니면 continue*/
        int int_target = (int)target;
        if (int_target % 2 == 1) {
            index = i+1;
            break;
        }
    }

    string answer = num.substr(0, index);
    return answer;
}

void main() {
    string a = largestOddNumber("12345678");
    printf("%s", a.c_str());
}

