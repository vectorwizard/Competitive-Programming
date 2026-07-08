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
    ll mini = *min_element(a.begin(),a.end());
    ll ans = 1e9;
    map<ll,ll> poss; 
    map<ll,ll> green; 
    while(mini!=1){
        poss[mini] = 0;
        green[mini] = 0;
        if(mini%2==1){
            mini++;
        }
        else mini/=2;
    }
    poss[1] = 0;
    green[1] = 0;
    if(poss.find(2) == poss.end()){
        poss[2] = 0;
        green[2] = 0;
    }
    for(ll i=0;i<n;i++){
        ll x = a[i];
        ll steps = 0;
        while(x!=1){
            if(poss.find(x)!=poss.end()){
                poss[x]+=steps;
                green[x]++;
            }
            if(x%2==1) x++;
            else x/=2;
            steps++;
        }
        if(poss.find(1)!=poss.end()){
            poss[1]+=(steps);
            green[1]++;
        }
        if(a[i] == 1){
            poss[2] += 1;
            green[2]++;
        }
    }
    for(auto it:poss){
        if(green[it.first]==n){
            ans = min(ans,it.second);
        }
    }
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
