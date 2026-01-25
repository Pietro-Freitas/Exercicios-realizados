#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
    int ans = 0;
    while (y != 0 || x != 0){
        if((x & 1) != (y & 1)) ans++;
        x = x >> 1;
        y = y >> 1;
    }
    return ans;
}


// Versão usado XOR
int hammingDistance(int x, int y) {
    int xor_result = x ^ y;  // bits diferentes ficam como 1
    int ans = 0;
    
    while(xor_result) {
        xor_result = xor_result & (xor_result - 1); // Remove bits 1 atpe chegar a  0
        ans++;
    }
    
    return ans;
}