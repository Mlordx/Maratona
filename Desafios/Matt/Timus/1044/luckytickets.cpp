#include <bits/stdc++.h>

int n;

using namespace std;

int main(){
  int n = 0;
  while(scanf("%d",&n) != EOF){
    if(n%2 != 0){ printf("0\n"); } /*pré-computados*/
    if(n == 2){ printf("10\n"); }
    if(n == 4){ printf("670\n");  }
    if(n == 6){ printf("55252\n");  }
    if(n == 8){ printf("4816030\n"); }
  }
  
  return 0;
}
