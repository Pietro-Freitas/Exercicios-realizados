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
int n, k;
int memo[MAX];

int dp(int i){
    if(i <= 1) return 1;
    if(memo[i] != -1) return memo[i];
    int ans = 0;
    for(int j = 1; j <= k; j++){
        if(i-j >= 0) ans += dp(i-j); 
    }
    return memo[i] = ans;
}



void solve() {
    cin >> n >> k;
    memset(memo, -1, sizeof memo);
    cout << dp(n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    set<int> msey = {1,2,3};

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}