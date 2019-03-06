#pragma once
#include<string>
#include<iostream>
using namespace std;
using namespace std;
class CongTrinhKhoaHoc
{
private:
	string MCT;
	int NXB;
	bool KVXB;
public:
	void Show();
	friend class List;
	friend ostream& operator<<(ostream &, CongTrinhKhoaHoc&);
	friend istream& operator>>(istream &, CongTrinhKhoaHoc&);
	friend void Merger(List &, int , int , int );
	const CongTrinhKhoaHoc& operator=(const CongTrinhKhoaHoc &);
	CongTrinhKhoaHoc(string ="M01", int =1980, bool =false);
	~CongTrinhKhoaHoc();
};