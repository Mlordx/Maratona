/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
3a Aval
Problema PXX - 181A - Series of Crimes
*/



#include <bits/stdc++.h>

using namespace std;

int N,M;

int Map[101][101];

vector<pair<int,int> > coords;

int main(){
  cin >> N >> M;

  for(int i = 0; i < N; i++){
    string aux;
    cin >> aux;
    for(int k = 0; k < aux.length(); k++)
      if(aux[k] == '*'){ coords.push_back(make_pair(i+1,k+1)); Map[i+1][k+1] = 1;}
  }

  int a = 0,b = 0;
  for(int i = 1; i <= N; i++){
    int sum = 0;
    for(int j = 1; j <= M; j++) sum += Map[i][j];
    if(sum == 1){ a = i; break; }
  }

  for(int j = 1; j <= M; j++){
    int sum = 0;
    for(int i = 1; i <= N; i++) sum += Map[i][j];
    if(sum == 1){ b = j; break; }
  }

  cout << a << " " << b << endl;
  
  return 0;
}
