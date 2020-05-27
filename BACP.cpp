#include<iostream>
#include<vector>
using namespace std;
int N, M, MIN= 100000000;

bool kiemtra(vector< int> credit, int xep[], int vt, int tiet){
	for(int i= 0; i< credit.size()/2; i++){
		if((credit.at(2*i+1) == vt) & (credit.at(2*i) < vt)){
			if(xep[credit.at(2*i)] >= tiet)	return 0;
		};
		if((credit.at(2*i) == vt) & (credit.at(2*i+1) < vt)){
			if(tiet >= xep[credit.at(2*i + 1)])	return 0;
		}
	};
	return 1;
}

void duyet(vector< int > credit, int TC[], int xep[], int vt){
	if(vt == N){
		/*for(int i= 0; i< credit.size()/2; i++){
			if(xep[credit.at(2*i)] >= xep[credit.at(2*i+1)])	return;
		};*/
		
		int Tinh[M];
		for(int i=0; i< M; i++)	Tinh[i]= 0;
		for(int i= 0; i< N; i++)
			Tinh[xep[i]]+= TC[i];
		int max= Tinh[0];
		for(int i=1 ; i< M; i++)
			if(max < Tinh[i]) max= Tinh[i];
		if(max < MIN) MIN= max;
		return ; 
	}
	for(int i= 0; i< M; i++){
		
		if(kiemtra(credit, xep, vt, i)){
			xep[vt]= i;
			duyet(credit, TC, xep, vt+1);
		}
	}
}

int main(){
	//Input
	cin>>N>>M;
	int TC[N];
	vector< int > credit;
	int test;
	for(int i= 0; i< N; i++)cin>>TC[i];
	for(int i= 0; i< N; i++){
		for(int j= 0; j< N; j++){
			cin>> test;
			if( test == 1) {
				credit.push_back(i);
				credit.push_back(j);
			}
		}
	}
	//
	int xep[N];
	duyet(credit, TC, xep, 0);
	cout<<MIN;
	return 0;
}
