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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int maxi = 1;
    int curr= 1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) curr++;
        else curr = 1;
        maxi = max(maxi,curr);
    }
    if(maxi>=m){
        cout<<"NO"<<endl;
        return;
    }
    else {
        cout<<"YES"<<endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
