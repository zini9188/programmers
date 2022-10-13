#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = 0;    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end()); // 우선 순위 큐 가장 작은 값을 마지막으로 두게 함
    
    while(1){
        if(pq.top() >= K) // 큐의 마지막이 K이상이면 return
            return answer;
        if(pq.size() <= 1) // 큐가 더이상 음식을 섞을 수 없으며 K 이상인 값이 없으므로 -1 return
            return -1;
        
        int n = 0; 
        n += pq.top(); 
        pq.pop();
        n += pq.top() * 2;
        pq.pop();
        // 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)        
        
        pq.push(n); // 섞은 음식을 큐에 넣어주면 자동으로 정렬이 된다.
        answer++;
    }
}
