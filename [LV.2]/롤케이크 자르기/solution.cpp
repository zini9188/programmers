#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> older; 
    set<int> younger;
    
    for(int i = 0; i < topping.size(); i++){ // 형에게 모든 토핑을 준다.
        older[topping[i]]++;
    }
    
    for(int index = 0; index < topping.size() - 1; index++){ // 인덱스를 늘려가며 동생에게 토핑을 하나씩 준다.
        younger.insert(topping[index]); // set을 이용하여 중복이 없게 계산
        older[topping[index]]--;
        
        if(older[topping[index]] <= 0){ // 해당 맛 토핑이 없으면 map에서 제거해준다.
            older.erase(topping[index]);
        }     
        
        if(younger.size() == older.size()){ // 두 배열의 크기가 같으면 토핑의 개수가 같으므로 answer++
            answer++;
        }    
    }    
    
    return answer;
}
