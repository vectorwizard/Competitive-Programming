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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    multiset<pair<int,int>> st;
    for(int i=0;i<n;i++){
        string s = to_string(a[i]);
        int zeros = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='0') break;
            else zeros++;
        }
        st.insert({zeros,s.size()});
    }
    int x = 0;
    while(st.size()>0){
        if(x%2==1){
            if(st.size()<2) break;
            auto it = st.rbegin();
            int zeros1 = it->first;
            int siz1 = it->second;
            st.erase(st.find({zeros1,siz1}));
            auto it1 = st.rbegin();
            int zeros2 = it1->first;
            int siz2 = it1->second;
            st.erase(st.find({zeros2,siz2}));
            int newsize = siz1 + siz2;
            st.insert({zeros2,newsize});
        }
        else{
            auto it = st.rbegin();
            int zeros1 = it->first;
            int siz1 = it->second;
            st.erase(st.find({zeros1,siz1}));
            st.insert({0,siz1-zeros1});
        }
        x++;
    }
    auto it = st.rbegin();
    int siz1 = it->second;
    if(siz1>=(m+1)) cout<<"Sasha"<<endl;
    else cout<<"Anna"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
