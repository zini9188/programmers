[2018 KAKAO BLIND RECRUITMENT] 방금그곡
#include <string>
#include <vector>
#include <sstream>
#include <regex>
using namespace std;

string replace(string s){ // #이 포함된 경우 소문자로 변경
    string target = "A#C#D#F#G#";
    string trans = "acdfg";    
    for(int i = 0; i < 5; i++){
        s = regex_replace(s,regex(target.substr(i * 2 , 2)), trans.substr(i,1));      
        // regex_replace(문자열, 찾을 문자열, 변환 문자열);
    }
    return s;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";

    int max = 0; 

    m = replace(m); 

    for(auto musicinfo : musicinfos){
        stringstream ss;
        ss.str(musicinfo);
        string s;
        vector<string> v;
        while(getline(ss, s, ',')){ // ,를 기점으로 문자 분리
            v.push_back(s);
        }
        string title = v[2];
        string code = v[3];

        code = replace(code);

        int time = (stoi(v[1].substr(0,2)) - stoi(v[0].substr(0,2))) * 60 + stoi(v[1].substr(3)) - stoi(v[0].substr(3));
        
        // code의 길이를 time의 길이만큼 변환하는 과정
        while(code.size() < time){
            code += code;
        }

        code = code.substr(0, time);

        // code에서 기억한 멜로디가 있는지 확인
        if(code.find(m) < code.size()){
            // 큰 값이 있으면 변경 후 answer를 현재 title로 변경
            if(max < time){
                max = time;
                answer = title;
            }
        }
    }

    return answer = answer.empty() ? "(None)" : answer;
}
