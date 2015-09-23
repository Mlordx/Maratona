#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> prime;

int main(){
  prime.resize(165001);
  prime[0] = -1;
  prime[1] = -1;
  for(int i = 2; i < prime.size(); i++) prime[i] = 0;
  
  for(int i = 2; i <= 165000; i++){
    if(prime[i] == 0){
      prime[i] = 1;
      for(int j = 2*i; j <= 165000; j += i) prime[j] = -1;
    }
  }
  
  vector<int> prime2;

  for(int i = 0; i < prime.size(); i++)  if(prime[i] == 1) prime2.push_back(i);

  while(scanf("%d",&N) != EOF){
    int x;
    for(int i = 0; i < N; i++){
      scanf("%d\n",&x);
      printf("%d\n",prime2[x-1]);
    }
  }
  
  return 0;
}
