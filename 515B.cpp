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
    ll n, r;
    cin >> n >> r;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    ll i = 0;
    while (i < n)
    {
        ll left = max(0LL, i - r + 1);
        ll right = min(n - 1, i + r - 1);
        bool fl = false;
        for (ll j = right; j >= left; j--)
        {
            if (a[j] == 1)
            {
                ans++;
                i = j + r;
                fl = true;
                break;
            }
        }
        if (fl == false)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main()
{
    fastio();
    ll t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
