#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
static bool comp(pair<int,int> &a,pair<int,int> &b){
    return (a.second<b.second);
}
void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end(),comp);
    int ans = 0;
    int ending = -1;
    for(int i=0;i<n;i++){
        if(vec[i].first>=ending){
            ans++;
            ending = vec[i].second;
        } 
    }
    cout<<ans<<endl;
}  

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
