#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec.push_back({a,1});
        vec.push_back({b,-1});
    }
    sort(vec.begin(),vec.end());
    int maxi = 0;
    int curr=0;
    for(auto it:vec){
        int time = it.first;
        int delta = it.second;
        if((curr+delta)>maxi){
            maxi = curr+delta;
        }
        curr = curr+delta;
    }
    cout<<maxi<<endl;
}  

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
