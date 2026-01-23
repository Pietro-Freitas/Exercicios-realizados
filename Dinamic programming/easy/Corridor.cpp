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
const int MAX = 1e5;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for(auto& i : nums) cin >> i;

    vector<int> dp(n);
    dp[0] = nums[0];
    int ans = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}