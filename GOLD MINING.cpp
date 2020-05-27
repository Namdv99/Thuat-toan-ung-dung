#include<iostream>
using namespace std;
int N, L1, L2;
int main(){
	cin>>N>>L1>>L2;
	unsigned int a[N];
	for( int i= 0; i< N; i++){
		cin>>a[i];
	};
	unsigned int F[N];
	for( int i= 0; i< N; i++){
		F[i]= a[i];
	};
	for ( int i= L1; i< N; i++){
		for( int j = i- L1; j >= i- L2; j--){
			if( j < 0) break;
			else{
				F[i]= max(F[i], F[j] + a[i]);
			};
		}
	};
	int Max= F[0];
	for( int i= 1; i< N; i++){
		if( F[i] > Max) Max= F[i];
	};
	cout<<Max;
	return 0;
}
