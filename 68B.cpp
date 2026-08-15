#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    vector<int> row(n,0);
    vector<int> col(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='*') {
                a[i][j] = 1;
                row[i]++;
                col[j]++;
            }
            else a[i][j] = 0;
        }
    }
    int ans = 1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt = m - row[i];
            cnt+=(n-col[j]);
            if(a[i][j]==0) cnt--;
            ans = min(ans,cnt);
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
