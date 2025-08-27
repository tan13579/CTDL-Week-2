#pragma once
#include<iostream>
#include<string>
using namespace std;
struct  SinhVien {
	string name;
	string mssv;
	float gpa;
};
struct Node {
	SinhVien duLieu;
	Node* ketiep;
};
void themCuoi(Node*& dau,SinhVien sv);
void inDS(Node* dau);
void timSV(Node* dau, string MSSVCanTim);
void xoaSV(Node* dau, string MSSVCanXoa);
void themDau(Node*& dau, SinhVien sv);
void sapXepSVTheoGPA(Node*& dau);
void timSVCoGPAThapNhap(Node*& dau);