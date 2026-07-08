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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> prefix(n);
    vector<ll> suffix(n);
    prefix[0] = a[0];
    for(int i=1;i<n;i++){
        if(a[i]<0) prefix[i] = prefix[i-1]-a[i];
        else prefix[i] = prefix[i-1]+a[i];
    }
    suffix[n-1] = -(a[n-1]);
    for(int i=n-2;i>=0;i--){
        suffix[i] = suffix[i+1]-a[i];
    }
    ll maxi = LLONG_MIN;
    for(int i=1;i<n-1;i++){
        ll x = prefix[i-1]+suffix[i+1];
        maxi = max(maxi,x);
    }
    maxi = max(maxi,max(prefix[n-2],suffix[1]));
    cout<<maxi<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
