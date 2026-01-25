#include<bits/stdc++.h>
using namespace std;

void uniqueNo2(vector<int> arr){
	int cumulative_xor = 0;
	for(int i=0; i < (int) arr.size(); i++){
		cumulative_xor = cumulative_xor ^ arr[i];
	}
    int pos = 0, temp = cumulative_xor;
    while((temp & 1) == 0){
        pos++;
        temp = temp >> 1;
    }

    int setA = 0, setB = 0;
    int mask = (1 << pos);

    for(int i = 0; i < (int) arr.size(); i++){
        if((arr[i] & mask) > 0){
            setA = setA ^ arr[i];
        }else{
            setB = setB ^arr[i];
        }
    }
    cout << setA << ' ' << setB;
}

int main(){
	vector<int> arr = {1,3,5,4,3,1,5, 9};
	uniqueNo2(arr);
}