//https://school.programmers.co.kr/learn/courses/30/lessons/42583
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck) {
    int answer = 0;
    int index = 0;
    int tsize = truck.size();
    queue<int> passed;
    queue<int> passing;
    queue<int> time;
    while(true){
        if(passed.size() == tsize) // 트럭이 완전히 다리를 떠난 시간이 필요하므로 answer에 +1을 해줘야 한다.
            return ++answer;
        
        if(index != tsize && truck[index] <= weight){ // 트럭의 무게가 다리의 무게보다 작은 경우
            passing.push(truck[index]); 
            weight -= truck[index++];    
            time.push(answer + bridge_length);
        }
        
        answer++; // 매초 증가
        
        if(time.front() == answer){ // 시간 큐의 첫 트럭이 다 지나간 경우
            passed.push(passing.front());
            weight += passing.front();
            passing.pop();
            time.pop();
        }        
    }    
}
