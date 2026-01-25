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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int mismatch_idx = -1;
    int expected = n;
    
    for (int i = 0; i < n; i++) {
        if (p[i] != expected) {
            mismatch_idx = i;
            break;
        }
        expected--;
    }
    if (mismatch_idx == -1) {
        for (int i = 0; i < n; i++) cout << p[i] << (i == n - 1 ? "" : " ");
        cout << endl;
        return;
    }
    int r = -1;
    for (int i = mismatch_idx + 1; i < n; i++) {
        if (p[i] == expected) {
            r = i;
            break;
        }
    }
    reverse(p.begin() + mismatch_idx, p.begin() + r + 1);

    for (int i = 0; i < n; i++) cout << p[i] << (i == n - 1 ? "" : " ");

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}