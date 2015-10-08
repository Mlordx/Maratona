/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P16 - 1080.Map Coloring
*/


#include <bits/stdc++.h>

using namespace std;

int N;
int impossible = 0;

vector<int> adj[99];
vector<int> color(99,-1);

void dfs_r(int u,int last_color){  
  color[u] = !last_color;
  
  for(auto a = adj[u].begin(); a != adj[u].end(); a++){
    auto v = *(a);
    if(color[v] == -1){
      dfs_r(v,color[u]);
    }else{
      if(color[v] == color[u]) impossible = 1;
    }
  }
}

void dfs(){
  int c = 1;
  dfs_r(0,c);
}


int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    while(1){
      int v;
      cin >> v;
      if(!v) break;
      adj[i].push_back(v-1);
      adj[v-1].push_back(i);
    }
  }

  dfs();
  if(impossible){ cout << "-1\n"; return 0; }
  
  for(int i = 0; i < N; i++) cout << color[i];
  cout << endl;
  
  return 0;
}
