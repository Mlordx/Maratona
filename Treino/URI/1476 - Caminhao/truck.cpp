#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

#define MAXV 2000000


int id[MAXV], tam[MAXV];

int u[MAXV], v[MAXV], peso[MAXV];


void UFInit(int n)
{
  for(int i = 0; i < n; i++){ id[i] = i; tam[i] = 1;}

}

int UFFind(int a)
{
  while(id[a]!=a) a = id[a];
  return a;
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

int N,M,S;
int ini,fim;
int tradutor[MAXV];


int compare(const void * a, const void * b)
{
  int a2 = peso[*(int*)a];
  int b2 = peso[*(int*)b];

  return (a2 > b2)? -1 : a2 < b2;
 
}

int resp;

int main(){
  resp = 0;
  while(cin >> N >> M >> S){

    for(int i = 0; i < M; i++){ cin >> u[i] >> v[i] >> peso[i];u[i]--; v[i]--; tradutor[i] = i;  }

    qsort(tradutor,M,sizeof(int),compare);   
   
    for(int i = 0; i < S; i++){
      cin >> ini >> fim;
      ini--;
      fim--;

      UFInit(N);
     
     
      for(int j = 0; j < M; j++){
    if(UFFind(u[tradutor[j]]) != UFFind(v[tradutor[j]])){ UFUnion(u[tradutor[j]],v[tradutor[j]]); resp = peso[tradutor[j]]; }
        if(UFFind(ini) == UFFind(fim)) break;
      }
      cout << resp << endl;
     
     
    }
   
  }
     
  return 0;
}
