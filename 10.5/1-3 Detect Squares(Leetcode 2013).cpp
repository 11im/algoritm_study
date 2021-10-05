//https://leetcode.com/contest/weekly-contest-259/problems/detect-squares/

//add : add point to structure
//count : count squres can be made with points that belongs to structure and input point
//diagonals -> right-up : x + y = k; left-down : x - y = k;


class DetectSquares {
public:
    map<int,vector<pair<int,int>>>sum,diff;
    int array[1002][1002];
    
    //reset
    DetectSquares() {
        sum.clear();
        diff.clear();        
        memset(array, 0, sizeof(array[0][0])*1002*1002);
    }
    
    //diagonal sum and diff add, array marking, if duplicate exist - array will have 2;
    void add(vector<int> point) {
        sum[point[0] + point[1]].push_back(make_pair(point[0], point[1]));
        diff[point[0] - point[1]].push_back(make_pair(point[0], point[1]));
        array[point[0], point[1]]++;
    }
    
    //find square;
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int answer = 0;
        //temp in diagonal sum;
        for(auto temp : sum[x + y]){
            //if duplicates of (x,y) exist in sum, exclude this case;
            if(temp.first = x && temp.second = y)  continue;
            //if x-axis and y-axis are same;
            if(abs(temp.first - x) == abs(temp.second - y)){
                //if duplicates exist
                answer += (array[temp.first][y] * array[x][temp.second]);
            }
        }
        //temp in diagonal diff
        for(auto temp : diff[x - y]){
            if(temp.first == x && temp.second == y) continue;
            if(abs(temp.first - x)) == abs(temp.second - y)){
                answer += (array[temp.first][y] * array[x][temp.second]);
            }
        }
        return answer;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */