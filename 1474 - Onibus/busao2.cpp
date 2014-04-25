#include <cstdio>

#define D6 1000000
#define MAX 2



 long long ID[2][2] = {{1,0},{0,1}};


// multiplica as matrizes A por B e guarda o resultado em A
void multiplica( long long a[MAX][MAX], long long b[MAX][MAX]){
 long long aux[MAX][MAX] = {{0}};



 for(int i = 0; i < MAX; i++)
   for(int j = 0; j < MAX; j++)
     for(int k = 0; k < MAX;k++)
        aux[i][j] += (a[i][k]%D6 * b[k][j]%D6)%D6;
     
 for(int i = 0;i < MAX; i++)
   for(int j = 0; j < MAX; j++)
     a[i][j] = aux[i][j]%D6;

}



void potencia( long long m[2][2], long long n, long long result[2][2]){
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

 long long n,k,l;


int main()
{
  n = k = l = 0;
  while(scanf("%lld %lld %lld",&n,&k,&l)!= EOF){
     long long aux[2][2]= {{0}};
     long long aux2[2][2] = {{0}};
     long long matrizBolada[2][2] = {{0,l},{1,k}};
     long long esquecida[2][2] = {{1,k},{0,0}};
    potencia(matrizBolada, n/5, aux);
    multiplica(esquecida, aux);
    printf("%06lld\n", esquecida[0][0]);
    
    
  }


  return 0;
}
