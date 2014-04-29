#include <cstdio>


#define MAXN 100004
#define MAXV 1000000000



int main()
{
	int N,L;
	int vetor[MAXV];


	int temp;
	int max = -1;
	int minZ, zTemp;
	int i,j;

	for(i = 0; i < MAXV; i++) vetor[i] = 0;

	while(scanf("%d %d\n", &N, &L)!= EOF && N != L && N != 0)
	{
		max = -1;
		for(i = 0; i < L; i++)
		{
			int temp2;
			scanf("%d", &temp);
			vetor[temp2 = temp-1] = 1;
			if(temp2 > max) max = temp2;
		}

		
		i = 0;
		for(j = 0; j < N; j++)
			if(!vetor[i]) minZ++;
		zTemp = minZ;
		for(i = 1; j < max; i++, j++)
		{
			if(!vetor[i-1]) zTemp--;
			if(!vetor[j]) zTemp++;
			if(zTemp <  minZ) minZ = zTemp;
		}

		printf("%d\n", zTemp);
		for(i = 0; i < max; i++) vetor[i] = 0;

	}

	return 0;
}