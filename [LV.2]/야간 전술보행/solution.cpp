#include <string>
#include <vector>
using namespace std;

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
    int answer = distance; // 전체 감시자를 통과하는 경우는 적군 기지까지의 거리
    
    for(int i = 0; i < scope.size(); i++){
        int work = times[i][0]; // 감시자가 일하는 시간
        int rest = times[i][1]; // 감시자가 쉬는 시간
        int start = min(scope[i][0], scope[i][1]); // 감시자의 감시 범위 시작
        int end = max(scope[i][1], scope[i][0]); // 감시자의 감시 범위 끝
        
        for(int j = start; j <= end; j++){ // 감시자의 [a, b]를 나타내는 반복문
            int total = work + rest;
            int check = j % total; 
            // 나머지가 0인 경우 쉬는 시간의 끝을 의미.
            // 1 <= x <= work의 의미: 감시자가 일하는 구간에 포함.
            if(check > 0 && check <= work){
                answer = min(answer, j);
                // 이미 최소값을 구했으므로 반복문 빠져나옴.
                break;
            }            
        }        
    }    
    return answer;
}
