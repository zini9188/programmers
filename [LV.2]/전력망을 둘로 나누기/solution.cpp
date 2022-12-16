전력망을 둘로 나누기
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 101; 
    int len = wires.size();  
    
    for(int i = 0; i < len; i++){ // 모든 배열의 값을 돌면서 전선을 끊어준다.
        vector<int> visited (101,0);
        int v1 = wires[i][0]; // 끊은 전선의 출발 값
        int v2 = wires[i][1]; // 끊은 전선의 도착 값
        int cnt = 1;        
        queue<int> q;
        q.push(v1);
        visited[i] = 1;
        
        // bfs를 이용하여 끊은 전선의 출발 값과 이어진 송전탑들을 찾는다.
        while(!q.empty()){
            int target = q.front();
            q.pop();                  
            
            // 방문하지 않았으며 target에 해당하는 출발, 도착 값들을 찾기
            for(int j = 0; j < len; j++){
                if(!visited[j]){
                    // 출발 값이 같으므로 방문 처리 후 도착 값으로 이어진 송전탑을 찾기 위해 큐에 푸쉬
                    if(wires[j][0] == target){
                        visited[j] = 1;                                                
                        q.push(wires[j][1]);                        
                        cnt++;
                    // 마찬가지로 출발 값으로 이어진 송전탑 찾기
                    }else if(wires[j][1] == target){
                        visited[j] = 1;                                                
                        q.push(wires[j][0]);                        
                        cnt++;                        
                    }
                }                
            }            
        }
        
        // a = 끊어진 전선의 출발지와 이어진 송전탑의 개수
        int a = n - cnt;
        // b = 끊어진 전선의 도착지와 이어진 송전탑의 개수
        int b = cnt;
        
        answer = min(answer, abs(a - b));        
    }    
    
    return answer;
}
