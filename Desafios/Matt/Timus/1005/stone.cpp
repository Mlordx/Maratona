/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P11 - 1005.Stone Pile
*/


#include <bits/stdc++.h>

using namespace std;

int N;

int stones[20];

//blc[i][j] == 1 se existe um subconjunto de 0 ate j-1 com soma i

int main(){
  cin >> N;
  int sum = 0;
  for(int i = 0; i < N; i++){ cin >> stones[i]; sum += stones[i];}

  bool blc[sum/2+1][N+1];

  for(int i = 0 ; i <= N; i++) blc[0][i] = true;
  for(int i = 1; i <= sum/2; i++) blc[i][0] = false;

  
  for(int i = 1; i <= sum/2; i++){
    for(int j = 1; j <= N; j++){
      if( stones[j-1] <= i ){
	blc[i][j] = blc[i][j-1] || blc[i-stones[j-1]][j-1];
      }
      else blc[i][j] = blc[i][j-1];
    }
  }

  int m = INT_MAX;

  for(int i = 1; i <= sum/2; i++){
    for(int j = 1; j <= N; j++){
      
      if(blc[i][j]){
	if(abs(sum-2*i) < m){
	  m = abs(sum - 2*i);
	}
      }
    }
  }

  if(N != 1) cout << m << endl;
  else cout << stones[0] << endl;
  
  return 0;
}
