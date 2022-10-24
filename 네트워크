네트워크

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;   
    vector<int> visited (n, 0); // 각 노드의 방문을 처리
    queue <int> q;
    for(int i = 0; i < n; i++){ // 1 ~ n개의 컴퓨터 배열
        if(visited[i]){ // 방문한 컴퓨터인 경우 continue;
            continue;
        }
        q.push(i); // 큐에 방문할 컴퓨터를 푸쉬
        visited[i] = 1; // 해당 컴퓨터를 방문했음
        while(!q.empty()){ // 큐가 빌때까지
            int num = q.front(); // 큐의 맨 앞 부분을 저장 후 pop
            q.pop();
            
            // 해당 컴퓨터와 연결되어 있는 컴퓨터들을 찾기
            for(int j = 0; j < n; j++){
                // 방문하지 않은 번호의 컴퓨터인 경우 그리고 현재 컴퓨터와 연결되어 있을 경우
                if(visited[j] == 0 && computers[num][j] == 1){
                    // 다음번 루프에서 방문하기 위해 큐에 삽입 후 해당 컴퓨터를 방문했음으로 변경
                    q.push(j);
                    visited[j] = 1;
                }
            }            
        }
        // 방문하지 않은 컴퓨터가 있으므로 네트워크의 개수를 증가
        answer++;        
    }    
    
    return answer;
}
