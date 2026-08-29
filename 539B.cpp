#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i]; 
    ll total = accumulate(a.begin(),a.end(),0LL);
    ll final = total;
    ll mini = *min_element(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        for(ll j=2;j*j<=a[i];j++){
            if(a[i]%j == 0){
                ll res = a[i]/j;
                if(res<=mini) break;
                ll temp = total;
                temp -=a[i];
                temp+=(a[i]/j);
                temp-=mini;
                temp+=(mini*j);
                final = min(final,temp);
            }       
        }
    }
    cout<<final<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
