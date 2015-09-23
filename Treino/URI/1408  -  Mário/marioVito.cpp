#include <cstdio>
#include <cstdlib>

#include <vector>

#define MAXN 100004
#define MAXV 1000000000

using namespace std;

vector<int> v(MAXN);


int main()
{
	int N,L;


	while(scanf("%d %d\n",&N, &L) != EOF & !(N == 0 && L == 0))
	{
		v.resize(L);
		for(int i = 0; i < L; i++) 
			scanf("%d", &v[i]);

		vector<int>::iterator bg = v.begin();
		vector<int>::iterator end = bg + L;
		int vasTemp, vasMax = 0;

		//vector<int>::iterator it;

		for(int i = 0; i < L; i++)
		{
			int bla = v[i]+N-1;
			vector<int>::iterator lb = lower_bound(v.begin(),end,bla);

			vasTemp = distance(v.begin(),lb) - i; // Relaxa q eu manjo
			printf("LB: %d || v[i]: %d || dist: %d\n",lb , v[i], vasTemp);
			if(vasTemp > vasMax)
				vasMax = vasTemp;
		}

		printf("%d\n", N - vasMax);

	}




	return 0;
}