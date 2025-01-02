#include<iostream>
using namespace std;
int main(){
    int tc;
    long long int n;
    cin>>tc;
    while(tc--){
        cin>>n;
        for(int i=59;i>1;i--){
            long long int left=2, right = n-1, mid, sum,x;
            while(left<=right){
                mid=left+(right-left)/2;
                sum=1, x=1;
                int flag=0;
                for(int j=1;j<i;j++){
                    if(sum>n || (n-sum)/mid < x){
                        flag=1;
                        break;
                    }
                    x*=mid;
                    sum=sum+x;
                }
                if(flag) right=mid-1;
                else if(sum<n) left=mid+1;
                else break;
            }
            if(sum==n){
              cout<<mid<<"\n";
              break;  
            } 
        }
    }
    return 0;
}
