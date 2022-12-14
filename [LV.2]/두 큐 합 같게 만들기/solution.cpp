[2022 KAKAO TECH INTERNSHIP] 두 큐 합 같게 만들기 lv.2
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long answer = 0, q1_sum = 0, q2_sum = 0;
    queue<long long> q1, q2;
    
    for(int i = 0; i < queue1.size(); i++){ // q1과 q2에 원소 삽입 및 합 구하기
        q1_sum += queue1[i];
        q2_sum += queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    while(answer <= (queue1.size() * 3) && !q1.empty() && !q2.empty()){ // 큐가 비어있거나 세 번 왕복할 크기
        if(q1_sum > q2_sum){ q1합 > q2합
            q1_sum -= q1.front();
            q2_sum += q1.front();
            q2.push(q1.front());
            q1.pop();
        }else if(q1_sum < q2_sum){ q1합 < q2합
            q2_sum -= q2.front();
            q1_sum += q2.front();
            q1.push(q2.front());
            q2.pop();            
        }else if(q1_sum == q2_sum){ 같아지면
            return answer;
        }        
        answer++;
    }
    
    // 
    return -1;
}
