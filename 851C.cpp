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
    if(n%2==0){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    vector<ll> a;
    for(ll i=1;i<=2*n;i++) a.push_back(i);
    cout<<n<<" "<<n+1<<endl;
    vector<ll> odd;
    vector<ll> even;
    for(ll i=1;i<=n-1;i+=2){
        odd.push_back(i);
    }
    for(ll i=2;i<=n-1;i+=2){
        even.push_back(i);
    }
    reverse(odd.begin(),odd.end());
    reverse(even.begin(),even.end());
    vector<pair<ll,ll>> vec(n-1);
    ll ind = 0;
    for(ll i=0;i<odd.size();i++){
        vec[ind].first = odd[i];
        ind++;
    }
    for(ll i=0;i<even.size();i++){
        vec[ind].first = even[i];
        ind++;
    }
    ind = 0;
    for(ll i=n+2;i<=2*n;i++){
        vec[ind].second = i;
        ind++;
    }
    for(auto it:vec){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
