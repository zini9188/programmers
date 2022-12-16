#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int comp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first > b.first;    
    return a.second > b.second;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;

    map<int, vector<pair<int, int>>> courses;
    vector<int> intensity(50001);
    vector<bool> isSummit(50001);

    // 그래프 생성
    for (auto path: paths) {
        // 정점, 간선, 가중치
        courses[path[1]].push_back({path[0], path[2]});
        courses[path[0]].push_back({path[1], path[2]});
    }

    // 정상에 닿는 값들 저장소
    vector<pair<int, int>> lower;
    // 현재 시작 지점에 대한 우선순위 큐 생성
    fill(intensity.begin(), intensity.end(), -1);
    priority_queue<pair<int,int>> pq;
    // gate까지의 최소 거리, gate번호, 현재까지 가장 긴 intensity
    for (auto gate: gates) {
        pq.push({0, gate});
        intensity[gate] = 0;
    }
    for(auto summit : summits){
        isSummit[summit] = true;
    }
    
    
    while (!pq.empty()) {
        // 현재 노드의 intensity
        int currentIntensity = -pq.top().first;
        // 현재 노드의 번호
        int currentNode = pq.top().second;
        // 큐에서 삭제
        pq.pop();
        
        // 현재 노드의 가중치가 현재 노드의 intensity보다 크면 비교할 필요가 없으므로 continue
        if (currentIntensity > intensity[currentNode])
            continue;

        // 현재 노드가 정상에 해당하면 정답에 값을 넣어줌
        if (isSummit[currentNode]) {
            lower.emplace_back(currentNode, currentIntensity);
            continue;
        }

        // 현재 노드와 연결된 다음 노드들
        for (auto course: courses[currentNode]) {
            // 다음 노드와 다음 가중치
            int nextNode = course.first;
            int nextDist = course.second;
            // intensity[nextNode]가 할당되지 않은 -1 이거나
            // intensity[nextNode]의 값이 max(currentIntensity, nextDist) 보다 더 큰 값인 경우이다.
            // 최소값을 구해야 하므로 intensity[nextNode]에 더 작은 가중치를 넣어줘야 한다.
            if(intensity[nextNode] == -1 || intensity[nextNode] > max(nextDist, currentIntensity)){
                intensity[nextNode] = max(nextDist, currentIntensity);
                pq.push({-intensity[nextNode], nextNode});
            }           
        }
    }
    sort(lower.begin(), lower.end(), comp);
    answer.push_back(lower.back().first);
    answer.push_back(lower.back().second);

    return answer;
}
