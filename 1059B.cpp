#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
string ans;
vector<int> ans_ind;
bool ispalin(string s){
    int n = s.size();
    int l = 0;
    int r= n-1;
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}
bool func(int ind,string temp,int prev,string &s,vector<int> &curr_ind){
    int n = s.size();
    if(ind==n){
        if(ispalin(temp)){
            ans= temp;
            ans_ind = curr_ind;
            return true;
        }
        return false;
    }
    bool take = false;
    bool nottake = false;
    if((s[ind]-'0')>=prev){
        curr_ind.push_back(ind);
        nottake = func(ind+1,temp,s[ind]-'0',s,curr_ind);
        curr_ind.pop_back();
    }
    take = func(ind+1,temp+s[ind],prev,s,curr_ind);
    return (take|nottake);
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> curr_ind = {};
    if(func(0,"",0,s,curr_ind)==false){
        cout<<-1<<endl;
        return;
    }
    cout<<(s.size()-ans.size())<<endl;
    for(auto it:ans_ind){
        cout<<it+1<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}

