#include<bits/stdc++.h>
using namespace std;
//F[i][j]: lưu độ dài xâu con chung dài nhất có được bởi cách lấy i kí tự đầu tiên của xâu X và j kí tự đầu tiên của xâu Y
//F[n][m]: đáp án bài toán
// Cơ sở quy hoạch động : F[i][0]=0 và F[0][i]=0 (xâu 1 chọn i kí tự nhưng xâu 2 không chọn kí tự nào thì độ dài xcc=0 , tương tự ngược lại)
// Không yêu cầu xâu con cần phải liên tiếp 
void lcs(int &n,int &m,string &X,string &Y){
    int F[n+1][m+1];
    for(int j=0;j<=m;j++){
        F[0][j]=0;
    }
    for(int i=0;i<=n;i++){
        F[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(X[i]==Y[j]){
                  F[i][j]=F[i-1][j-1]+1;
             }
             else{
                F[i][j]=max(F[i][j-1],F[i-1][j]);
             }
        }
    }
    cout<<"Do dai cua xau con chung dai nhat la: ";
    cout<<F[n][m]<<endl;

    //truy vết
    string res="";
    int i=n,j=m;//xuất phát từ ô dưới cùng bên phải
    while(i>0 && j>0){
        if(X[i]==Y[j]){
            res +=X[i];
            i--;j--;//di chuyển lên trên bên trái
        }else{
            if(F[i][j-1]>=F[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(res.begin(),res.end());//vì đi ngược nên xâu bị ngược
    cout<<"Xau con chung dai nhat cu the la: "<<res<<endl;

}
int main(){
    string X,Y;
    cin>>X>>Y;
    X =" "+X;
    Y=" "+Y;
    int n = X.size()-1;
    int m = Y.size()-1;
    lcs(n,m,X,Y);
    return 0;
}