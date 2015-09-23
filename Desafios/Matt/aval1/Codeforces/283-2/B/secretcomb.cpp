#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>

using namespace std;
vector<int> digitos;
string numero;

int valor(char c){
  if(c == '0') return 0;
  if(c == '1') return 1;
  if(c == '2') return 2;
  if(c == '3') return 3;
  if(c == '4') return 4;
  if(c == '5') return 5;
  if(c == '6') return 6;
  if(c == '7') return 7;
  if(c == '8') return 8;
  if(c == '9') return 9;
}

int compara(vector<int> a, vector<int> b){
  for(int i = 0; i < a.size(); i++){
    if(a[i] > b[i]) return 1;
    if(a[i] < b[i]) return 0;
  }
}

int main(){
  int N = 0;
  cin >> N;
  int j;
  int min = 1 << 30;
  cin >> numero;
  vector<int> resp;

  for(int i = 0; i < N; i++){
    int x = valor(numero[i]);    
    digitos.push_back(x);
    resp.push_back(9);
  }
  
  min = 1 << 30;

  for(int x = 0; x < 2*N; x++){
    int aux = digitos[N-1];
    digitos.pop_back();
    digitos.insert(digitos.begin(),aux);
  
    
    for(int i = 0; i < 10; i++){

	if(!compara(digitos,resp)){
	  for(int k = 0; k < N; k++) resp[k] = digitos[k];
	}

      for( int k = 0; k < N; k++){
	digitos[k]+=1;
	if(digitos[k] == 10) digitos[k] = 0;
      }
    }

  }


  for(int k =0; k < N; k++) printf("%d",resp[k]);
  puts("");
  
  return 0;
}
