#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
#define ii pair<int, int>
#define f first
#define s second
typedef long long ll;
const int MAX = 1e5;
char M[MAX][MAX];
int costa = 0;
int m, n;
vector<ii> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(ii s){
    for(auto u : mov){
        u.f += s.f; u.s += s.s;
        if(u.f < 0 or u.s < 0 or u.f == m or u.s == n){
            costa++;
            break;
        }else if (M[u.f][u.s] == '.'){
            costa++;
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> m >> n;
    for(int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> M[i][j];
    for(int i = 0; i < m; i++) for (int j = 0; j < n; j++) if(M[i][j] == '#') bfs({i, j});
    cout << costa;

    return 0;
}