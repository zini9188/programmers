#include <string>
using namespace std;

int solution(string dirs) {
    string dir = "UDRL"; // 방향의 인덱스
    int answer = 0;    
    int board[11][11][11][11] = {0,}; // x1,y1와 x2,y2의 간선을 구하는 배열
    int x = 5, y = 5;
    int mx[4] = {0,0,1,-1};
    int my[4] = {1,-1,0,0};
    
    for(auto a : dirs){
        int nX, nY;
        int n = dir.find(a);
        nX = x + mx[n];
        nY = y + my[n];
        if(nX <= 10 && nX >= 0 && nY <= 10 && nY >= 0){ // 다음 좌표가 보드 위에 있을 수 있으면
            if(!board[nX][nY][x][y] || !board[x][y][nX][nY]) // 하나라도 가지 않은 길인 경우
                answer++;            
            
            board[x][y][nX][nY] = 1;            
            board[nX][nY][x][y] = 1;
            
            x = nX;
            y = nY;
        }
    }
    
    return answer;
}
