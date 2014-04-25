#include <cstdio>

#define D6 1000000
#define MAX 2



unsigned long long ID[2][2] = {{1,0},{0,1}};


// multiplica as matrizes A por B e guarda o resultado em A
void multiplica(unsigned long long a[MAX][MAX],unsigned long long b[MAX][MAX]){

  unsigned long long aux[MAX][MAX] = {{0}};

 for(int i = 0; i < MAX; i++)
   for(int j = 0; j < MAX; j++)
     for(int k = 0; k < MAX;k++)
        aux[i][j] += (a[i][k]%D6 * b[k][j]%D6)%D6;
     
 for(int i = 0;i < MAX; i++)
   for(int j = 0; j < MAX; j++)
     a[i][j] = aux[i][j]%D6;

}



void potencia(unsigned long long m[2][2],unsigned long long n,unsigned long long result[2][2]){
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

unsigned long long n,k,l;


int main()
{
  n = k = l = 0;
  while(scanf("%llu %llu %llu",&n,&k,&l)!= EOF){
    unsigned long long aux[2][2]= {{1,0},{0,1}};
    unsigned long long aux2[2][2] = {{0}};
    unsigned long long matrizBolada[2][2] = {{0,l},{1,k}};
    unsigned long long esquecida[2][2] = {{1,k},{0,0}};
    potencia(matrizBolada, n/5, aux);
    multiplica(esquecida, aux);
    printf("%06llu\n", esquecida[0][0]);
    
    
  }
  return 0;
}
