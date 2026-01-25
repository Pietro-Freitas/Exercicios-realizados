/*
    Código elegantemente feito por: Pietro
    Se compilou, envia
*/
#include <bits/stdc++.h>
using namespace std;


//! Código n resolvido

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
    vector<int>swords(n);
    vector<int>monsters(n);
    for(auto& i : swords) cin >> i;
    for(auto& i : monsters) cin >> i;
    int dif, levelsP = 0;
    int maxLevels =0, sum = 0;
    for(auto m : monsters){
        if(m > n) break;
        if(sum + m > n) break;
        sum += m;
        maxLevels++;
    }
    sort(all(swords), greater<int>());
    dif = swords[sum];
    for(int i = 0; i < sum; i++){
        dif = swords[i];
    }
    int ans = dif * maxLevels;
    // o código acima maximiza nossos levels, mas n os pontos
    if(swords[monsters[0]-1] > ans) ans = swords[monsters[0]-1];
    if(swords[0] == swords[n-1]) ans = swords[0]*n; // overflow em muito grandes, deveria ter usado long long no ans
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

//* código resolvido pelo grok AI

/*
void solve() {
    int n; cin >> n;
    vector<ll> swords(n);
    vector<int> monsters(n);
    
    for(auto& i : swords) cin >> i;
    for(auto& i : monsters) cin >> i;
    
    // Ordena espadas em ordem decrescente
    sort(all(swords), greater<ll>());
    
    // Pré-calcula soma acumulada dos monsters
    vector<ll> pref(n + 1, 0);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + monsters[i];
    }
    
    ll ans = 0;
    int levels = 0;
    
    // Testa cada quantidade m de espadas
    for(int m = 1; m <= n; m++) {
        // Com m espadas, quantos níveis consigo passar?
        while(levels < n && pref[levels + 1] <= m) {
            levels++;
        }
        
        // Dificuldade = força da m-ésima espada mais forte
        ll dif = swords[m - 1];
        
        ans = max(ans, dif * levels);
    }
    
    cout << ans << endl;
}
*/