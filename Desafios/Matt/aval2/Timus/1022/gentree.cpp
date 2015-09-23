/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o sem 2015
2a aval
Problema P9 - 1022. Genealogical Tree
*/

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

  cin >> N;
  top.clear();

    
  for(int i = 0; i <= N; i++) adj[i].clear();

  int a = 0, b = 0;
  for(int i = 0; i < N; i++){
    int M = -1;
    while(M != 0){
      cin >> M;
      if(M == 0) continue;
      adj[M].push_back(i+1);
    }
  }
  top_sort();
    
  for(int i = 0; i < N-1; i++)
    cout << top[i] << " ";
  cout << top[N-1] << endl;
    
  
  
  return 0;
}
