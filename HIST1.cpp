#include<iostream>

#include<vector>
#include<bits/stdc++.h>
using namespace std;
int A[1000001];
long long duyet(int N){
	int L[N];
	int R[N];
	vector< int > stack;
	for( int i= 0; i< N; i++){
		if( stack.size() == 0 ){
			L[i] = i;
			stack.push_back(i);
		} else{
			int j= stack.size()-1;
			while( ( j >= 0) && ( A[i] <= A[stack.at(j)] ) ){
				stack.erase(stack.begin() + j);
				j--;
			}
			if( j >= 0) {
				L[i]= stack.at(j) + 1;
				stack.push_back(i);
			}
			else{
				L[i]= 0;
				stack.push_back(i);
			}
		}
	};
	stack.clear();
	for( int i= N-1; i>= 0; i--){
		if( stack.size() == 0 ){
			R[i] = i;
			stack.push_back(i);
		} else{
			int j= stack.size()-1;
			while( ( j >= 0) && ( A[i] <= A[stack.at(j)] ) ){
				stack.erase(stack.begin() + j);
				j--;
			}
			if( j >= 0) {
				R[i]= stack.at(j) - 1;
				stack.push_back(i);
			}
			else{
				R[i]= N-1;
				stack.push_back(i);
			}
		}
	}
	long long max= 0;
	for( int i= 0; i< N; i++){
		if( max < A[i] * (R[i] - L[i] +1)) max= A[i] * (R[i] - L[i] +1);
	}
	return max;
}

int main(){
	//input
	ifstream in(" Input.txt");
	ofstream out(" Out1.txt");
	vector< long long > kq;
	while(true){
		int N;
		in>>N;
		if( N == 0) break;
		for( int i= 0; i< N; i++) in>> A[i];
		kq.push_back(duyet(N));
	};
	for( int i= 0; i< kq.size(); i++){
		out<<kq.at(i);
		out<<"\n";
	}
	return 0;
}
