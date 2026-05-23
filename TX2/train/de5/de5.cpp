#include<bits/stdc++.h>
using namespace std;
struct GiaoTrinh{
    string ten;
    string tenTG;
    int gia;
};
struct KQC{
    int soGT;
    vector<GiaoTrinh> ds;
};
void inDS(vector<GiaoTrinh> ds){
    cout<<left
        <<setw(5)<<"STT"
        <<setw(25)<<"Ten GT"
        <<setw(20)<<"Ten TG"
        <<"Gia bia"<<endl;
    for(int i=0;i<ds.size();i++){
        cout<<left
            <<setw(5)<<i+1
            <<setw(25)<<ds[i].ten
            <<setw(20)<<ds[i].tenTG
            <<ds[i].gia<<" nghin dong"<<endl;
    }
}
KQC C(int p,int n,vector<GiaoTrinh> d){
    KQC kq;
    kq.soGT=0;
    int tien=0;
    for(int i=0;i<n;i++){
        if(tien+d[i].gia<=p){
        kq.soGT++;
        tien+=d[i].gia;
        kq.ds.push_back(d[i]);
    }
    }
    return kq;
    
}

void inKQC(KQC kqC){
    if(kqC.soGT>0){
        cout<<"Co the mua duoc nhieu nhat la: "<<kqC.soGT<<endl;
        cout<<"Danh sach giao trinh duoc mua la: "<<endl;
        inDS(kqC.ds);
    }
}
int BMH(string P, string T) {
    int m = P.length();
    int n = T.length();
    
    if (m > n) return -1;

    // Khởi tạo bảng dịch chuyển d
    int d[256];
    for (int i = 0; i < 256; i++) {
        d[i] = m; // Mặc định nhảy m ký tự
    }
    for (int i = 0; i < m - 1; i++) {
        d[P[i]] = m - 1 - i;
    }

    // Tiến hành tìm kiếm
    int i = m - 1; // Chỉ số trên văn bản T
    while (i < n) {
        int k = 0; // Số ký tự trùng khớp tính từ bên phải sang
        while (k < m && P[m - 1 - k] == T[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1; // Tìm thấy xâu P tại vị trí này
        } else {
            i += d[T[i]]; // Nhảy bước theo bảng dịch chuyển
        }
    }
    return -1; // Không tìm thấy
}
string toLower(string s){
    transform(s.begin(),s.end(),s.begin(),::tolower);
    return s;
}
void kqBMH(vector<GiaoTrinh> d){
    string mau= "lap trinh";
    vector<GiaoTrinh> dsLT;
    for(int i=0;i<d.size();i++){
        string ten = toLower(d[i].ten);
        if(BMH(mau,ten)!=-1){
            dsLT.push_back(d[i]);
        }
    }
    if(!dsLT.empty()){
        cout<<"Co "<<dsLT.size()<<" giao trinh thuoc ve lap trinh"<<endl;
        inDS(dsLT);
    }
}
int main(){
    vector<GiaoTrinh> d ={
        {"Lap trinh CSDL","An Van Minh",25},
        {"Lap trinh C++","Vuong Quoc Dung",30},
        {"Lap trinh Python","Hu Truc",32},
        {"Ngon ngu lap trinh Java","Doan Du",40},
        {"Than dieu dai hiep ","Kim Dung",50},
    };
    int p=100;
    int n=d.size();
    KQC kqC = C(p,n,d);
    inKQC(kqC);
    cout<<"----------------------------------------------"<<endl;
    kqBMH(d);
    return 0;

}