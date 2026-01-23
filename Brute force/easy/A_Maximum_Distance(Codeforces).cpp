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
    vector<ii> cord(n);
    FOR(i,0,n) cin >> cord[i].f;
    FOR(i,0,n) cin >> cord[i].s;
    int euclideanDist = -INF;
    FOR(i, 0, n){
        FOR(j, i+1, n){
            int dist = (cord[j].f - cord[i].f) *(cord[j].f - cord[i].f) + ((cord[j].s - cord[i].s) * (cord[j].s - cord[i].s));
            euclideanDist = max(euclideanDist, dist);
        }
    }
    cout << euclideanDist << endl;
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