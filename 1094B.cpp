#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> x(m+1);
    int odd = 0,even=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) {
        cin>>x[i];
        if(x[i]%2==0) even++;
        else odd++;
    }
    vector<int> odds;
    vector<int> evens;
    for(int i=1;i<=n;i++){
        if(i%2==0) evens.push_back(a[i]);
        else odds.push_back(a[i]);
    }
    sort(evens.rbegin(),evens.rend());
    sort(odds.rbegin(),odds.rend());
    ll total = 0;
    if(even>0) total+=evens[0];
    even--;
    for(int i=1;i<evens.size();i++){
        if(even>0 && evens[i]>0){
            total+=evens[i];
            even--;
        }
        else break;
    }
    if(odd>0) total+=odds[0];
    odd--;
    for(int i=1;i<odds.size();i++){
        if(odd>0 && odds[i]>0){
            total+=odds[i];
            odd--;
        }
        else break;
    }
    ll totalf = accumulate(a.begin(),a.end(),0LL);
    cout<<totalf-total<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
