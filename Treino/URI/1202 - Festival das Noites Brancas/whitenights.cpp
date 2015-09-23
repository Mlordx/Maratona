#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 2
 
unsigned long long mod = 1000;

// multiplica as matrizes A por B e guarda o resultado em A
void multiplica(unsigned long long a[MAX][MAX],unsigned long long b[MAX][MAX]){
  unsigned long long aux[MAX][MAX] = {{0}};

  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < MAX; j++)
      for(int k = 0; k < MAX;k++)
	aux[i][j] += (a[i][k]%mod * b[k][j]%mod)%mod;
            
  for(int i = 0;i < MAX; i++)
    for(int j = 0; j < MAX; j++)
      a[i][j] = aux[i][j]%mod;
}
 
void potencia(unsigned long long m[MAX][MAX],unsigned long long n,unsigned long long result[MAX][MAX]){
  result[0][0]=result[1][1]=1;
  result[1][0]=result[0][1]=0;
 
  while(n > 0){
    if(n%2 == 0){
      multiplica(m,m);
      n /= 2;
    }
    else{
      multiplica(result,m);
      n--;
    }
  }
} 
 
unsigned long long fibonacci[MAX][MAX];
unsigned long long result[MAX][MAX];
 

unsigned long long A[10001][MAX][MAX] = {{{0}}};

void inicializaAi(){
  A[0][0][0] = 1;
  A[0][0][1] = 1;
  A[0][1][0] = 1;
  A[0][1][1] = 0;

  for(int i = 1; i <= 10000;i++){
    A[i][0][0] = A[i-1][0][0];
    A[i][0][1] = A[i-1][0][1];
    A[i][1][0] = A[i-1][1][0];
    A[i][1][1] = A[i-1][1][1];
    multiplica(A[i],A[i]);
  }
}
 
int main (){
  unsigned long long n = 0;
  char m[10001];
  inicializaAi();
  unsigned long long aux[MAX][MAX];

  while(scanf("%llu\n",&n) != EOF){
    for(int i = 0; i < n; i++){
      scanf("%s",m);
      aux[0][0] = aux[1][1] = 1;
      aux[0][1] = aux[1][0] = 0;
      int j = 0;

      for(int k = strlen(m)-1 ; k >= 0;k--){
	if(m[k] == '1' ) multiplica(aux,A[j]);
	j++;
      }
      printf("%03llu\n",aux[0][1]);
    }
  }
  return 0;
}
