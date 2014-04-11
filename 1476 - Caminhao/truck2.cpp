#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define MAXV 20000
#define LOG(x) ceil(log2(x))




int id[MAXV], tam[MAXV];

int u[MAXV], v[MAXV], peso[MAXV],pai[MAXV][LOG(MAXV)],nivel[MAXV],checado[MAXV];
vector<int> x, y, custo;

list<int> adj[];
list<int>::iterator it;



void UFInit(int n){
  for(int i = 0; i < n; i++){ id[i] = i; tam[i] = 1; checado[i] = -1;}
}

int UFFind(int a){
  while(id[a]!=a) a = id[a];
  return a;
}

void UFUnion(int a, int b){
  int Paia = UFFind(a), Paib = UFFind(b);

  if(tam[Paia] < tam[Paib]){
      id[Paia] = Paib;
      tam[Paib] += tam[Paia];
    }
  else{
      id[Paib] = Paia;
      tam[Paia] += tam[Paib];
    }
}

int N,M,S;
int ini,fim;
int tradutor[MAXV];


/******************************************************************************************/
/***************Inicialização da LCA*******************************************************/
void dfsR(int n,int v){
  checado[v] == 1;

  for(int i = 0; i < n; i++)
    for(it = adj[tradutor[v]].begin(); it!= adj[tradutor[v]].end(); it++){
      if(checado[*it] == -1){ dfsR(n,*it); }
      else {
	//	pai[v][0] = pai dele na arvore;
	for(int k = 1; k < LOG(n); k++)
	  pai[v][k] = pai[pai[v][k-1]][k-1];
      }
    } 
  
}

void LCAinit(int n){
  checado[tradutor[0]] == 1;
  for(int i = 0; i < LOG(n); i++){ pai[tradutor[0]][i] = 0; /*pai[i][0] = pai de fato dele*/} 
  for(int i = 1; i < n; i++) checado[tradutor[i]] = -1;
  dfsR(n,tradutor[1]);
}
/******************************************************************************************/
/******************************************************************************************/

int LCA(int n,int a, int b){
  int tmp;
  if(nivel[a] == nivel[b]) return pai[a][0];
  if(nivel[a] < nivel[b])
}




int compare(const void * a, const void * b)
{
  int a2 = peso[*(int*)a];
  int b2 = peso[*(int*)b];

  return (a2 > b2)? -1 : a2 < b2;
 
}
				       

int main(){
  tam = 0;
  while(cin >> N >> M >> S){

    for(int i = 0; i < M; i++){ cin >> u[i] >> v[i] >> peso[i];u[i]--; v[i]--; tradutor[i] = i;  }

    qsort(tradutor,M,sizeof(int),compare);   //ordena decrescentemente as arestas
   
    UFInit(N);

    for(int j = 0; j < M; j++){ // for que forma a árvore geradora de custo máximo
      if(UFFind(u[tradutor[j]]) != UFFind(v[tradutor[j]])){ 
	UFUnion(u[tradutor[j]],v[tradutor[j]]); 
      
	adj[u[tradutor[j]]].push_back(v[tradutor[j]]); // u é adjacente a v
	adj[v[tradutor[j]]].push_back(u[tradutor[j]]); // v é adjacente a u
      
	x[j] = u[j]; 
	y[j] = v[j];  
	custo[j] = peso[j];
      }
    }
  
  
    for(int i = 0; i < S; i++){
      cin >> ini >> fim;
      ini--;
      fim--;     
    }  
  }


  return 0;
}
