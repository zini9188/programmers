#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> new_orders;

bool comp(pair<string, int> a, pair<string, int> b){ 
    return a.second > b.second;
}

void dfs(string word, string order, int index, int target){ // word에 order의 조합들을 담아 원하는 길이가 되면 map에 담아주기
    if(word.size() == target){
        new_orders[word]++;
        return;
    }    
    for(int i = index; i < order.size(); i++){
        dfs(word + order[i], order, i + 1, target);
    }    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(auto &order : orders) // &를 이용하여 실제 order값들을 정렬
            sort(order.begin(), order.end());

    for(auto cs : course){ 
        for(auto order : orders){  
            if(order.size() < cs) // 주문 갯수가 만들어야 하는 코스보다 작으면 패스
                continue;    
            dfs("", order, 0, cs);
        }
        vector<pair<string, int>> v(new_orders.begin(), new_orders.end());
        sort(v.begin(), v.end(), comp);
        
        int m = 0;
        for(auto a: v){
            m = max(m, a.second);
            if(m >= 2 && m == a.second){ // 2명 이상이 주문하여야 하므로 
                answer.push_back(a.first);
            }
        }
        new_orders.clear(); // 다음 코스 종류 추가를 위해 초기화
    }    
    sort(answer.begin(), answer.end());   

    return answer;
}
