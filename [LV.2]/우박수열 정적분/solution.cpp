#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;    
    vector<double> y;
    int num = k; // temp
    y.push_back(k); // (0,0)
    
    while(num != 1){ // 우박수열 계산
        if(num % 2 == 0){
            num /= 2;
        }else{
            num = num * 3 + 1;     
        }
        y.push_back(num);       
    }
    
    vector<double> area; // [i, i+1]의 넓이 계산
    for(int i = 0; i < y.size() - 1; i++){        
        area.push_back(abs(y[i] + y[i + 1]) / 2);
    }
    
    vector<double> total_area = {0.0, area.front()}; // [0, i] 의 넓이를 계산
    for(int i = 2; i < area.size() + 1; i++){
        total_area.push_back(total_area[i - 1] + area[i - 1]);
    }
    
    for(auto range : ranges){ // [left, right] 의 넓이 계산
        int right = y.size() + range[1] - 1;
        int left = range[0];
        if(left <= right){
            answer.push_back(total_area[right] - total_area[left]);
        }else{
            answer.push_back(-1);
        }
    }
    
    return answer;
}
