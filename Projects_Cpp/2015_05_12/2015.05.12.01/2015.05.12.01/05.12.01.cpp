#include<iostream>
using namespace std;

int max(int a, int b){
	if(a > b)return a;
	return b;
}

char max(char a,char b){
	if(a > b)return a;
	return b;
}

double max(double a, double b){
	if(a > b)return a;
	return b;
}

int main(){
	cout << "10と20を比較して大きいのは"<<max(10,20) << "\n";
	cout << " aとbを比較して大きいのは" <<max('a','b') << "\n";
	cout << "1.01と0.99を比較して大きいのは"<< max(1.01,0.99) << "\n";
	return 0;
}