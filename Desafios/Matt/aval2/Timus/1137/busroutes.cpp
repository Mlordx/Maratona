/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P12 - 1137.Bus Routes
*/


#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> adj[100009];
int visit[10000][10000];

vector<int> cycle;

void dfs(int u){
  
  for(auto bla = adj[u].begin(); bla != adj[u].end(); bla++){
    auto v = *(bla);
    if(!visit[u][v]){
      visit[u][v] = 1;
      dfs(v);
    } 
  }
  
  cycle.push_back(u);
}

int main(){
  cin >> N;
  int aux = 0;

  for(int i = 0; i < N; i++){
    int M;
    cin >> M;
    int first;
    cin >> first;
    int last = first-1;
    aux = last;
    for(int i = 0; i < M; i++){
      int a;
      cin >> a;
      adj[last].push_back(a-1);
      visit[last][a-1] = 0;
      last = a-1;
    }
  }

  dfs(aux);
  unsigned int size = cycle.size()-1;
  cout << size << " ";
  reverse(cycle.begin(),cycle.end());
  for(auto i = 0; i < size-1; i++) cout << cycle[i]+1 << " ";
  cout << cycle[size-1]+1 << " " << cycle[0]+1 << endl;

  return 0;
}
