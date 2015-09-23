#include<cstdio>
#include<vector>

using namespace std;

vector<int> height;
int N;
int m = -120000;
int M = 200000;

int main(){

  while(scanf("%d",&N) != EOF){
    m = 299999;
    M = -200000;
    height.resize(N);
    
    for(int i = 0; i < N; i++) scanf("%d",&height[i]);

    for(int i = 1; i < N-1; i++){
      M = -200000;
      for(int j = 0; j < N-1; j++){
	
	
	if(j != i && j+1!=i ){ if( height[j+1] - height[j] > M) M = height[j+1] - height[j]; }
	else if(j == i){ if( height[j+1] - height[j-1] >  M) M = height[j+1] - height[j-1]; }
	else if(j+1 == i){if( height[j+2] - height[j] > M) M = height[j+2] - height[j];  }

      }
	if( M < m) m = M;
	
    }
      printf("%d\n",m);
  }
  return 0;    
}
