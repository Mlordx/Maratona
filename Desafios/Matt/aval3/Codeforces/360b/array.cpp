/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
3a Aval
Problema P5 - 210B - Levko and Array
*/


#include <bits/stdc++.h>

using namespace std;

int N,K;

int a[2001],b[2001];

int beautiful(long long m){
  for(int i = 1; i <= N; i++) b[i] = i-1;
  
  for(int i = 2; i <= N; i++)
    for(int j = 1; j <= i-1; j++)
      if(abs(a[i]-a[j]) <= m*(i-j))
	b[i] = min(b[i],b[j] + i - j - 1);
  
  for(int i = 1; i <= N; i++)
    if(b[i] + N - i <= K) return 1;
  return 0;
}

int main(){
  cin >> N >> K;

  for(int i = 1; i <= N; i++) cin >> a[i];

  long long l = 0, r = INT_MAX;
  int aux;
  while( l < r ){
    aux = (l + r)/2;
    if(beautiful(aux)) r = aux;
    else l = aux +1;
  }

  cout << l << endl;

  return 0;
}
