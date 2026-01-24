#include<bits/stdc++.h>
using namespace std;

vector<int> sortByBits(vector<int> arr) {
    auto countBits = [](int n) {
        int count = 0;
        while(n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    };
    
    sort(arr.begin(), arr.end(), [&](int a, int b) {
        int bitsA = countBits(a);
        int bitsB = countBits(b);
        
        if(bitsA != bitsB) return bitsA < bitsB;
        return a < b;
    });
    
    return arr;
}   