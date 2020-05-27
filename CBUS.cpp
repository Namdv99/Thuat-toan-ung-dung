#include<iostream>
using namespace std;
int n,k, g= 10000000;

void duyet(int *chiphi, int X[], int mark[], int i, int hk, int sum){
	if( i == (2*n + 1) ){
		if( ( sum + chiphi[X[2*n] * (2*n + 1)] )< g)
			g = sum + chiphi[X[2*n] * (2*n +1)];
		return;
	};
	for(int j= 1; j< 2*n+1; j++){
		if(!mark[j] & (hk <= k)){
			if(j <= n){
				mark[j]= 1;
				X[i]= j;
				hk++;
				duyet((int *)chiphi, X, mark, i+1, hk, sum+ chiphi[X[i-1]*(2*n+1) + X[i]]);
				hk--;
				mark[j]= 0;
			}else{
				int kt= 0;
				for(int t=0; t< i; t++)	if(X[t]== (j-n))	kt++;
				if(kt){
					mark[j]= 1;
					X[i]= j;
					hk--;
					duyet((int *)chiphi, X, mark, i+1, hk, sum+ chiphi[X[i-1]*(2*n+1) + X[i]]);
					hk++;
					mark[j]= 0;
				}
			}
		}
	}
}

int main(){
	// Input
	cin>>n>>k;
	int chiphi[2*n+1][2*n+1];
	for(int i=0; i<= 2*n; i++)
		for(int j=0; j<= 2*n; j++)	cin>> chiphi[i][j];
	
	//Goi ham de quy
	int X[2*n+1], mark[2*n+1];
	X[0]=0;
	for(int i=0; i< 2*n+1; i++)	{
		mark[i]= 0;
	}
	duyet(*chiphi, X, mark, 1, 0, 0);
	cout<<g;
	return 0;
}
