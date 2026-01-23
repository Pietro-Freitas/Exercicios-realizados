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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    if(n == 0 || m == 0) cout << 0 << endl;
    else if(m==1 || n == 1) cout << 1 << endl;
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           if(i != 0 && j != 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
           cout << dp[i][j] << endl;
        }
    }
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