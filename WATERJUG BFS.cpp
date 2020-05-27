 #include<iostream>
using namespace std;
int n, H, M , dem =0;

int Maxleft(int Ar[], int i, int j){
	int sum= 0;
	for(int k= j; k>=i;k--){
		sum+= Ar[k];
	};
	return sum; 
}

int Maxright(int Ar[], int i, int j){
	int sum= 0;
	for(int k=i; k<=j; k++){
		sum+= Ar[k];
	};
	return sum;
}

void Max(int Ar[], int i, int j){
	if(i==j){
		if((Ar[i] >= H)&& (Ar[i] <= M)){
			dem++;
		};
		return;
	};
	int m;
	m= (i+j)/2;
	Max(Ar, i, m);
	Max(Ar, m+1, j);
	long sum;
	for( int k= m; k >= i; k--){
		for( int h= m+1; h <= j; h++){
			sum= Maxleft(Ar, k, m) + Maxright(Ar, m+1, h);
			if( (sum >= H) && (sum <= M))	dem++;
		}
	};
	return ;
}

int main(){
	cin>>n>>H>>M;
	int Ar[n];
	for(int i=0;i<n;i++) cin>>Ar[i];
	Max(Ar, 0, n-1);
	cout<<dem;
	return 0;
}
