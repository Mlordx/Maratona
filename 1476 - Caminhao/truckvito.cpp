#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
 #include <cstdio>


using namespace std;

#define MAXV 200200
#define MAXS 50020
#define PESINF 100010

typedef struct aresta{
  int v;
  int peso;
} Aresta;


int id[MAXV], tam[MAXV];

list<Aresta> adj[MAXV];

int u[MAXV], v[MAXV], peso[MAXV], depth[MAXV], prnt[MAXV][30], pesMax[MAXV][30];

int obj[MAXS][2];


int minHue(int a, int b)
{
  return a < b? a : b;
}


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
int ini,fim, maxDepth;
int tradutor[MAXV];


int compare(const void * a, const void * b)
{
  int a2 = peso[*(int*)a];
  int b2 = peso[*(int*)b];

  return (a2 > b2)? -1 : a2 < b2;
 
}

void addEdge(int u, int v, int wh)
{
  Aresta a;

  a.peso = wh;
  a.v = v;
  adj[u].push_back(a);
  a.v = u;
  adj[v].push_back(a);
}

int dfsR(int v, int depth2)
{
  
  depth[v] = depth2;
  if(depth2 > maxDepth) maxDepth = depth2;
  for(list<Aresta>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
  {
    Aresta a = (Aresta) (*i);
    int u = a.v;
    if(prnt[u][0] == -1)
    {
      
      prnt[u][0] = v;
      pesMax[u][0] = a.peso;
      dfsR(u,depth2 + 1);
    }
  }


}


int LCA(int u, int v)
{
  int temp, lg;
  int maxPeso = 100010;
  if(depth[u] > depth[v] ){ temp = u; u = v; v = temp; }

  //cout << "HUE" << depth[u] << endl;
  // Agora v tem depth maxíma

  //Vamos calcular o chão do log de depth[v]

  for(lg = 1; 1 << lg <= depth[v]; lg++);
  lg--;

  
  //Vamos subir v para o nível de u
  for(int i = lg; i >=0; i--)
    if(depth[v] - (1 << i) >= depth[u])
      {
       // printf("%d ---~~~-- \n",i);
       // cout << "SUBINDO:" << depth[v] <<"|||" <<v+1<<" -----> " <<prnt[v][i] + 1 <<"(" << minHue(pesMax[v][i], maxPeso)<< ")" <<endl;
        maxPeso = minHue(pesMax[v][i], maxPeso);
        v = prnt[v][i];
        
      }

      
  if(v == u) return maxPeso; // Olha só, já achamos o LCA

  //Agora vamos subindo os dois até acharmos um pai em comum.

  for(int i = lg; i >=0; i--)
    if(prnt[v][i] != -1 &&  prnt[v][i] != prnt[u][i])
      { maxPeso = minHue(maxPeso,minHue(pesMax[v][i], pesMax[u][i])); v = prnt[v][i]; u = prnt[u][i];} //tinha que pegar maxPeso ANTES de mudar v e u, cone.


   
    return minHue(maxPeso, minHue(pesMax[v][0], pesMax[u][0]));




}





int main(){
  int resp;
  
  while(cin >> N >> M >> S){

    maxDepth = 0;
    resp = 0;

    for(int i = 0; i < M; i++){ 
      cin >> u[i] >> v[i] >> peso[i];
      u[i]--;
      v[i]--;
      depth[u[i]] = depth[v[i]] =-1;
      
      //addEdge(u[i],v[i], peso[i]);
      tradutor[i] = i; 
     }

    qsort(tradutor,M,sizeof(int),compare);   
   
    for(int i = 0; i < S; i++){
      cin >> obj[i][0] >> obj[i][1];
      obj[i][0]--;
      obj[i][1]--;     
    }


    UFInit(N);

    //Inicializa matriz prnt
    for (int i = 0; i < N; i++)
          for (int j = 0; 1 << j < N; j++)
              {prnt[i][j] = -1; pesMax[i][j] = -1; adj[i].clear();}
     
    int cont = 1; //Numero de árvores que demos union
     

     // Forma spanning tree
    for(int j = 0; cont < N && j < M; j++){
      if(UFFind(u[tradutor[j]]) != UFFind(v[tradutor[j]]))
        {
          cont++;
          addEdge(u[tradutor[j]],v[tradutor[j]], peso[tradutor[j]]);
          UFUnion(u[tradutor[j]],v[tradutor[j]]);
           resp = peso[tradutor[j]];
         }
      
    }

    prnt[u[0]][0] = u[0];
    pesMax[u[0]][0] = PESINF;

    dfsR(u[0],0);


    // Vamo calcular o pai de todo mundo com prog dinâmica

    for (int j = 1; 1 << j <= maxDepth; j++)
         for (int i = 0; i < N; i++)
             if (prnt[i][j - 1] != -1)
                {

                   prnt[i][j] = prnt[prnt[i][j - 1]][j - 1];
                   pesMax[i][j] = minHue(pesMax[prnt[i][j-1]][j-1], pesMax[i][j-1]);
                }


    for(int i = 0; i < S; i++)
      {cout << LCA(obj[i][0], obj[i][1]) << endl;}
     
   
  }
     
  return 0;
}
