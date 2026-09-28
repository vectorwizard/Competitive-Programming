#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> pos(n+1,0);
    for(int i=0;i<n;i++) pos[a[i]] = i;
    int ans = 1;
    int last = -1;
    for(int i=1;i<=n;i++){
        if(pos[i]>last){
            last = pos[i];
        }
        else{
            last = pos[i];
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}