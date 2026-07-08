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
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<ll> needed(n);
    needed[0] = b[0];
    for(int i=1;i<n;i++){
        needed[i] = needed[i-1]+b[i];
    }
    sort(a.rbegin(),a.rend());
    ll maxi = 0;
    for(int i=0;i<n;i++){
        ll swords_needed = needed[i];
        if(swords_needed>n) break;
        int level = i+1;
        int x = a[swords_needed-1];
        ll score = 1LL*x*level;
        maxi = max(maxi,score);
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}