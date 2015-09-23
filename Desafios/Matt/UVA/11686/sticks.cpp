#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001],top;
int visited[100001],finished[100001];

int N,M;
int tempo;

int dfs_r(int v){
  visited[v] = 1;

  for(auto u = adj[v].begin(); u != adj[v].end(); u++){
    int x = (*u);
    if(!visited[x]){
      if(!dfs_r(x))
	return 0;
    }
    else if(!finished[x]){
      return 0;
    }
  }
  
  top.push_back(v);
  finished[v] = 1;
  return 1;
}

int top_sort(){
  for(int i = 1; i <= N; i++) finished[i] = visited[i] = 0;

  for(int i = 1; i <= N; i++)
    if(!visited[i])
      if(!dfs_r(i))
	return 0;

  return 1;
}


int main(){

  while(1){
    cin >> N >> M;
    top.clear();

    if(!N && !M) return 0;
    for(int i = 0; i <= N; i++) adj[i].clear();

    int a = 0, b = 0;
    for(int i = 0; i < M; i++){
      cin >> a >> b;
      adj[a].push_back(b);
    }

    if(top_sort()){
      for(int i = N-1; i >= 0; i--)
	cout << top[i] << endl;
    }else cout << "IMPOSSIBLE\n";
          
  }
  
  return 0;
}
