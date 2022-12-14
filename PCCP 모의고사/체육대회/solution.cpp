#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int visited[10001]; // 방문 판별 배열
vector<vector<int>> abil;
int m,n;
int res = 0;
void dfs(int sum, int idx){
    if(idx == n){ // 모든 종목을 비교하면 최대값을 비
        res = max(res, sum);    
        return;
    }
    
    // 선발한 학생을 선발했다고 표시하고 합계를 더한 후 다음 종목으로 넘기
    for(int i = 0; i < m; i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(sum + abil[i][idx], idx + 1);
            visited[i] = 0;
        }        
    }
}

int solution(vector<vector<int>> ability) {
    int answer = 0;
    
    abil = ability;   
    m = ability.size();
    n = ability[0].size();
    dfs(0,0);
    
    return res;
}
