#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
int N, M, K;

int recursao(int ind, int now, int macas);
int dist(int p1, int p2);


int x[1001];
int y[1001];
int t[1001];

int resposta[1001];

int main()
{

	while(cin >> N >> M >> K && (N != 0 && M != 0 && K != 0))
	{

		for(int i = 1; i <= K; i++)
		{
			cin >> x[i] >> y[i] >> t[i];
			//x[i]--; y[i]--; // tomanocu
			resposta[i] = -42;
		}
		//int meuX, meuY;

		cin >> x[0] >> y[0];
		resposta[0] = -1;
		//recursao(0,1,0);
		int max = -1;

		for(int i = K; i >= 0; i-- )
		{
			resposta[i] = 1;
			for(int j = i + 1; j <= K;j++ )
			{
				if( t[i] + dist(i,j) <= t[j] && resposta[i] < resposta[j] + 1 ) resposta[i] = resposta[j] + 1;
			}
		}
		for(int i = 0; i <= K; i++)
			if(resposta[i] > max) max = resposta[i];
		cout << resposta[0] -1 << endl;
		
	}
}

int recursao(int ind, int now, int macas)
{

	/*
	for(int i = ind + 1; i < K; i++)
	{
		if(t[ind] + dist(ind,i) <= t[i])
		{
			if(resposta[i]) return resposta[i];
			else return resposta[i] = recursao(i,)
		}
	}*/
	//printf("Pensando em sair de %d e ir para %d\n", ind, now);
	if(now > K) return 0;
	if(resposta[now] != -42) return resposta[now];
	else
	{
		int com = -1, sem = 0;
		if( t[ind] + dist(ind,now) <= t[now] ) {com = 1 + recursao(now, now+1, macas+1); sem = recursao(ind, now+1, macas);}
		else sem = 0;
		//sem = recursao(ind, now+1, macas);
		resposta[now] = sem < com? com : sem;
		printf("Saindo de %d, Sem a maçã %d fico com %d, e com ela fico com %d\n", t[ind],t[now], sem, com);
		if( sem < com) printf("Peguei a maça %d\n", t[now]);



		return resposta[now];
	}

}

int dist(int p1, int p2)
{
	int dx = x[p1] - x[p2];
	int dy = y[p1] - y[p2];
	if(dx<0) dx*=-1;
	if(dy<0) dy*=-1;

	return dx < dy? dy : dx;
}