#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 2
 
 
unsigned long long mod = -1;

// multiplica as matrizes A por B e guarda o resultado em A
void multiplica(unsigned long long a[MAX][MAX],unsigned long long b[MAX][MAX],int modulo){
  unsigned long long aux[MAX][MAX] = {{0}};

  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < MAX; j++)
      for(int k = 0; k < MAX;k++)
	aux[i][j] += (a[i][k]%modulo * b[k][j]%modulo)%modulo;
            
  for(int i = 0;i < MAX; i++)
    for(int j = 0; j < MAX; j++)
      a[i][j] = aux[i][j]%modulo;
}
 
void potencia(unsigned long long m[MAX][MAX],unsigned long long n,unsigned long long result[MAX][MAX],int modulo){
  result[0][0]=result[1][1]=1;
  result[1][0]=result[0][1]=0;
 
  while(n > 0){
    if(n%2 == 0){
      multiplica(m,m,modulo);
      n /= 2;
    }
    else{
      multiplica(result,m,modulo);
      n--;
    }
  }
} 
 
unsigned long long fibonacci[MAX][MAX];
unsigned long long result[MAX][MAX];
 

std::vector<int> paraBinario(unsigned long long numero){
  std::vector<int> bin;
  unsigned long long aux = numero;
  while(numero!=0){
    bin.push_back(numero & 1);
    numero >>= 1;
  }

  return bin;
}


unsigned long long A[2000][MAX][MAX] = {{{0}}};
unsigned long long A2[2000][MAX][MAX] = {{{0}}};

void inicializaAi(int modulo){
  A[0][0][0] = 1;
  A[0][0][1] = 1;
  A[0][1][0] = 1;
  A[0][1][1] = 0;

  for(int i = 1; i <= 1000;i++){
    A[i][0][0] = A[i-1][0][0];
    A[i][0][1] = A[i-1][0][1];
    A[i][1][0] = A[i-1][1][0];
    A[i][1][1] = A[i-1][1][1];
    multiplica(A[i],A[i],modulo);
  }
}
 
void inicializaA2i(int modulo){
  A2[0][0][0] = 1;
  A2[0][0][1] = 1;
  A2[0][1][0] = 1;
  A2[0][1][1] = 0;

  for(int i = 1; i <= 1000;i++){
    A2[i][0][0] = A2[i-1][0][0];
    A2[i][0][1] = A2[i-1][0][1];
    A2[i][1][0] = A2[i-1][1][0];
    A2[i][1][1] = A2[i-1][1][1];
    multiplica(A2[i],A2[i],modulo);
  }
}
 
unsigned long long calculafib(unsigned long long n,int modulo){
  if(n == 0) return 0;
  if(n == 1) return 1;
  if(n == 2) return 1;
  unsigned long long aux[MAX][MAX];
  aux[0][0] = aux[1][1] = 1;
  aux[0][1] = aux[1][0] = 0;

  std::vector<int> binario = paraBinario(n);

  for(int i = 0; i < binario.size(); i++){
    if(binario[i]) multiplica(aux,A[i],modulo);
  }
  return aux[0][1];
}
unsigned long long calculafib2(unsigned long long n,int modulo){
  if(n == 0) return 0;
  if(n == 1) return 1;
  if(n == 2) return 1;
  unsigned long long aux[MAX][MAX];
  aux[0][0] = aux[1][1] = 1;
  aux[0][1] = aux[1][0] = 0;

  std::vector<int> binario = paraBinario(n);

  for(int i = 0; i < binario.size(); i++){
    if(binario[i]) multiplica(aux,A2[i],modulo);
  }
  return aux[0][1];
}
 
  
int achaPeriodo(int m){
  int x=3;
  unsigned long long fib1,fib2;
  fib1=fib2=0;
  if(m == 2) return 2;
  int sai = 0;
  
    if(m%1000 != 0){ //caso seja da forma 10^n com n > 2, o periodo de pisano é da forma 15*10^(n-1), caso contrario eu acho o periodo.
      while(1){
	fib1 = calculafib(x,m);
	if(fib1 == 1){
	  fib2 = calculafib(x+1,m);
	  if(fib2 == 1) return x-1;
	}
	x++;
      }
    }
    else return 15 * pow(10,log10(m)-1);
}

int main (){
  unsigned long long n = 0;
  unsigned long long m = 0;
  int c = 0;

  while(scanf("%llu %llu",&n,&m) != EOF){
    //descobrir o tamanho do periodo de pisano
    ///////////////////////////////////////
    int modulo = 0;

    inicializaAi(m);//<- Ai tem o fib mod m
    modulo = achaPeriodo(m);
    inicializaAi(modulo);// <- A2i tem o fib mod periodo
    unsigned long long hue = calculafib(n,modulo);
    inicializaAi(m);
    printf("%llu\n",calculafib(hue,m));
     
  }
    return 0;
}
