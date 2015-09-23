#include<string>
#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;

vector<string> table;

int N,M;

int compara(string a, string b){
  int p = 0;

  if(a.compare(b) <= 0) return -1;
  
  while(a[p] <= b[p]){ p++; if(p == N-1) break;}
  return p;
}

int main(){

  scanf("%d %d",&N,&M);
  table.resize(N);
  for(int i = 0; i < N; i++) cin >> table[i]; 
  
  int checa = 0;

  if(N == 1){
    printf("0\n");
    return 0;
  }

  int cont = 0;

  while(1){
    if(table[0].length() == 0) break;
    int min = 1 << 30;
    checa = 0;


    for(int i = 0; i < N-1; i++){
      int aux = compara(table[i],table[i+1]);
      if(aux != -1 && aux < min) min = aux;
    }

    for(int i = 0; i < N-1; i++){  if(table[i].compare(table[i+1]) <= 0) checa++;}

    if(checa == N-1) break;
    
    cont++;

    for(int i = 0; i < N; i++) table[i].erase(table[i].begin()+min);
  }

  cout << cont << endl;

  return 0;
}
