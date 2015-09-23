#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int K;

#define MAXV 100001

int id[MAXV], tam[MAXV];


vector< vector<int> > valor;

void UFInit(int n)
{
  for(int i = 0; i < n; i++){ id[i] = i; tam[i] = 1;}

}

int UFFind(int a)
{
  if (id[a]!=a)
    id[a] = UFFind(id[a]);
  return id[a];
}

void UFUnion(int a, int b)
{
  int Paia = UFFind(a), Paib = UFFind(b);

  if(tam[Paia] < tam[Paib])
    {
      id[Paia] = Paib;
      tam[Paib] += tam[Paia];
    }
  else
    {
      id[Paib] = Paia;
      tam[Paia] += tam[Paib];
    }
}


int main(){
  while(scanf("%d",&K)!=EOF){
    int bla = 0;
    UFInit(100001);
    valor.resize(K);
    valor.clear();
    
    long long i = 2, menos_i = (2*K-2)%K;
    
    while(1){
      vector<int> novos;
      if(bla) break;

      
      int u = menos_i; menos_i = (menos_i+(K-1))%K;
      
      for(vector<int>::iterator a = valor[u].begin(); a!= valor[u].end(); a++){
	int j = (*a);
	if(UFFind(i) != UFFind(j)){ UFUnion(i,j); novos.push_back(j); }
	  else{
	    printf("%d\n",i);
	    bla = 1;
	    return 0;
	  }
      }
      
      if(bla) break;

      int j = K - (i%K)*(i%K)%K;
      
      while (j < i) {
	if(!binary_search(novos.begin(),novos.end(),j)){
	  if(!binary_search(valor[u].begin(),valor[u].end(),j) && UFFind(i) != UFFind(j)){UFUnion(i,j);} 
	  else{
	    printf("%d\n",i);
	    bla = 1;
	    return 0;
	  }
	}
	j += K;
      }

      int t = ((i%K)*(i%K))%K;
      valor[t].push_back(i);
      
      i++;
      if(bla) break;
    }
  }
  return 0; 
}
