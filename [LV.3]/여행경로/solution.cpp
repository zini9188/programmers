#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> answer; // 정답을 처리할 벡터
vector<vector<string>> ticket; // tickets의 배열 복사
vector<bool> visited = {0,}; // ticket의 방문을 처리
bool flag = false; // 모든 항공권을 사용했음을 처리
void dfs(string cur, int cnt){
    if(cnt == ticket.size()){ // 모든 항공권을 사용하면 flag = true;
        flag = true;
    }
    // 현재 방문한 공항을 벡터에 삽입
    answer.push_back(cur);    
    // 티켓 배열을 루프
    for(int i = 0; i < ticket.size(); i++){
        // 해당 항공권을 사용하지 않았고 현재 공항과 같은 위치이면
        if(!visited[i] && ticket[i][0] == cur){
            // 해당 항공권을 사용으로 변경
            visited[i] = true;
            // 도착 공항을 현재 공항으로 변경 후 항공권 사용 횟수 증가
            dfs(ticket[i][1], cnt + 1);
            // 모든 항공권을 사용하지 못했을 경우 백트래킹을 이용
            if(!flag){
                answer.pop_back();
                visited[i] = false;
            }
        }
    }    
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    ticket = tickets;
    dfs("ICN", 0);    
    return answer;
}
