#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i = 1; i < food.size(); i++){ // i번째 음식의 절반만큼 음식 배치
        for(int j = 0; j < food[i]/2; j++){
            answer+= to_string(i);
        }        
    }
    string temp = answer;
    reverse(temp.begin(), temp.end()); // 만든 음식을 거꾸로 변경
    
    return answer + "0" + temp; // 중간에 물을 넣고 두 음식 배치를 합치기
}
