/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P22 - 1124.Mosaic
*/


#include <bits/stdc++.h>

using namespace std;

vector<int> adj[501];

int M,N;

int cmp,diff;

void dfs_r(int u){
  while(!adj[u].empty()){
    auto v = adj[u].back();
    adj[u].pop_back();
    dfs_r(v);
    cmp++;
  }
}

void dfs(){
  for(int i = 1; i <= M; i++){
    if(!adj[i].empty()){
      dfs_r(i);
      diff++;
    }
  }
}

  

int main(){
  cin >> M >> N;

  for(int i = 1; i <= M; i++){
    for(int j = 0; j < N; j++){
      int aux;
      cin >> aux;
      if(aux != i) adj[i].push_back(aux);
    }
  }

  dfs();
  
  cout << diff+max(cmp-1,0) << endl;
  
  return 0;
}
