#include "List.h"
#include"CongTrinhKhoaHoc.h"
#include<iostream>
using namespace std;

// Ham dung day du tham so
List::List(int number)
{
	this->Number = number;
	this->data = new CongTrinhKhoaHoc[this->Number];
}
// Dinh Nghia Phuong Thuc Hien Thi
void List::Show() {
	for (int i = 0; i < this->Number; i++) {
		(this->data + i)->Show();
		cout << endl;
	}
	cout << this->Number << endl;
}
// Dinh Nghia Phuong Thuc Them Phuong Thuc
void List::Add(int k, CongTrinhKhoaHoc &p) {
	if (k < 0)
		k = 0;
	if (k >= this->Number)
		k = this->Number;
	CongTrinhKhoaHoc* data1 = new CongTrinhKhoaHoc[this->Number];
	for (int i = 0; i < this->Number; i++) {
		*(data1 + i) = *(data + i);
	}
	delete[] this->data;
	this->Number++;
	this->data = new CongTrinhKhoaHoc[this->Number];
	for (int i = 0; i < k; i++) {
		*(this->data + i) = *(data1 + i);
	}
	*(this->data + k) = p;

	for (int i = k + 1; i < this->Number; i++) {
		*(this->data + i) = *(data1 + i - 1);
	}
	delete[] data1;
}
// Dinh Nghia Phuong Thuc Cap Nhat
void List::Update(int k, CongTrinhKhoaHoc & ct) {
	if (k < 0)
		k = 0;
	if (k >= this->Number)
		k = this->Number - 1;
	*(data + k) = ct;
}
// Dinh Nghia phuong Thuc Xoa
void List::Delete(int k) {
	if (k < 0)
		k = 0;
	if (k >= this->Number)
		k = this->Number - 1;
	CongTrinhKhoaHoc *data1 = new CongTrinhKhoaHoc[this->Number];
	for (int i = 0; i < this->Number; i++) {
		*(data1 + i) = *(this->data + i);
	}
	delete[] this->data;
	this->Number--;
	this->data = new CongTrinhKhoaHoc[this->Number];
	for (int i = 0; i < k; i++) {
		*(this->data + i) = *(data1 + i);
	}
	for (int i = k; i < this->Number; i++) {
		*(this->data + i) = *(data1 + i + 1);
	}
	delete[] data1;
}
// Dinh nghia Phuong thuc hien so luong phan tu list
int List::ShowLength() {
	return this->Number;
}
// Dinh Nghia Phuong Thuc Tim Kiem Noi Suy Tra ve Vi tri
List* List::Search(int nxb) {
	int posl = 0, posr = 0, count = 0;
	int* temp = new int[this->Number];

	// Tao mang de sap xep roi tim kiem
	List tempList(this->Number);
	for (int i = 0; i < this->Number; i++) {
		*(tempList.data + i) = *(this->data + i);
	}
	tempList.Sort(List::Inc);
	// Thuat toan tim kiem noi suy
	int left = 0;
	int right = this->Number - 1;
	while (left <= right && nxb >= (tempList.data + left)->NXB && nxb <= (tempList.data + right)->NXB) {
		double val1 = (double)(nxb - (tempList.data + left)->NXB) / ((tempList.data + right)->NXB - (tempList.data + left)->NXB);
		int val2 = (right - left);
		int pos = left + val1*val2;
		if ((tempList.data + pos)->NXB == nxb) {
			posr = pos + 1;
			posl = pos - 1;
			*(temp + count) = pos;
			count++;
			while ((tempList.data + posr)->NXB == nxb) {
				*(temp + count) = posr;
				count++;
				if (posr < this->Number)
					posr++;
				else
					break;
			}
			while ((tempList.data + posl)->NXB == nxb) {
				*(temp + count) = posl;
				count++;
				if (posl > 0)
					posl--;
				else
					count--;
					break;
			}

			int* tempres = new int[count];
			for (int i = 0; i < count; i++) {
				*(tempres + i) = *(temp + i);
			}
			static List Listres(count);
			for (int i = 0; i < count; i++) {
				*(Listres.data + i) = *(tempList.data + *(tempres + i));
			}
			delete[] temp;
			return &Listres;
		}
		if ((tempList.data + pos)->NXB < nxb) {
			left = pos + 1;
		}
		if ((tempList.data + pos)->NXB > nxb) {
			right = pos - 1;
		}
	}

	static List Listres0(0);
	cout << "\t: >> Khong co phan tu can tim" << endl;
	delete[] temp;
	return &Listres0;
}


// Dinh Nghia Phuong Thuc Sap Xep
// Ham Dec
bool List::Dec(int left, int right) {
	if (left < right) {
		return true;
	}
	else
		return false;
}
// Ham Inc
bool List::Inc(int left, int right) {
	if (left > right) {
		return true;
	}
	else
		return false;
}
// Con Tro Ham
bool(*p)(int left, int right);
// Ham Tron
void Merger(List &temp, int left, int mid, int right) {
	CongTrinhKhoaHoc *tempctkh;
	int i = left;
	int j = mid + 1;
	int k = 0;
	tempctkh = new CongTrinhKhoaHoc[right - left +1];

	while (i <= mid && j <= right) {
		if (  (temp.data + i)->NXB < (temp.data + j)->NXB  ) {
			*(tempctkh + k) = *(temp.data + i);
			k++;
			i++;
		}
		else {
			*(tempctkh + k) = *(temp.data + j);	
			k++;
			j++;
		}	
	}
	while (i <= mid) {
		*(tempctkh + k) = *(temp.data + i);
		k++;
		i++;
	}
	while (j <= right) {
		*(tempctkh + k) = *(temp.data + j);
		k++;
		j++;
	}
	for (int k = left; k <= right ; k++) {
		*(temp.data + k) = *(tempctkh + k - left);
	}
	delete[] tempctkh;
}
// Ham sap xep tron
void MergerSort(List &temp, int left, int right ) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergerSort(temp, left, mid);
		MergerSort(temp, mid + 1, right);

		Merger(temp, left, mid, right);
	}
}
void List::Sort(bool(*p)(int left, int right)) {
	List temp(this->Number);
	for (int i = 0; i < this->Number; i++) {
		*(temp.data + i) = *(this->data + i);
	}
	
	MergerSort(temp, 0, this->Number - 1);
	if (p(2, 1)) {
		for (int i = 0; i < this->Number; i++) {
			*(this->data + i) = *(temp.data + i);
		}
	}
	else {
		for (int i = 0; i < this->Number; i++) {
			*(this->data + i) = *(temp.data + this->Number - i - 1);
		}
	}
}
//Da nang hoa toan tu =
const List& List::operator=(const List &list) {

	this->Number = list.Number;
	delete[] this->data;
	this->data = new CongTrinhKhoaHoc[this->Number];
	for (int i = 0; i < this->Number; i++) {
		*(this->data + i) = *(list.data + i);
	}
	return *this;
}
// Da nang hoa toan tu []
CongTrinhKhoaHoc& List::operator[](int i) {
	static CongTrinhKhoaHoc tam;
	if (i >= 0 && i < this->Number) {
		return *(this->data + i);
	}
	else {
		cout << "Error";
		return tam;
	}	
}
// Ham Huy
List::~List()
{
	delete[] data;
}
