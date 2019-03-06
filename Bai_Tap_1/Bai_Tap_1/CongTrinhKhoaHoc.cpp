#include "CongTrinhKhoaHoc.h"
#include<iostream>
using namespace std;
// Ham Dung day du tham so
CongTrinhKhoaHoc::CongTrinhKhoaHoc(string mct, int  nsx, bool kvxb)
{
	this->MCT = mct;
	this->NXB = nsx;
	this->KVXB= kvxb;
}
// Dinh Nghia Phuong Thuc Hien Thi
void CongTrinhKhoaHoc::Show() {
	cout << "Ma Cong Trinh : " << this->MCT << endl;
	cout << "Nam Xuat Ban : " << this->NXB << endl;
	cout << "Khu Vuc Xuat Ban : " << this->KVXB << endl;
}
//Da Nang Hoa toan tu = 
const CongTrinhKhoaHoc& CongTrinhKhoaHoc::operator=(const CongTrinhKhoaHoc &ctkh) {
	this->MCT = ctkh.MCT;
	this->NXB = ctkh.NXB;
	this->KVXB = ctkh.KVXB;
	return *this;
}
// Ham Huy
CongTrinhKhoaHoc::~CongTrinhKhoaHoc()
{
}