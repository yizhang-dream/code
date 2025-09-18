#include<bits/stdc++.h>
using namespace std;
int a[10000003];
int hashe(string str){
 	int ans=0;
 	for(int i=0;i<str.size();i++){
 		ans=(ans*17+(int)str[i])%10000007;
	}
 	return ans;
}
int main(){
    int n,m=0;
    cin>>n;
    for(int i=0; i<n; i++){
        char  x[20000000];
        scanf("%s",&x);
    
        a[i]=hashe(x);
        sort(a,a+i+1);
        
    }
    for(int i=0;i<n;i++){
            if(a[i]!=a[i+1]){
                m+=1;
            }
        }
        
    cout<<m<<endl;
    
    return 0;
}