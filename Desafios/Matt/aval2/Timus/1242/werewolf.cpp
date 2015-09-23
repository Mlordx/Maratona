/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P10 - 1242.Werewolf
*/


#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> adj[1001];
vector<int> victim(1001,0);
vector<int> suspect(1001,1);

void dfsV(int v){
  suspect[v] = 0;

  for(auto u = adj[v].begin(); u != adj[v].end(); u++){
    int w = (*u);
    if(suspect[w]) dfsV(w);
  }
  
}

void dfsM(int v){
  for(auto u = adj[v].begin(); u != adj[v].end(); u++){
    int w = (*u);
    if(suspect[w]) dfsM(w);
    if(victim[w]){
      suspect[v] = 0;
      victim[v] = 1;
    }
  }
}




int main(){
  cin >> N;
  
  string a;
  
  while(1){
    cin >> a;
    if(a == "BLOOD") break;
    int numb;
    istringstream(a) >> numb;
    int b = 0;
    cin >> b;
    adj[numb].push_back(b);
    //cout << a << "~" << b << endl;
  }


  int v;
  while(scanf("%d\n",&v) != EOF){
    victim[v] = 1;
    dfsV(v);
  }

  for(int i = 1; i <= N; i++){
    if(!victim[i]) dfsM(i);
  }

  int flag = 0;
  for(int i = 1; i <= N; i++){
    if(suspect[i]){
      cout << i << " ";
      flag = 1;
    }
  }
  if(flag)cout << endl;
  else cout << "0\n";
  
  

  return 0;
}
