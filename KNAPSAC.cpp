#include<iostream>
using namespace std;
int best=0;
int n,b;
void duyet(int a[], int c[], int i, int sum, int gt){
	if( i> n-1){
		if(gt > best)	best= gt;
		return;
	};
	duyet(a, c, i+1,sum ,gt);
	if(sum + a[i] <= b){
		duyet(a, c, i+1, sum+a[i], gt+c[i]);
	};
}
int main(){
	cin>>n>>b;
	int a[n],c[n];
	for(int i=0; i<n; i++)	cin>>a[i]>>c[i];
	int i=0, sum=0, gt=0;
	duyet(a, c, i, sum, gt);
	cout<<best;
	return 0;
}
