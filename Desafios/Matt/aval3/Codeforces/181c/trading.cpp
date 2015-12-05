/*
  Nome: Mateus Barros Rodrigues
  NUSP: 7991037
  MAC0327 - 2o Sem 2015
  3a Aval
  Problema PXX - 181C - Trading Business
*/

#include <bits/stdc++.h>

using namespace std;

int n,m,k;

struct Prod{
  int buy,sell,quant;

  bool operator<(const Prod& p) const{
    return buy > p.buy;
  }
}products[2000];

Prod p[2000];


int main(){

  cin >> n >> m >> k;

  int aux = 0;
  for(int i = 0; i < n; i++){
    string bla;
    cin >> bla;
    for(int j = 0; j < m; j++){
      int a,b,c;
      cin >> a >> b >> c;
      products[i*m + j].buy = a;
      products[i*m + j].sell = b;
      products[i*m + j].quant = c;
    }      
  }

  int sum = 0;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i==j)continue;

      for(int x = 0; x < m; x++){
	p[x].buy = products[i*m + x].sell - products[j*m + x].buy;
	p[x].quant = products[j*m+x].quant;
      }

      sort(p,p+m);

      int capacity = k;
      int resp = 0;

      for(int x = 0; x < m; x++){
	if(p[x].buy < 0) break;
	int qt = min(capacity,p[x].quant);
	capacity -= qt;
	resp += qt*p[x].buy;
      }

      sum = max(sum,resp);
    }
  }

  cout << sum << endl;
  
  return 0;
}
