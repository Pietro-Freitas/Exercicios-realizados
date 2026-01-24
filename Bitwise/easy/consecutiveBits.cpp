#include<bits/stdc++.h>
using namespace std;

int countSequenceBits(int n) {
    int cont = 0;
    int ans = 0;
    while(n){
        int last_bit = (n & 1);
        if(last_bit == 1) cont++;
        else cont = 0;
        ans = max(ans, cont);
        n = n >> 1;
    }
    
    return ans;
}