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
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> gaps(n);
    int x = 0;
    for(int i=0;i<n;i++){
        gaps[i] = (b[i]-a[i]);
        x+=gaps[i];
    }
    if(x!=0){
        cout<<-1<<endl;
        return;
    }
    if(abs(gaps[0])%2==0){
        for(int i=0;i<n;i++){
            if(abs(gaps[i])%2!=0){
                cout<<-1<<endl;
                return;
            }
        }
    }
    else if(abs(gaps[0])%2==1){
        for(int i=0;i<n;i++){
            if(abs(gaps[i])%2!=1){
                cout<<-1<<endl;
                return;
            }
        }
    }
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++){
        vec[i] = {gaps[i],i};
    }
    vector<vector<int>> ans;
    while(1){
        bool fl = true;
        for(int i=0;i<n;i++){
            if(vec[i].first!=0){
                fl = false;
                break;
            }
        }
        if(fl) break;
        sort(vec.rbegin(),vec.rend());
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(i<n/2) {
                vec[i].first--;
                temp.push_back(vec[i].second+1);
            }
            else vec[i].first++;
        }
        ans.push_back(temp);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        int sz = ans[i].size();
        for(int j=0;j<sz;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
