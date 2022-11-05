#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int len = order.size();
    int index = 0;
    stack<int> container;
    for(int i = 1; i <= len; i++){
        container.push(i); // 스택에 하나씩 쌓기
        // 스택의 맨 위 값이 order[index]와 같은 경우에만 그리고 스택이 비어있지 않으면
        while(!container.empty() && container.top() == order[index]){ 
            // 해당 값을 pop하고 다음 order로 넘어가기
            container.pop();
            index++;
            answer++;            
        }
    }
    return answer;
}
