#include<bits/stdc++.h>
using namespace std;

int uniqueNo(vector<int> arr){
	int cumulative_xor = 0;
	for(int i=0; i < (int) arr.size(); i++){
		cumulative_xor = cumulative_xor ^ arr[i];
	}
	return cumulative_xor;
}

int main(){
	vector<int> arr = {1,3,5,4,3,1,5};

	cout << uniqueNo(arr) <<endl;
}