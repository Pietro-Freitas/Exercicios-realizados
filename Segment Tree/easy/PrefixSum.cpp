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
#define FOR(i,ini,N) for(int i=ini;i<N;i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define INF 0x3f3f3f3f
const int MAX = 1000;

void solve() {
    int n; cin >> n;
    vector<int> arr(n), p(n);
    for(auto& i : arr) cin >> i;
    p[0] = arr[0];
    for(int i = 1; i < n; i++) p[i] = arr[i] + p[i-1];
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        int ans = (l > 0 ? p[r] - p[l-1] : p[r]);
        cout << ans << endl;
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