#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Hàm phụ trợ: Tìm vị trí xuất hiện CUỐI CÙNG của ký tự 'c' trong chuỗi mẫu 'P'
// Nếu không tìm thấy, trả về -1
int char_in_string(char c, string P) {
    int do_dai_mau = P.length();
    
    // Duyệt từ cuối chuỗi lên đầu chuỗi để tìm vị trí xuất hiện cuối cùng
    for (int i = do_dai_mau - 1; i >= 0; i--) {
        if (P[i] == c) {
            return i; // Trả về chỉ số vị trí tìm thấy
        }
    }
    return -1; // Không tìm thấy ký tự này trong chuỗi mẫu
}

// Hàm thuật toán Boyer-Moore-Horspool phiên bản Việt hóa
bool Boyer_Moore_Hospool(string P, string T) {
    int v = P.length(); // Độ dài chuỗi mẫu (Pattern)
    int i = v - 1;      // Biến 'i' chạy trên văn bản T, bắt đầu từ vị trí đuôi của chuỗi mẫu

    // Vòng lặp quét qua toàn bộ văn bản T
    while (i < T.length()) {
        int khop_duoi = i; // Lưu lại vị trí đuôi cố định của lượt khớp này để tính bước nhảy
        int k = v - 1;     // Biến 'k' chạy ngược từ cuối chuỗi mẫu P về đầu

        // Vòng lặp so khớp từ PHẢI SANG TRÁI
        while (k > -1 && T[i] == P[k]) {
            i--; 
            k--;
        }

        // Nếu k < 0 tức là biến k đã chạy qua hết vị trí 0 -> Đã khớp hoàn toàn chuỗi P
        if (k < 0) {
            return true;
        }
        else {
            // Khi bị lệch khớp, ta dựa vào ký tự lỗi thực sự tại vị trí đuôi (T[khop_duoi]) để nhảy
            int x = char_in_string(T[khop_duoi], P);
            
            if (x < 0) {
                // Trường hợp 1: Ký tự lỗi không có trong P -> Nhảy cóc vượt qua vị trí đuôi này
                i = khop_duoi + v;
            }
            else {
                // Trường hợp 2: Ký tự lỗi có trong P -> Dịch sao cho ký tự trong P thẳng hàng với văn bản
                i = khop_duoi + v - x - 1;
            }
        }
    }
    return false; // Đã duyệt hết văn bản mà không tìm thấy chuỗi mẫu
}

int main() {
    // Khởi tạo văn bản (T) và chuỗi mẫu cần tìm (P)
    string T = "HANOI UNIVERSITY OF INDUSTRY"; 
    string P = "INDUSTRY";                     

    cout << "Van ban (T): " << P << endl;
    cout << "Chuoi mau can tim (P): " << T << endl;
    cout << "---------------------------------------" << endl;

    if (Boyer_Moore_Hospool(P, T)) {
        cout << "=> KET QUA: Tim thay chuoi mau \"" << T << "\" trong van ban!" << endl;
    } else {
        cout << "=> KET QUA: Khong tim thay chuoi mau!" << endl;
    }


    return 0;
}