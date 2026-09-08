#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 998244353;
vector<ll> fact(1e6+2,0);
void cal(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<=1e6;i++){
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
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        ll x = a[i];
        if(x<=0) continue;
        mpp[max(0LL,i-x+1)] += -1;  // 0->no poss , 1->poss
        mpp[i+x] += 1;
    }
    ll poss = 0;
    vector<ll> ans(n,0);
    for(ll i=0;i<n;i++){
        if(mpp.find(i)!=mpp.end()){
            poss+=mpp[i];
        }
        if(poss==0) ans[i] = 1;
    }
    bool fl = false;
    for(ll i=0;i<n;i++){
        if(ans[i]==1){
            fl = true;
            break;
        }
    }
    if(!fl){
        cout<<-1<<endl;
        return;
    }
    for(ll i=0;i<n;i++){
        if(a[i]==-1) continue;
        ll left = (i-a[i]);
        if(left>=0 && ans[left]==1){
            continue;
        }
        ll right = (i+a[i]);
        if(right<n && ans[right]==1){
            continue;
        }
        cout<<-1<<endl;
        return;
    }
    for(auto it:ans){
        cout<<it;
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cal();
    cin>>t;
    while (t--) solve();
    return 0;
}
