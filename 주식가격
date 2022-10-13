#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size() - 1; i++){
        int sec = 1;
        for(int j = i + 1; j < prices.size(); j++){
            if(prices[i] > prices[j] || j == prices.size() - 1){ // price[i]가 price[j] 보다 크다면 가격이 떨어진 것, 혹은 마지막까지 비교하는 경우의 시간을 넣어준다.
                answer.push_back(sec);
                break;
            }
            sec++;            
        }
    }
    // 마지막 인덱스는 항상 0이다
    answer.push_back(0);
    
    
    return answer;
}
