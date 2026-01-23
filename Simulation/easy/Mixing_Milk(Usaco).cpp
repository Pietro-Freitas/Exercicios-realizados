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
#define ii pair<ll, ll>
#define FOR(i,ini,N) for(int i=ini;i<N;i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define INF 0x3f3f3f3f
const int MAX = 1000;


/*
0 -
1° 3
2° 4
3° 5
1 -
1° 0
2° 7
3° 5
2 -
1° 0
2° 0
3° 12
3 -
1° 10
2° 0
3° 2
4 - 
1° 0
2° 10
3° 2
*/

void solve() {
    vector<ii> bucket(3); //* Capacidade máxima e carga atual
    FOR(i, 0, 3) cin >> bucket[i].f >> bucket[i].s;
    
    FOR(i, 0, 100){
        int b1 = i % 3;
        int b2 = (i + 1) % 3;

        ll e = bucket[b2].f - bucket[b2].s; //* Quanto falta para encher
        ll trans = min(bucket[b1].s, e); //* Quanto irei transfferir

        bucket[b1].s -= trans;
        bucket[b2].s += trans;

    }

    cout << bucket[0].s << endl <<  bucket[1].s << endl << bucket[2].s << endl;
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