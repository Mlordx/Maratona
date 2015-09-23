#include<bits/stdc++.h>

using namespace std;

int N;

void resp(int N){
  if(N == 4){
    printf("1 * 2 = 2\n");
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
  }
  if(N == 5){
    printf("5 - 3 = 2\n");
    printf("2 + 1 = 3\n");
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
  }
  if(N <= 5) return;
  
  resp(N-2);
  printf("%d - %d = 1\n",N,N-1);
  printf("24 * 1 = 24\n");
}

int main(){
  cin >> N;

  if(N <= 3){ printf("NO\n"); return 0; }

  printf("YES\n");
  
  resp(N);
  
  return 0;
}
