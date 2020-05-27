 #include<iostream>
using namespace std;
int n;

int Maxleft(int Ar[], int i, int j){
	int max= Ar[j];
	long sum= 0;
	for(int k= j; k>=i;k--){
		sum+= Ar[k];
		if(sum >= max) max=sum;
	};
	return max;
}
int Maxright(int Ar[], int i, int j){
	int max=Ar[i];
	long sum= 0;
	for(int k=i; k<=j; k++){
		sum+= Ar[k];
		if(sum > max) max=sum;
	};
	return max;
}
int Max(int Ar[], int i, int j){
	if(i==j)return Ar[i];
	int m= (i+j)/2;
	long ml= Max(Ar, i, m);
	long mr= Max(Ar, m+1, j);
	long Maxl= Maxleft(Ar, i, m);
	long Maxr= Maxright(Ar, m+1,j);
	long max= 0;
	if(ml> mr)	max= ml;
		else max= mr;
	if(max < Maxl+Maxr)	max= Maxl+ Maxr;
	return max;
}

int main(){
	cin>>n;
	int Ar[n];
	for(int i=0;i<n;i++) cin>>Ar[i];
	cout<< Max(Ar, 0, n-1);
	return 0;
}
