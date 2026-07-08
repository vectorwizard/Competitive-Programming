#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    set<int> st;
    stack<pair<int,int>> sta;
    vector<pair<int,int>> vec;
    for(int i=1;i<=n;i++){
        if(st.count(a[i])==0){
            st.insert(a[i]);
            vec.push_back({a[i],i});
        }
    }
    for(int i=vec.size()-1;i>=0;i--){
        sta.push(vec[i]);
    }
    stack<pair<int,int>> temp;
    while(q--){
        int t;
        cin>>t;
        while(sta.top().first!=t){
            temp.push(sta.top());
            sta.pop();    
        }
        cout<<sta.top().second<<" ";
        sta.pop();
        while(!temp.empty()){
            int x = temp.top().first;
            int y = temp.top().second;
            temp.pop();
            sta.push({x,y+1});
        }
        sta.push({t,1});
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
