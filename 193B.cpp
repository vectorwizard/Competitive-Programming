#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 998244353;
vector<ll> fact(1e6,0);
void cal(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<1e6;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}

ll power(ll a, ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans = (ans*ans)%mod;
    if(b%2==1){
        ans = (ans*a)%mod;
    }
    return ans%mod;
}

ll ncr(ll n,ll r){
    ll x = fact[n];
    ll y = fact[r];
    y = (y*fact[n-r])%mod;
    ll ans = (x * power(y,mod-2))%mod;
    return ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll patch = 1;
    vector<pair<ll,ll>> temp;
    for(ll i=1;i<n;i++){
        if(a[i]==a[i-1]){
            patch++;
        }
        else{
            temp.push_back({patch,a[i-1]});
            patch = 1;
        }
    }
    temp.push_back({patch,a[n-1]});
    ll m = temp.size();
    bool fl = false;
    for(ll i=1;i<m;i++){
        if(temp[i].first>=2 && temp[i-1].first>=2){
            fl = true;
            break;
        }
    }
    if(fl){
        cout<<m+2<<endl;
    }
    else{
        bool fl = false;
        for(ll i=0;i<m;i++){
            if(temp[i].first==1) continue;
            if(i>1){
                if(temp[i-2].second!=temp[i].second){
                    fl = true;
                    break;
                }
            }
            if(i<=(m-3)){
                if(temp[i+2].second!=temp[i].second){
                    fl = true;
                    break;
                }
            }
            if(i==1 || i==(m-2)){
                fl = true;
            }
        }
        if(fl){
            cout<<(m+1)<<endl;
        }
        else cout<<m<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cal();
    cin>>t;
    while (t--) solve();
    return 0;
}
