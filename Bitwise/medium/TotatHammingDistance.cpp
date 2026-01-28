#include<bits/stdc++.h>
using namespace std;

int countBits(int n){
    int count = 0;
    while(n > 0){
        n = n & (n-1);
        count++;
    }
    return count;
}

int totalHammingDistance(vector<int> nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            ans += countBits(nums[i] ^ nums[j]);
        }
    }
    return ans;
}

// Solução do professor:
/*

int totalHammingDistance(vector<int> nums) {
    int n = nums.size();
    int dist = 0;
    for(int i = 0 ; i < 32; i++){
        int one = 0;
        for(int j = 0 ; j < n ; j++){
            one += (nums[j]&1);  // Check if the current bit is 1
            nums[j] >>= 1;  // Right shift the number
        }
        dist += one*(n - one);  // Update the total Hamming distance
    }
    return dist;
}
*/

int main(){
    vector<int> nums = {4, 14, 2};

    cout << totalHammingDistance(nums);

    return 0;
}