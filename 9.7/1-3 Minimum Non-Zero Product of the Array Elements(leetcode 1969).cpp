//https://leetcode.com/contest/weekly-contest-254/problems/minimum-non-zero-product-of-the-array-elements/

//int p 가 주어진 상황에서 [1:2^p -1]의 2진 숫자들을 생성 후, 해당 숫자들 중 2개를 골라 같은 위치에 있는 0과 1을 바꿔서 생성된 숫자들의 곱이 최소가 되도록하는 함수
//생성한 배열에서 최대한 많은 1을 만들어야함 -> XOR 연산했을 때 2^p - 1이 나오면 하나는 1, 하나는 2^p-1-1로 변경
//필요한 함수 : 1. 주어진 범위의 2진 숫자를 만드는 함수 2. 생성된 숫자들의 0과 1을 바꾸는 함수

public:
    int minNonZeroProduct(int p) {
        int answer = 1;
        int idx = pow(2, p) - 1;
        int nums[idx];
        
        for(int i = 0; i < idx; i++){
            nums[i] = i + 1;
        }

        for(int i = 0; i < idx / 2; i++){
            for(int j = idx; j >= idx/2; j++){
                if(nums[i] ^ nums[j] == idx){
                    nums[i] = 1;
                    nums[j] = idx -1;
                }
            }
        }

        for(int i = 0; i < idx; i++){
            answer = answer * nums[i];
        }

        return answer;
    }