#pragma once
#include"CongTrinhKhoaHoc.h"
#include<iostream>
using namespace std;
class CongTrinhKhoaHoc;
class List
{
private:
	CongTrinhKhoaHoc* data;
	int Number;
public:
	List(int =1);
	void Show();
	void Add(int , CongTrinhKhoaHoc&);
	void Update(int, CongTrinhKhoaHoc&);
	void Delete(int = 0);
	int ShowLength();
	static bool Dec(int, int);
	static bool Inc(int, int);
	static bool(*p)(int, int);
	friend void Merger(List &, int , int , int );
	List* Search(int);
	void Sort(bool(*p)(int left, int right));
	CongTrinhKhoaHoc& operator[](const int);
	friend ostream& operator<<(ostream&, List&);
	friend istream& operator>>(istream&, List&);
	const List& operator=(const List &);
	~List();
};
