#include <cstdio>
#include <cmath>

unsigned long long a,b;


unsigned long long nMaisProximo(unsigned long long n){
  int i; 
  float bla1 = (1+sqrt(5))/2;
  float bla2 = (1-sqrt(5))/2;
  float bla3 = sqrt(5)*n;

  for(i = 0; ;i++)
    if( (unsigned long long)(pow(bla1,i)-pow(bla2,i)) ==   (unsigned long long)(bla3)   ) return i;
    else if (  (unsigned long long)(pow(bla1,i+1)-pow(bla2,i+1)) >   (unsigned long long)(bla3) ) return i+1;
}

unsigned long long nMaisProximo2(unsigned long long n){
  int i; 
  float bla1 = (1+sqrt(5))/2;
  float bla2 = (1-sqrt(5))/2;
  float bla3 = sqrt(5)*n;

  for(i = 0; ;i++)
    if( (unsigned long long)(pow(bla1,i)-pow(bla2,i)) <=   (unsigned long long)(bla3) && (unsigned long long)(pow(bla1,i+1)-pow(bla2,i+1)) >   (unsigned long long)(bla3)  ) return i;
}





int main(){
  a=b=0;

  while( scanf("%llu %llu",&a,&b) && (a!=0 && b!= 0) ){
    if(a == b){printf("0\n"); break; }
    unsigned long long k = nMaisProximo(a);
    unsigned long long t = nMaisProximo2(b);

    printf("%llu\n",t-k+1);

  }

  return 0;
}
