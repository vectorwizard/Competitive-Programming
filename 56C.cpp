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
    vector<ll> b(n/2);
    for(ll i=0;i<n/2;i++) cin>>b[i];
    vector<ll> a(n);
    ll first = 0;
    ll last = b[0];
    ll i = 1;
    ll j = n-2;
    a[0] = first;
    a[n-1] = last;
    ll ind = 1;
    while(i<j){
        ll x = b[ind];
        if(x<=last){
            if(first==0){
                a[i] = 0;
                a[j] = x;
                last = x;
            }
            else{
                a[i] = first;
                a[j] = (x-first);
                last = a[j];
            }
            i++;
            j--;
            ind++;
        }
        else{
            ll maxi = max(x-last, first);
            a[i] = maxi;
            first = maxi;
            a[j] = (x-maxi);
            last = a[j];
            i++;
            j--;
            ind++;
        }
    }
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
