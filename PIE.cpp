#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
//#define M_PI   3.14159265358979323846264338327950288;

double ketqua(int R[], int N, int F, double pi){
	sort(R, R + N);
	double lo= 0, hi= 0, mid;
	for( int i= 0; i< N; i++)	hi += pi * R[i];
	hi = hi/N;
	for( int i=0; i< 100; i++){
		mid= (lo + hi)/2;
		int count= 0;
		for( int i= N-1; i>= 0 && count <= F; --i)
			count += (int) floor( pi * R[i] / mid);
		if( count > F) lo = mid;
		else hi = mid;
	};
	return mid;
}
int main(){
// INput
	int so;
	double pi= 3.1415926;
	cin>>so;
	int N, F;
		int R[N];
		cin>>N >> F;
		for(int J= 0; J< N; J++)cin>> R[J];
		for(int J= 0; J< N; J++)cout<<R[J]<<"\t";
	/*for(int I=0; I< so; I++){
		int N, F;
		int R[N];
		cin>>N >> F;
		for(int J= 0; J< N; J++)cin>> R[J];
		for(int J= 0; J< N; J++)R[J]= R[J] * R[J];
		for(int J= 0; J< N; J++)cout<<R[J]<<"\t";
	}*/
	return 0;
}
