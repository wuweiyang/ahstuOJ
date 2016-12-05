#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
void solve(){
int n;
int s[100];
while(cin>>n){
int sum =0;
for(int i=0;i<n;i++){
    cin>>s[i];sum+=s[i];
}
int tot=0;
if(sum/n*n!=sum){
    cout<<"Oh no!"<<endl;
}
else {
    int ave=sum/n;
    for(int i=0;i<n-1;i++){
    if(s[i]>ave){s[i]=ave;s[i+1]+=s[i]-ave;tot++;}
    if(s[i]<ave){s[i+1]-=ave-s[i];tot++;}
    }
    cout<<tot<<endl;
}
}
}
int main()
{
freopen("a.in","r",stdin);
freopen("a.out","w",stdout);
solve();
    return 0;
}
