#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,h,k;
    cin>>n>>h>>k;
    vector<ll> a(n);
    ll total = 0;
    ll ans = 0;
    unordered_map<int,ll> mpp;
    vector<ll> maxi(n);
    vector<ll> mini(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        total+=a[i];
        mpp[i] = total;
    }
    if((h%total)==0) ans += n * (h/total) + ((h/total)-1) * k;
    else ans += (n+k) * (h/total);
    h = h%total;
    if(h==0){
        cout<<ans<<endl;
        return;
    }
    mpp[-1] = 0;
    maxi[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        maxi[i] = max(a[i],maxi[i+1]);
    }
    mini[0] = a[0];
    for(int i=1;i<n;i++){
        mini[i] = min(a[i],mini[i-1]);
    }
    for(int i=0;i<n;i++){
        ll damage = mpp[i];
        if(i<n-1) damage+=max(0LL,(maxi[i+1]-mini[i]));
        if(damage>=h){
            ans++;
            break;
        }
        else{
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}