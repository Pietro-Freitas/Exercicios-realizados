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

void overLayNumber(char arr[], int i){
    int j = 0;
    while(i > 0){
        int last_bit = i & 1;
        if(last_bit){
            cout << arr[j];
        }
        j++;
        i = i >> 1;
    }
    cout << endl;
}

void generateAllSubsets(char arr[]){
    int n = strlen(arr);
    FOR(i, 0, (1<<n)){
        overLayNumber(arr, i);
    }
}

void solve() {
    char arr[1000];
    cin >> arr;
    generateAllSubsets(arr);

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