#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end()); // 상자에는 최대한 비싼것끼리 모아야 하므로 오름차순으로 정렬
    
    for(int i = score.size() - 1; i - m + 1>= 0; i-= m){ // 맨 뒤의 사과부터 상자에 담는다.
        int profit = score[i - m + 1] * m; // 상자에 담기는 맨 앞 사과의 값으로 식을 계산
        answer += profit;       
    }    
    
    return answer;
}
