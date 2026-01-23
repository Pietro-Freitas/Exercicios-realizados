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
const int MAX = 21;

void solve() {
    int k, n; cin >> k >> n;

    vector<vector<int>> v(k, vector<int>(n));
    FOR(i, 0, k) FOR(j, 0, n) cin >> v[i][j];

    int ans = 0;
    FOR(vaca_ref, 1, n + 1) {
        vector<int> vezes_atras(MAX, 0);
        FOR(i, 0, k) {
            bool encontrei_ref = false;
            FOR(j, 0, n) {
                if (v[i][j] == vaca_ref) encontrei_ref = true;
                else if (encontrei_ref) {
                    vezes_atras[v[i][j]]++;
                }
            }
        }
        FOR(vaca_b, 1, n + 1) if (vezes_atras[vaca_b] == k) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}