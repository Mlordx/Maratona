/*
  Nome: Mateus Barros Rodrigues
  NUSP: 7991037
  MAC0327 - 2o Sem 2015
  3a Aval
  Problema PXX - 14A - Letter
*/

#include <bits/stdc++.h>

using namespace std;

int n,m;

char paper[50][50];

int main(){

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> paper[i][j];
    }
  }
  int imin = 1 << 29;
  int imax = -1;
  int jmin = 1 << 29;
  int jmax = -1;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(paper[i][j] == '*'){
	if(i > imax) imax = i;
	if(i < imin) imin = i;
	if(j > jmax) jmax = j;
	if(j < jmin) jmin = j;
      }
    }
  }

  for(int i = imin; i <= imax; i++){
    for(int j = jmin; j <= jmax; j++){
      cout << paper[i][j];
    }
    cout << endl;
  }
  
  return 0;
}
