/*
    Código elegantemente feito por: Pietro
    Se compilou, envia
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define INF 0x3f3f3f3f
const int MAX = 1000;

vector<int> nums;
vector<int> dp;

bool camSum(int target){
    if(target == 0) return true;
    if(target < 0) return false;
    if(dp[target] != -1) return dp[target];
    for(int i : nums){
        if(camSum(target - i) == true) return dp[target] = true;
    }
    return dp[target] = false;
}

void solve() {
    int n, target; cin >> n >> target;
    nums.resize(n);
    dp.assign(target+1, -1);
    for(auto& i : nums) cin >> i;
    cout << (camSum(target) == true ? "true" : "false") << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}