#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string largestOddNumber(string num) {

    /* ������ substring �� �� ����*/
    int index = 0;

    /*num ���� ���ϱ�*/
    int length = num.length();

    /*�ݺ��� : num �� �ڿ������� �� �ձ���*/
    for (int i = length - 1; i >= 0; --i) {
        /*target�� num �ڿ������� �� �ڸ��� ����*/
        char target = num.at(i);

        /*int�� ���� �� Ȧ/¦ �׽�Ʈ, Ȧ�̸� index�� i �����ϰ� break �ƴϸ� continue*/
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

