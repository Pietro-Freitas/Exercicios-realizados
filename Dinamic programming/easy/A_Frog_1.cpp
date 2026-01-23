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
const int MAX = 1e5+10;

void solve() {
    int n; cin >> n;
    vector<int> h(n);
    for(auto& l : h) cin >> l;
    vector<int>dp(MAX, 0);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int ans = INF;
        ans = abs(h[i]-h[i-1]) + dp[i-1];
        if(i > 1)ans = min(ans, abs(h[i-2]- h[i]) + dp[i-2]);
        
        dp[i] = ans;
    }
    cout << dp[n-1] << endl;
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