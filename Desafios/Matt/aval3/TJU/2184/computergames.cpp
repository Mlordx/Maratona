/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
3a Aval
Problema PXX - 2184 - Computer Games II
*/


#include <bits/stdc++.h>

using namespace std;

int N,K;
vector<int> levels;
vector<int> levels2;


int main(){
  while(1){
    levels.clear();
    levels2.clear();
    cin >> N >> K;
    if(N==0 && K==0) break;
    
    for(int i = 0; i < N; i++){
      int aux;
      cin >> aux;
      if(aux%2 == 0)levels.push_back(aux);
      else levels2.push_back(aux);
    }

    int count = 0;

    sort(levels.begin(),levels.end());
    sort(levels2.begin(),levels2.end());

    int i = 0;
    int j = 0;

    int a = (int)levels.size();
    int b = (int)levels2.size();

    
    while((i < a) && (j < b)){
      if(levels[i] - levels2[j] > K) j++;
      else if( levels[i] - levels2[j] < -K) i++;
      else{
	count++;
	i++; j++;
      }
    }

    cout << count << endl;
  }
 

  
  return 0;
}
