#include<iostream>
#include<vector>
#include<string>
using namespace std;

int duyet(string st){
	if( st[0] == ')' || st[0] == ']' || st[0] == '}')
		return 0;
	int i = 1;
	while( st.length() && i <= st.length()){

	if(st[i] == ']'){
		if( st[i-1] != '[')	return 0;
		else{
			st.erase(i-1, 2);
			i--;
			continue; 
		}
	};
	if(st[i] == ')'){
		if( st[i-1] != '(')	return 0;
		else{
			st.erase(i-1, 2);
			i--;
			continue; 
		}
	};
	if(st[i] == '}'){
		if( st[i-1] != '{')	return 0;
		else{
			st.erase(i-1, 2);
			i--;
			continue; 
		}
	};
	i++;
	};
	if( i == 0) return 1;
	else return 0;
}
int main(){
	//INPUT
	int T;
	cin>>T;
	string dau[T];
	for (int i= 0; i< T; i++){
		cin>>dau[i];
	};
	// Ham tinh toan
	for (int i= 0; i< T; i++){
		cout<<duyet(dau[i]);
		cout<<"\n";
	}
	return 0;
}
