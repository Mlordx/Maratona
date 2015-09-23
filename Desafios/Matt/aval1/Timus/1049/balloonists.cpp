#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> prime;
vector<int> prime2;


void computePrimes(){
  prime.resize(10001);
  prime[0] = -1;
  prime[1] = -1;
  for(int i = 2; i < prime.size(); i++) prime[i] = 0;
  
  for(int i = 2; i <= 10000; i++){
    if(prime[i] == 0){
      prime[i] = 1;
      for(int j = 2*i; j <= 10000; j += i) prime[j] = -1;
    }
  }
  

  for(int i = 0; i < prime.size(); i++)  if(prime[i] == 1) prime2.push_back(i);
}
  

int main(){
  computePrimes();
  int divs = 1;
  vector<int> factors(10000);
  for(int i =0;i < 10; i++){
    int bla = 0;
    cin >> bla;

    for(int j = 0; j < prime2.size(); j++){
	while(bla%prime2[j] == 0){
	    factors[prime2[j]] += 1;
	    bla /= prime2[j];
	}
      }
  }
  
  for(int k =0; k < 10000;k++) if(factors[k] != 0) divs *= factors[k]+1;
  
  printf("%d\n",divs%10);
  

  return 0;
}
