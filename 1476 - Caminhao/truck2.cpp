#include <iostream>
#include <cstdlib>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;

#define MAXV 20000
#define LOG(x) ceil(log2(x))

int id[MAXV], tam[MAXV];

int u[MAXV], v[MAXV], peso[MAXV],pai[MAXV][MAXV],nivel[MAXV],checado[MAXV];
int x[MAXV], y[MAXV], custo[MAXV],custoPai[MAXV];

list<int> adj[MAXV];
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
void dfsR(int n,int V,int Ant,int p){
  checado[V] = 1;
  for(int i = 0; i < n; i++)

    while(!adj[V].empty()){
      it = adj[V].begin();
      if(checado[*it] == -1){ dfsR(n,*it,V,p+1); }
      else {
	pai[V][0] = Ant; //o pai de alguem é o anterior à ele, sendo o anterior da raiz ela mesma
	nivel[V] = p;
	for(int k = 1; k < LOG(n); k++)
	  pai[V][k] = pai[pai[V][k-1]][k-1];
	adj[V].pop_front();
      }
    } 
  
}

void LCAinit(int n){
  for(int i = 0; i < n; i++) checado[i] = -1;
  for(int i = 1; i < n; i++) nivel[i] = 0;
  dfsR(n,0,0,1);
}
/******************************************************************************************/
/******************************************************************************************/

int LCA(int n,int a, int b){
  int tmp;

  if(nivel[a] < nivel[b]){
    tmp = a;
    a = b;
    b = tmp;
  }

  for(int i = LOG(nivel[a]); i >= 0; i--)
    if(nivel[a] - (1 << i)/*2^i*/ >= nivel[b])
      a = pai[a][i];

  for(int i = LOG(nivel[a]); i >= 0; i--)
    if(pai[a][i] != pai[b][i])
      a = pai[a][i], b = pai[b][i];

  return pai[a][0];
}

/******************************************************************************************/
/******************************************************************************************/

int compare(const void * a, const void * b)
{
  int a2 = peso[*(int*)a];
  int b2 = peso[*(int*)b];

  return (a2 > b2)? -1 : a2 < b2;
 
}
				       

int main(){

  while(cin >> N >> M >> S){
    for(int i = 0; i < M; i++){ cin >> u[i] >> v[i] >> peso[i];u[i]--; v[i]--; tradutor[i] = i;}

    qsort(tradutor,M,sizeof(int),compare);   //ordena decrescentemente as arestas
   
    UFInit(N);

    for(int j = 0; j < M; j++){ // for que forma a árvore geradora de custo máximo
      int U = u[tradutor[j]];
      int V = v[tradutor[j]];

      if(UFFind(U) != UFFind(V)){ 

	UFUnion(U,V); 

	cout << "adicionei a aresta " << U+1 << "-" << V+1 << " custo: " << peso[tradutor[j]] << endl;
	x[tradutor[j]] = U; 
	y[tradutor[j]] = V;
	custo[tradutor[j]] = peso[tradutor[j]];

	adj[U].push_back(V); // u é adjacente a v
	adj[V].push_back(U); // v é adjacente a u
      }
    }
  
    LCAinit(N);

    for(int i = 0; i < S; i++){
      cin >> ini >> fim;
      ini--;
      fim--;   

      cout << LCA(N,ini,fim) << endl;  
    }  
  }


  return 0;
}
  

