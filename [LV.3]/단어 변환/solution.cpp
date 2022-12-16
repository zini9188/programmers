단어 변환

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> visited = {false, }; // 방문 체크 배열
int answer = 51; // 정답
vector<string> word; // words의 복사본
string t; // 목표 단어
void dfs(string cur, int cnt){
    if(cur == t){ // 목표 단어이면 정답의 최소값을 비교
        answer = min(cnt, answer);
        return;
    }
    // word의 크기 만큼 루프
    for(int i = 0; i < word.size(); i++){
        // 방문하지 않았다면 방문으로 변경
        if(!visited[i]){
            visited[i] = true;
            // 현재 단어와 바꿀 단어의 다른 알파벳이 한개만 있는 경우 단어를 변경
            int c = 0;
            for(int j = 0; j < cur.size(); j++){
                if(cur[j] != word[i][j]){
                    c++;
                }                
            }
            if(c == 1){
                dfs(word[i], cnt + 1);
            }
            // 백트래킹
            visited[i] = false;
        }        
    }      
}
int solution(string begin, string target, vector<string> words) {
    t = target;
    word = words;
    dfs(begin, 0);
    // 정답이 나오지 않으면
    if(answer == 51)
        return 0;
    return answer;
}
