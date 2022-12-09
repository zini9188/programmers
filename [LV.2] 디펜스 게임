#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    if (k == enemy.size()) { // 방어권으로 모든 병력을 막을 수 있을 때
        return k;
    }

    priority_queue<int> pq;
    for (int i = 0; i < enemy.size(); i++) { // 라운드를 진행
        if (k > 0) { // 방어권이 있는 경우 소진하여 라운드 증가
            pq.push(-enemy[i]); // 큐에 방어한 병력을 넣기
            k--; // 방어권을 소모
        } else { // 방어권을 모두 소모한 경우
            pq.push(-enemy[i]); // 해당 라운드의 병력을 큐에 넣기
            if (n >= -pq.top()) { // 현재 병력으로 큐에 넣었던 가장 적은 라운드의 병력을 막을 수 있는 경우
                n -= -pq.top(); // 현재 병력에서 방어한 병력 빼기
                pq.pop(); // 가장 적은 값 빼주기
            } else { // 현재 병력으로 막을 수 없는 라운드인 경우
                return i;
            }
        }
    }

    return enemy.size();
}
