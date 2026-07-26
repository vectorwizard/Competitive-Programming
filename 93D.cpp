#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll dp[201][201][201];

ll func(ll ind1,ll ind2,ll ind3,vector<ll> &r,vector<ll> &g,vector<ll> &b){
    ll R = r.size();
    ll G = g.size();
    ll B = b.size();
    if(ind1==R+1 && ind2==G+1) return 0;
    if(ind1==R+1 && ind3==B+1) return 0;
    if(ind2==G+1 && ind3==B+1) return 0;
    ll maxi = 0;
    if(dp[ind1][ind2][ind3]!=-1) return dp[ind1][ind2][ind3];
    ll p12 = 0, p23 = 0,p13 = 0;
    if(ind1<R){
        if(ind2<G) p12 = r[ind1]*g[ind2] + func(ind1+1,ind2+1,ind3,r,g,b);
        if(ind3<B) p13 = r[ind1]*b[ind3] + func(ind1+1,ind2,ind3+1,r,g,b);
    }
    if(ind2<G && ind3<B) p23 = g[ind2]*b[ind3] + func(ind1,ind2+1,ind3+1,r,g,b);
    maxi = max(p12,max(p23,p13));
    return dp[ind1][ind2][ind3]=maxi;
}

void solve() {  
    ll R,G,B;
    cin>>R>>G>>B;
    vector<ll> r(R);
    vector<ll> g(G);
    vector<ll> b(B);
    for(ll i=0;i<R;i++) cin>>r[i];
    for(ll i=0;i<G;i++) cin>>g[i];
    for(ll i=0;i<B;i++) cin>>b[i];
    sort(r.rbegin(), r.rend());
    sort(g.rbegin(), g.rend());
    sort(b.rbegin(), b.rend());
    memset(dp,-1,sizeof(dp));
    ll ans = func(0,0,0,r,g,b);
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
