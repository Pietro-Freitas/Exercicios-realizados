#include<bits/stdc++.h>
using namespace std;

void updateSum(vector<int> &sumArr, int x){
    for(int i = 0; i < 32; i++){
        int ith_bit = x & (1 << i);
        if(ith_bit) sumArr[i]++;
    }
}

int numFromBits(vector<int> sumArr){
    int num = 0;
    for(int i = 0; i < 32; i++){
        num += (sumArr[i] * (1<<i)); // 00100 
    }
    return num;
}

int uniqueNo3(vector<int> arr){
    vector<int> sumArr(32, 0);
    for(int x : arr){
        updateSum(sumArr, x);
    }

    for(int i = 0; i < 32; i++){
        sumArr[i] = sumArr[i]%3; // ou tem 0, out tem o nmr na forma 3n ou na forma 3n+1
    }

    return numFromBits(sumArr);
}

int main(){
	vector<int> arr = {1,3,5,4,3,1,5, 1, 3, 5};
	cout << uniqueNo3(arr);
}
/*
1 2 3 4 3 2 1 1 2 3
001
010
011
100
011
010
001
001
010
011
---     1   0  0 -> 4
166   3n+1 3n 3n (3n -> o numero diferente tem o numero desligado, ou seja 0, o 3n + 1 tem ele ligado, ou seja, 1)
*/