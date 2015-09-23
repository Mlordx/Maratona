#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;

int N;
vector<int> levels;

int main(){
  while(scanf("%d",&N) != EOF ){
    levels.clear();
    levels.resize(N);
    for(int i=0;i<N;i++) levels[i] = 0;

    int x,y;

    scanf("%d",&x);
    for(int i = 0; i<x; i++){
      scanf("%d",&y);
      levels[y-1] = 1;
    }

    scanf("%d",&x);
    for(int i = 0; i<x; i++){
      scanf("%d",&y);
      levels[y-1] = 1;
    }
    
    int guy = 1;
    
    for(int i=0;i<N;i++) if(levels[i] == 0) guy = 0;
	
    if(guy) printf("I become the guy.\n");
    else printf("Oh, my keyboard!\n");

  }

  return 0;
}
