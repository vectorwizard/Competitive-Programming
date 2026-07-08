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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    vector<ll> p(n);
    vector<ll> q(n);
    p[0] = a[0];
    q[0] = b[0];
    if (q[0] < p[0])
    {
        cout << "NO" << endl;
        return;
    }
    for (ll i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + a[i];
        q[i] = q[i - 1] + b[i];
        if (q[i] < p[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
