#include<bits/stdc++.h>

using namespace std;

int N,M;

typedef struct role{
  int a,b;
  int ind;
}Role;

int cmp(const void* a, const void* b){
  Role A = *(Role*)a;
  Role B = *(Role*)b;
  return (A.a == B.a ? A.ind < B.ind : A.a > B.a );
}

bool cmp2(const Role& A, const Role& B){
    return (A.a == B.a ? A.ind > B.ind : A.a < B.a );
}


Role musical[200000];
int k[200000];
set< pair<int,int> > actors;
vector<int> part(100000);

int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    int a,b;
    cin >> a >> b;
    Role bla;
    bla.a = a;
    bla.b = b;
    k[i] = -1;
    bla.ind = i;
    musical[i] = bla;
  }

  cin >> M;

  for(int i = N; i < N+M; i++){
    int a,b,x;
    cin >> a >> b >> x;
    Role bla;
    bla.a = a;
    bla.b = b;
    k[i] = x;
    bla.ind = i;
    musical[i] = bla;
  }

  sort(musical,musical+N+M,cmp2);

  int x = 0;


  for(int i = 0; i < N+M; i++){
    
    Role aux = musical[i];

    if(k[aux.ind] == -1){
      
      auto a = actors.lower_bound(make_pair(aux.b, INT_MIN));      
      if( a == actors.end()){ printf("NO\n"); return 0; }
      part[aux.ind] = (*a).second-N+1;
      k[(*a).second]--;
      if(k[(*a).second] == 0) actors.erase(a);
      
    }else{
      actors.insert(make_pair(aux.b,aux.ind));
    }
  }
  
  printf("YES\n");
  for(int i = 0; i < N-1; i++) printf("%d ",part[i]);
  printf("%d\n",part[N-1]);
  
  return 0;
}
