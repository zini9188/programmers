#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    // 연결된 길의 리스트를 생성한다. ex) 1번길 : 2, 4, 5번길과 연결 v[1] = 2, 4, 5
    map<int, vector<int>> road;
    for(int i = 0; i < roads.size(); i++){
        int current = roads[i][0];
        int linked = roads[i][1];       
        road[current].push_back(linked);
        road[linked].push_back(current);        
    }    

    queue<int> nextPosition;
    // 거리 표시를 위한 배열 초기값은 무한대
    vector<int> distance(n + 1, 987654321);
    // 목적지부터 역순으로 연결한다.
    nextPosition.push(destination);
    // 목적지의 거리는 0으로 둔다. (시작 지점이므로 이동이 없음)
    distance[destination] = 0;   

    // bfs 시작
    while(!nextPosition.empty()){
        int pos = nextPosition.front();
        nextPosition.pop();
        
        // 해당 index의 길과 연결된 길을 비교한다.
        for(int i = 0; i < road[pos].size();i++){
            int element = road[pos][i];
            // 현재 길과 다음 길을 비교하는데 만약 현재 길보다 크다면 최단거리를 위해 최소값을 넣어준다.
            if(distance[pos] + 1 < distance[element]){
                distance[element] = distance[pos] + 1;
                nextPosition.push(element);
            }
        }
    }

    // sources의 배열을 돌며 현재까지 구한 거리의 값을 비교하고 정답 배열에 삽입한다. 거리가 무한대인 경우 return -1
    for(int i = 0; i < sources.size(); i++){
        int ans = distance[sources[i]] < 987654321 ? distance[sources[i]] : -1;
        answer.push_back(ans);
    }

    return answer;
}
