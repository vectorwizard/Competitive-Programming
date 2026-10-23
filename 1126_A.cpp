#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a;
    for(ll i=1;i<=n;i++) a.push_back(i);
    vector<ll> ans;
    ll i = n-1;
    ll target = (n*(n+1))/2;
    if(target%2==0) cout<<0<<endl;
    else cout<<1<<endl;
    target = target/2;
    ll sum = 0;
    while(i>=0){
        if((sum+a[i])<=target){
            ans.push_back(a[i]);
            sum+=a[i];
            i--;
        }
        else{
            break;
        }
    }
    if(sum!=target) ans.push_back(target-sum);
    cout<<ans.size()<<" ";
    for(auto it:ans) cout<<it<<" ";
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
