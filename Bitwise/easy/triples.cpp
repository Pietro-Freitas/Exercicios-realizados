#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void overLayNumber(vector<int> nums, ll number){
    int j = 0;
    string s = "";
    while(number > 0){
        int last_bit = number & 1;
        if(last_bit)  cout << nums[j];
        else cout << 0;
        j++;
        number = number >> 1;
    }
    cout << endl;
}

int countTriplets(vector<int> nums) {
    ll ans = 0;
    for(int i = 0; i < (1 << nums.size()); i++){
        overLayNumber(nums, i);
    }
    return ans;
}

int main(){
    vector<int> nums = {2, 1, 3};

    cout << countTriplets(nums) << endl;

    return 0;
}