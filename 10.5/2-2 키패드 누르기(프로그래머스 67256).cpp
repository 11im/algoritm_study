//https://programmers.co.kr/learn/courses/30/lessons/67256
//왼손 엄지 *, 오른 손 엄지 #
//상하좌우 이동 가능, 이동 1칸 = 시간 1
//1, 4, 7은 왼손 고정, 3, 6, 9는 오른손 고정, 2, 5, 8, 0은 가까운 손, 거리가 같으면 오른손 잡이는 오른손, 왼손잡이는 왼손
//매개 변수 : 누를 번호 numbers, 왼손/오른손 잡이 hand
//반환 : 번호를 누를 손 순서

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, pair<int,int>> phone;

string what_hand(vector<int>& v, string temp, int hand){
    int right = 12;
    int left = 11;
    
    for(int i = 0; i < v.size(); i++){
        int num = v.at(i);
        if(num == 3 || num == 6 || num == 9){
            right = num;
            temp += "R";
        }
        else if(num == 1 || num == 4 || num == 7){
            left = num;
            temp += "L";
        }
        else{
            int num_x = phone.find(num)->second.first;
            int num_y = phone.find(num)->second.second;
            int r_x = phone.find(right)->second.first;
            int r_y = phone.find(right)->second.second;
            int l_x = phone.find(left)->second.first;
            int l_y = phone.find(left)->second.second;

            int r_count = abs(num_x - r_x) + abs(num_y - r_y);
            int l_count = abs(num_x - l_x) + abs(num_y - l_y);
            
            //오른손 잡이
            if(hand == 1){
                if(r_count <= l_count){
                    temp += "R";
                    right = num;
                } 
                else{
                    temp += "L";
                    left = num;
                } 
            }
            else{
                if(l_count <= r_count){
                    temp += "L";
                    left = num;
                }
                else{
                    temp += "R";
                    right = num;
                }
            }
        }
    }
    return temp;
}

string solution(vector<int> numbers, string hand) {
    //11은 *, 12는 #
    phone.insert(make_pair(1, make_pair(1,4)));
    phone.insert(make_pair(2, make_pair(2,4)));
    phone.insert(make_pair(3, make_pair(3,4)));
    phone.insert(make_pair(4, make_pair(1,3)));
    phone.insert(make_pair(5, make_pair(2,3)));
    phone.insert(make_pair(6, make_pair(3,3)));
    phone.insert(make_pair(7, make_pair(1,2)));
    phone.insert(make_pair(8, make_pair(2,2)));
    phone.insert(make_pair(9, make_pair(3,2)));
    phone.insert(make_pair(11, make_pair(1,1)));
    phone.insert(make_pair(0, make_pair(2,1)));
    phone.insert(make_pair(12, make_pair(3,1)));

    //default 왼손잡이
    int Hand = 0;
    if(hand == "right") Hand = 1;
    string answer = "";

    return what_hand(numbers, answer, Hand);
}