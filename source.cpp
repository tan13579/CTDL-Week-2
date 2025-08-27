#include"header.h"
using namespace std;
void themCuoi(Node*& dau, SinhVien sv) {
	Node* moi = new Node;
	moi->duLieu = sv;
	moi->ketiep = nullptr;
	if (dau == nullptr) {
		dau = moi;
		return;
	}
	Node* tam = dau;
	while (tam->ketiep != nullptr) {
			tam=tam->ketiep;
	}
	tam->ketiep = moi;
	
}
void inDS(Node* dau) {
	Node* tam = dau;
	int demSV = 1;
	while (tam != nullptr) {
		cout<<"Sinh Vien thu: " << demSV << endl;
		cout << "Ten SV la: " << tam->duLieu.name << endl;
		cout << "MSSV la: " << tam->duLieu.mssv << endl;
		cout << "GPA la: " << tam->duLieu.gpa << endl;
		demSV++;
		tam = tam->ketiep;
	}
}
void timSV(Node* dau, string MSSVCanTim) {
	int viTri = 0;
	if (dau == nullptr) {
		cout << "danh sach rong " << endl;
		return;
	}
	Node* tam = dau;
	while (tam != nullptr) {
		if (tam->duLieu.mssv == MSSVCanTim) {
			cout << "da tim thay sinh vien co ma so " << MSSVCanTim <<" tai vi tri "<<viTri<< endl;
			return;
		}
		tam = tam->ketiep;
		viTri++;
	}
	cout << "khong tim thay sinh vien! " << endl;
}
void xoaSV(Node* dau, string MSSVCanXoa) {
	if (dau == nullptr) {
		cout << "DS rong k the xoa " << endl;
		return;
	}
	if (dau->duLieu.mssv == MSSVCanXoa) {
		Node* tam = dau;
		dau = dau->ketiep;
		delete tam;
	}
	Node* truoc = dau;
		Node * hienTai = dau->ketiep;
		while (hienTai != nullptr) {
			if (hienTai->duLieu.mssv == MSSVCanXoa) {
				truoc->ketiep = hienTai->ketiep;
				delete hienTai;
				cout << "da xoa sinh vien " << MSSVCanXoa <<" tai vi tri "<< endl;
				return;
			}
			truoc = hienTai;
			hienTai = hienTai->ketiep;
		}
		cout << "khong tim thay MSSV" << endl;
}
void themDau(Node*& dau, SinhVien sv) {
	Node* moi = new Node;
	moi->duLieu = sv;
	moi->ketiep = dau;
	dau=moi;
}
void sapXepSVTheoGPA(Node*& dau) {
	if (dau == nullptr) {
		cout << "danh sach rong" << endl;
		return;
	}
	Node* MaxGPA = dau;
	Node* hienTai = dau->ketiep;
	while (hienTai != nullptr) {
		if (hienTai->duLieu.gpa > MaxGPA->duLieu.gpa) {
			MaxGPA = hienTai;
		}
		hienTai = hienTai->ketiep;
	}
	cout << "sinh vien co GPA cao nhat la " << endl;
	cout << "ten sinh vien co GPA cao nhat" << MaxGPA->duLieu.name << endl;
	cout << "MSSV co GPA cao nhat " << MaxGPA->duLieu.mssv << endl;
	cout << "GPA cao nhat" << MaxGPA->duLieu.gpa << endl;
}
void timSVCoGPAThapNhap(Node*& dau) {
	if (dau == nullptr) {
		cout << "danh sach rong" << endl;
		return;
	}
	Node* MinGPA = dau;
	Node* hienTai = dau->ketiep;
	while (dau != nullptr) {
		if (hienTai->duLieu.gpa < MinGPA->duLieu.gpa) {
			MinGPA = hienTai;
		}
		hienTai = hienTai->ketiep;
	}
	cout << "sinh vien co GPA thap nhat la " << endl;
	cout << "ten sinh vien co GPA thap nhat la" << MinGPA->duLieu.name << endl;
	cout << "MSSV co GPA thap nhat la " << MinGPA->duLieu.mssv << endl;
	cout << "GPA thap nhat la " << MinGPA->duLieu.gpa << endl;

}