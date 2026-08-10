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
    int maxi = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            maxi = max(maxi,cnt);
            cnt = 0;
        }
        else cnt++;
    }
    maxi = max(maxi,cnt);
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
