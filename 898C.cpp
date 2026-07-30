#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    vector<vector<char>> a(10,vector<char>(10,0));
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            cin>>a[i][j];
        }
    }
    ll ans = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i][j]!='X') continue;
            int distr = abs(9-i), distc = abs(9-j);
            distr = min(distr,abs(0-i));
            distc = min(distc,abs(0-j));
            int mini = min(distr,distc);
            ans+=(mini+1);
        }
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
