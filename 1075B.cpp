#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<vector<int>> vec(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
    }
    ll min_poss = 0;
    ll maxi = LLONG_MIN;
    for(int i=0;i<n;i++){
        int a = vec[i][0];
        int b = vec[i][1];
        int c = vec[i][2];
        min_poss += 1LL*a*(b-1);
        maxi = max(maxi,(ll)((1LL*a*b)-c));
    }
    if(min_poss>=x){
        cout<<0<<endl;
        return;
    }
    ll rem = x-min_poss;
    if(maxi<=0){
        cout<<-1<<endl;
        return;
    }
    cout<<((rem+maxi-1)/maxi)<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}