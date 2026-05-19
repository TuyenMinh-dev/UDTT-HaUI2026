#include<bits/stdc++.h>
// xâu con đối xứng dài nhất
//tư tưởng : gọi F[i][j] là xâu con bắt đầu ở vị trí i và kết thúc ở vị trí j
//xâu F[i][j] cso xâu con đối xứng khi F[i][j]=(F[i+1][J-1]) &&(s[i]==s[j])
//nghĩa là xâu bên trong phải đối xứng và  2 kí tự bên ngoài phải giống nhau  
//tất cả các phần tử nằm trên đường chéo chính đều có xâu đối xứng(do bắt đầu = kết thúc)
//không xét đến các phần tử nằm dưới đường chéo chính là các phần tử này có bắt đầu >kết thúc(i>j)
using namespace std;
void lps(string &s,int &n){
    //F[i][j] = F[i+1][j-1] && (s[i]==s[j])
    bool F[n+1][n+1];
    memset(F,false,sizeof(F));
    for(int i=1;i<=n;i++){
        F[i][i]= true;//trường hợp cơ sở: tất cả các xâu con có độ dài bằng 1 đều đối xứng
    }
    //xét các xâu con có độ dài từ 2 đến n
    int ans=1;
    for(int len=2;len<=n;len++){
        for(int i=1;i<= n-len+1;i++){
            int j=i+len-1;
            //F[i][j]: có độ dài là len
            if(len==2 && s[i]==s[j]) F[i][j]=true;// trong trường hợp len=2
            else{
                F[i][j] = F[i+1][j-1] && (s[i]==s[j]);
            }
            if(F[i][j]) ans=max(ans,len);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<F[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
}

int main(){
    string s;cin>>s;
    s=" "+s;//thêm một kí tự vào để xâu bắt dầu từ chỉ số 1
    int n=s.size()-1;
    lps(s,n);
    return 0;
    
}

