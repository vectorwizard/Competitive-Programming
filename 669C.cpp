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
    vector<ll> ans(n+1,0);
    ll i = 1;
    ll j = 2;
    while(j<=n){
        ll x,y;
        cout<<"?"<<" "<<i<<" "<<j<<endl;
        cin>>x;
        cout<<"?"<<" "<<j<<" "<<i<<endl;
        cin>>y;
        if(x>y){
            ans[i] = x;
            i = j;
            j++;
        }
        else{
            ans[j] = y;
            j++;
        }
    }
    ans[i] = n;
    cout<<"!"<<" ";
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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
