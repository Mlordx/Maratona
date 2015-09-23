#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> group;
int min = 200000;
int total = 0;
int n = 0;

bool cmp(int i,int j) { return (i<j); }

int main(){

  while(scanf("%d",&N) != EOF){
    group.resize(N);
    for(int i = 0; i < N; i++) scanf("%d",&group[i]);
    sort(group.begin(),group.end(),cmp);

    for(int i = 0; i < N/2+1; i++) total += group[i]/2 +1;

    printf("%d\n",total);

  }

  return 0;
}
