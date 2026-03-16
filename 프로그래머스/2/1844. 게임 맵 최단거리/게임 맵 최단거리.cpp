#include <bits/stdc++.h>
using namespace std;
int visited[104][104];
queue<pair<int,int>> q;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
 

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    visited[0][0] = 1;
    q.push({0,0});
    while(q.size()){
        auto [y,x] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= n || nx >= m || ny < 0 || nx < 0) continue;
            if(visited[ny][nx] || maps[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
        
        
    }
    
    if(visited[n-1][m-1] == 0) {
        answer = -1;
    }
    else{
        answer = visited[n-1][m-1];
    }
    
    
    return answer;
}