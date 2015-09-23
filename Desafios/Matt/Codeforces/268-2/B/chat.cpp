#include<bits/stdc++.h>

using namespace std;

int p,q,l,r;
vector< pair<int,int> > timex(50);
vector< pair<int,int> > timez(50);

int main(){
  p = q = l = r = 0;
  cin >> p >> q >> l >> r;

  for(int i = 0; i < p; i++){
    int a,b;
    a = b = 0;
    cin >> a >> b;
    pair<int,int> bla = make_pair(a,b);
    timex[i] = bla;
  }

  for(int i = 0; i < q; i++){
    int a,b;
    a = b = 0;
    cin >> a >> b;
    pair<int,int> bla = make_pair(a,b);
    timez[i] = bla;
  }

  int cont = 0;
  int flag = 0;
  
  for(int k = l; k <= r; k++){
    flag = 0;
    for(int i = 0; i < q && !flag; i++){  						      

      pair<int,int> atual = make_pair(timez[i].first+k,timez[i].second+k);
	
      for(int j = 0; j < p; j++){

	pair<int,int> aux = timex[j];
	int a = aux.first;
	int b = aux.second;
	int c = atual.first;
	int d = atual.second;

	if(!flag && ((b >= c) && (d >= a)) ){  flag = 1; cont++;} 
	  
      } 
    }
  }
    
  printf("%d\n",cont);

  return 0;
}
