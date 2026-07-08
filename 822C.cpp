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
    string s;
    cin >> s;
    vector<ll> hash(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
            hash[i + 1] = 1;
    }
    unordered_map<ll, ll> mpp;
    ll ans = 0;
    vector<ll> deleted(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (hash[i] == 1) continue;
        if(deleted[i]==0)
        {
            mpp[i]++;
            deleted[i] = 1;
        }

        for (ll j = 2; j <= n; j++)
        {
            ll x = i * j;
            if (x > n)
                break;
            if (hash[x] == 1)
                break;
            if (deleted[x] == 0)
            {
                mpp[i]++;
                deleted[x] = 1;
            }
        }
    }
    for (auto it : mpp)
    {
        ans += (it.first * it.second);
    }
    cout << ans << endl;
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
