#define INF 1 << 30
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<utility>

using namespace std;

int N,s,t;

int points[100000];
int sum1[100000],sum2[100000],serve1[200010],serve2[200010];

vector< pair<int,int> > matches;

int compare2(const void* a, const void* b){
  pair<int,int> A = *(pair<int,int>*)a;
  pair<int,int> B = *(pair<int,int>*)b;

  if(A.first < B.first) return -1;
  if(A.first > B.first) return 1;

  return 0;
} 


int main(){
  scanf("%d\n",&N);
  int lastWinner = 0;

  for(int i = 0; i < 2*N + 10; i++){ serve1[i] = serve2[i] = INF; }
  for(int i = 0; i < N; i++){ sum1[i] = sum2[i] = INF; }
  
  int cont,cont1,cont2;

  
  for(int i = 0; i < N; i++){
    
    cin >> points[i];

    if(i == N-1 && points[i] == 1) lastWinner = 1;
    else if( i == N-1 && points[i] == 2) lastWinner = 2;
    
    if(points[i] == 1) cont1++;
    else if(points[i] == 2) cont2++;

    if(i == 0){
      if(points[0] == 1){
	sum1[0] = 1;
	sum2[0] = 0;
      }
      else if(points[0] == 2){
	sum1[0] = 0;
	sum2[0] = 1;
      }
    }else{
      if(points[i] == 1){
	sum1[i] = 1 + sum1[i-1];
	sum2[i] = sum2[i-1];
      }else{
	sum1[i] = sum1[i-1];
	sum2[i] = 1 + sum2[i-1];	
      }    
    }
  }
  
  for(int i = 0; i  < N; i++){
    if(serve1[sum1[i]] == INF) serve1[sum1[i]] = i;
    if(serve2[sum2[i]] == INF) serve2[sum2[i]] = i;
  }
  
  
  for(int t = 1; t <= N; t++){
    int k = 0;
    int cont1 = cont2 = 0;
    int quebrou = 0;
    while(k < N){
      if(k == 0){
	if(serve1[t] == INF && serve2[t] == INF){ quebrou = 1;  break;}
	if(serve1[t] < serve2[t]){
	  k = serve1[t]+1;
	  cont1++;
	}
	else{
	  k = serve2[t]+1;
	  cont2++;
	}
      }else{
	if((sum1[k-1] +t >= N && sum2[k-1] +t >= N) || (serve1[sum1[k-1] + t] == INF && serve2[sum2[k-1] + t] == INF)){quebrou = 1; break;}
 
	if(serve1[sum1[k-1] + t] < serve2[sum2[k-1] + t]){
	  k = serve1[sum1[k-1] + t] +1;
	  cont1++;
	}
	else{
	  k = serve2[sum2[k-1] + t] +1;
	  cont2++;
	}
      }
    }
    if(!quebrou){
      if(cont1 > cont2 && lastWinner == 1){
	pair<int,int> bla = make_pair(cont1,t);
	matches.push_back(bla);
      }else if(cont2 > cont1 && lastWinner == 2){
	pair<int,int> bla = make_pair(cont2,t);
	matches.push_back(bla);
      }
    }
    
  }

  qsort(&matches[0],matches.size(),sizeof(pair<int,int>),compare2);
  
  printf("%d\n",matches.size());
  
  for(int i =0; i < matches.size(); i++) printf("%d %d\n",matches[i].first,matches[i].second);
  
  return 0;
}
