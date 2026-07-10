#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll xk, yk, xq, yq;
    cin >> xk >> yk;
    cin >> xq >> yq;
    vector<ll> dr = {a, a, b, b, -a, -a, -b, -b};
    vector<ll> dc = {b, -b, a, -a, b, -b, a, -a};
    set<pair<ll, ll>> st;
    for (ll i = 0; i < 8; i++)
    {
        ll x = xk + dr[i];
        ll y = yk + dc[i];
        st.insert({x, y});
    }
    ll ans = 0;
    for (auto it : st)
    {
        ll x1 = it.first;
        ll y1 = it.second;
        for (ll i = 0; i < 8; i++)
        {
            ll x = x1 + dr[i];
            ll y = y1 + dc[i];
            if((x==xq)&&(y==yq)) ans++;
        }
    }
    if(a==b) cout<<ans/2<<endl;
    else cout<<ans<<endl;
}

int main()
{
    fastio();
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
