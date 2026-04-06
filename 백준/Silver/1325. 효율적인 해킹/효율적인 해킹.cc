#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[10004];
int visited[10004], ret[100004];
int mx;

int dfs(int i){
  visited[i] = 1;
  int cnt = 1;
  for(int k : adj[i]){
    if(!visited[k]){
      cnt += dfs(k);
    }
  }
  return cnt;
}

int main(){
  cin >> n >> m;


  while(m--){
    int a, b;
    cin >> a >> b;
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n ; i++){
    fill(visited, visited  + 10004 , 0);
    ret[i] = dfs(i);
    mx = max(mx,ret[i]);
  }

  for(int i = 1; i <= n; i++){
    if(ret[i] == mx){
      cout << i << ' ';
    }
  }

  return 0;
}