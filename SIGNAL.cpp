#include<iostream>
using namespace std;
int N, b, max= -1;
int Signal(int signal[]){
	int Max1, Max2;
	int vt1, mid= 0, vt2;
	while( signal[mid] <= b){
		mid++;
	};
	if( mid >= N-2)	return -1;
	else{
		Max1= signal[mid];
		vt1= mid;
		for(int i= mid + 1; i< N; i++)
	}
}
int main(){
	#INPUT
	cin>> N >> b;
	int signal[N];
	for (int i= 0; i< N; i++){
		cin>> signal[i];
	}
	#OUTPUT
	cout<< Signal(signal);
	return 0;
}
