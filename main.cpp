#include "header.h"
#include <iostream> // ?ã có trong header.h
using namespace std;

int main() {
    Node* dau = nullptr;
    string tmp;  // ??c t?t c? input d??i d?ng string
    int chon = -1;

    do {
        cout << "\n=====MENU====\n";
        cout << "1. Them sinh vien\n";
        cout << "2. In danh sach sinh vien\n";
        cout << "3. Xoa sinh vien\n";
        cout << "4. Tim sinh vien\n";
        cout << "5. Tim sinh vien co GPA cao nhat\n";
        cout << "6. Tim sinh vien co GPA thap nhat\n";
        cout << "7. Cap nhat danh sach sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";

        getline(cin, tmp);
        if (tmp.empty()) continue;

        chon = stoi(tmp); // chuy?n string sang s? nguyên

        switch (chon) {
        case 1: {
            SinhVien sv;
            cout << "Nhap MSSV: ";
            getline(cin, sv.mssv);
            cout << "Nhap ten SV: ";
            getline(cin, sv.name);
            cout << "Nhap GPA: ";
            getline(cin, tmp);
            sv.gpa = stof(tmp); // chuy?n string sang float

            themCuoi(dau, sv); // thêm sinh viên vào cu?i danh sách
            cout << "Da them sinh vien!\n";
            break;
        }
        case 2:
            inDS(dau);
            break;
        case 3: {
            cout << "Nhap MSSV can xoa: ";
            string mssv;
            getline(cin, mssv);
            xoaSV(dau, mssv);
            break;
        }
        case 4: {
            cout << "Nhap MSSV can tim: ";
            string mssv;
            getline(cin, mssv);
            timSV(dau, mssv);
            break;
        }
        case 5:
            sapXepSVTheoGPA(dau);
            break;
        case 6:
            timSVCoGPAThapNhap(dau);
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);

    return 0;
}