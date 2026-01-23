#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> nums) {
    vector<int> num;
	int ans = 0;
    while(nums.size() > 1){
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1];
        num.push_back(nums[0]);
        num.push_back(nums[1]);
        nums.push_back(sum);
        nums.erase(nums.begin());
        nums.erase(nums.begin());
    }
    for(auto i : num){
        ans += i;
    }
    return ans;
}