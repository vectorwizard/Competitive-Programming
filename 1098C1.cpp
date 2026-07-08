#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll a,n,xx=-2e18,yy=2e18;
    cin>>a>>n;
    vector<ll> d(n);
    for(ll i=0;i<n;i++) cin>>d[i];
    string s = to_string(a);
    bool fl = true;
    string ans = "";
    ll com = 0;
    for(ll i=0;i<s.size();i++){
        ll digit = s[i] - '0';
        bool has = false;
        for(ll j=0;j<d.size();j++){
            if(digit == d[j]){
                has = true;
                break;
            }
        }
        if(has==false){
            com = i;
            fl = false;
            break;
        }
        ans+=s[i];
    }
    if(fl==true){
        cout<<0<<endl;
        return;
    }
    bool has = false;
    ll target = s[com]-'0';
    ll ind = upper_bound(d.begin(),d.end(),target) - d.begin();
    ind--;
    if(ind>=0){
        has = true;
    }
    if(has){
        char ch = d[ind] + '0';
        ans+=ch;
        for(ll i=com+1;i<s.size();i++){
            char ch= d[n-1]+'0';
            ans+=ch;
        }
        if(ans!="") xx = stoll(ans);
    }
    else{
        bool has = false;
        for(ll i=com-1;i>=0;i--){
            ll target = ans[i]-'0';
            ll ind = lower_bound(d.begin(),d.end(),target) - d.begin();
            ind--;
            if(ind>=0){
                has = true;
                char ch = '0' + d[ind];
                ans = ans.substr(0,i) + ch;
                for(ll j=i+1;j<s.size();j++){
                    char ch = '0' + d[n-1];
                    ans+=ch;
                }
                if(ans!="") xx = stoll(ans);
                break;
            }
        }
        if(!has){
            string ans1 = "";
            for(ll i=0;i<s.size()-1;i++){
                char ch = '0' + d[n-1];
                ans1+=ch;
            }
            if(ans1!="") xx = stoll(ans1);
        }
    }
    ans = s.substr(0,com);
    has = false;
    target = s[com]-'0';
    ind = upper_bound(d.begin(),d.end(),target) - d.begin();
    if(ind<n){
        has = true;
    }
    if(has){
        char ch = d[ind] + '0';
        ans+=ch;
        for(ll i=com+1;i<s.size();i++){
            char ch= d[0]+'0';
            ans+=ch;
        }
        if(ans!="") yy = stoll(ans);
    }
    else{
        bool has = false;
        for(ll i=com-1;i>=0;i--){
            ll target = ans[i]-'0';
            ll ind = upper_bound(d.begin(),d.end(),target) - d.begin();
            if(ind<n){
                has = true;
                char ch = '0' + d[ind];
                ans = ans.substr(0,i) + ch;
                for(ll j=i+1;j<s.size();j++){
                    char ch = '0' + d[0];
                    ans+=ch;
                }
                if(ans!="") yy = stoll(ans);
                break;
            }
        }
        if(!has){
            ll non_zero = d[0];
            for(ll i=0;i<n;i++){
                if(d[i]>0){
                    non_zero = d[i];
                    break;
                }
            }
            string ans1 = "";
            char ch = '0' + non_zero;
            ans1+=ch;
            for(ll i=0;i<s.size();i++){
                char ch = '0' + d[0];
                ans1+=ch;
            }
            if(ans1!="") yy = stoll(ans1);
        }
    }
    ll final = min(abs(a-xx),abs(a-yy));
    cout<<final<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
