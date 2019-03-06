#include<iostream>
#include"CongTrinhKhoaHoc.h"
#include"List.h"
#include<iomanip>
using namespace std;
// Da Nang Hoa Toan Tu Nhap o Ham Main cua Class CTKH
ostream& operator<<(ostream &o, CongTrinhKhoaHoc &ctkh) {
	o << "\t==================================" << endl;
	o << "\t|| Ma Cong Trinh"<< "\t" << ": " << ctkh.MCT << "\t||" << endl;
	o << "\t|| Nam Xuat Ban" << "\t\t" << ": " << ctkh.NXB << "\t||" << endl;
	o << "\t|| Khu Vuc Xuat Ban" << "\t" << ": " << ctkh.KVXB << "\t||" << endl;
	o << "\t==================================" << endl;
	return o;
}
// Da Nang Hoa Toan Tu Xuat o Ham Main cua Class CTKH
istream& operator>>(istream &i, CongTrinhKhoaHoc &ctkh) {
	cout << "\t: >> Nhap Ma Cong Trinh \t\t: ";
	i >> ctkh.MCT;
	do {
		cout << "\t: >> Nhap Nam Xuat Ban ( > 1900)\t: ";
		i >> ctkh.NXB;
	} while (ctkh.NXB < 1900);
	int temp = 0;
	do {
		cout << "\t: >> Nhap Khu Vuc Xuat Ban ( 0/1 )\t: ";
		cin >> temp;
	} while (temp < 0 || temp > 1);
	if (temp == 1)
		ctkh.KVXB = 1;
	else
		ctkh.KVXB = 0;
	return i;
}
// Da Nang Hoa Toan Tu Xuat o Ham Main cua Class List
ostream& operator<<(ostream &o, List &list) {
	for (int i = 0; i < list.Number; i++) {
		o << list[i];
		o << endl;
	}
	//o << list.Number << endl;
	return o;
}
// Da Nang Hoa Toan Tu Nhap o Ham Main cua Class List
istream& operator>>(istream &i, List &list) {
	for (int i = 0; i < list.Number; i++) {
		cout << "\t: >> Nhap Phan Tu thu : " << i << endl;
		cin >> list[i];
		cout << endl;
	}
	return i;
}

int main() {
	int control = 0;
	List DefLis(0);
	while (1) {
//		Khung
		cout << "==========================================================" << endl;
		cout << "||\t" << "Khoi tao mot mang list\t\t" << "||" << "  Phim 0\t" << "||" << endl;
		cout << "||\t" << "Hien thi mang list hien tai\t" << "||" << "  Phim 1\t" << "||" << endl;
		cout << "||\t" << "Them mot doi tuong vao list\t" << "||" << "  Phim 2\t" << "||" << endl;
		cout << "||\t" << "Cap Nhat thong tin doi tuong\t" << "||" << "  Phim 3\t" << "||" << endl;
		cout << "||\t" << "Xoa doi tuong\t\t\t" << "||" << "  Phim 4\t" << "||" << endl;
		cout << "||\t" << "Sap xep doi tuong\t\t" << "||" << "  Phim 5\t" << "||" << endl;
		cout << "||\t" << "Tim kiem doi tuong\t\t" << "||" << "  Phim 6\t" << "||" << endl;
		cout << "||\t" << "Thoat khoi chuong trinh\t\t" << "||" << "  Phim 7\t" << "||" << endl;
		cout << "==========================================================" << endl;
//		Ep dieu kien cho control
		do {
			cout << "cin >>\t: ";
			cin >> control;
		} while (control > 7 || control < 0);
//		Dieu Kien
		switch (control)
		{
			// Khoi tao mang
		case 0: {
			int n = 0;
			cout << "Nhap so luong phan tu cua list\t: " ;
			cin >> n;
			List lis(n);
			cin >> lis;
			DefLis = lis;
			cout << "\t: >> Done" << endl;
			break;
		}
			// Hien thi
		case 1: {
			cout << DefLis;
			cout << "\t: >> Done" << endl;
			break;
		}
			// Them
		case 2: {
			int index = 0;
			char cindex;
			CongTrinhKhoaHoc addCTKH;
			cout << "\t: >> Nhap thuoc tinh cua doi tuong them vao" << endl;
			cin >> addCTKH;
			cout << "\t: >> Nhap vi tri them vao phan tu moi" << endl;
			cout << "\t: >> Them vao dau List (b), cuoi mang (e), vi tri bat ki k : ";
			cin >> cindex;
			if (cindex == 'b')
				DefLis.Add(0, addCTKH);
			else if (cindex == 'e')
				DefLis.Add(DefLis.ShowLength(), addCTKH);
			else
				DefLis.Add(int(cindex) - 48, addCTKH);
			cout << "\t: >> Done" << endl;
			break;
		}
			// Cap nhat
		case 3: {
			if (DefLis.ShowLength() == 0) {
				cout << "\t: >> List khong co phan tu de cap nhat" << endl;
				cout << "\t: >> Done" << endl;
				break;
			}
			int index = 0;
			char cindex;
			CongTrinhKhoaHoc updateCTKH;
			cout << "\t: >> Nhap thuoc tinh cua doi tuong duoc cap nhat" << endl;
			cin >> updateCTKH;
			cout << "\t: >> Nhap vi tri cap nhat phan tu moi" << endl;
			cout << "\t: >> Cap nhat vao dau List (b), cuoi mang (e), vi tri bat ki k : ";
			cin >> cindex;
			if (cindex == 'b')
				DefLis.Update(0, updateCTKH);
			else if (cindex == 'e')
				DefLis.Update(DefLis.ShowLength() - 1, updateCTKH);
			else
				DefLis.Update(int(cindex) - 48, updateCTKH);
			cout << "\t: >> Done" << endl;
			break;
		}
			// Xoa
		case 4: {
			if (DefLis.ShowLength() == 0) {
				cout << "\t: >> List khong co phan tu de xoa" << endl;
				cout << "\t: >> Done" << endl;
				break;
			}
			int index = 0;
			char cindex;
			cout << "\t: >> Nhap vi tri muon xoa" << endl;
			cout << "\t: >> Cap nhat vao dau List (b), cuoi mang (e), vi tri bat ki k : ";
			cin >> cindex;
			if (cindex == 'b')
				DefLis.Delete(0);
			else if (cindex == 'e')
				DefLis.Delete(DefLis.ShowLength());
			else
				DefLis.Delete(int(cindex) - 48);
			cout << "\t: >> Done" << endl;
			break;
		}
			// Sap xep
		case 5: {
			if (DefLis.ShowLength() == 0) {
				cout << "\t: >> List khong co phan tu de sap xep" << endl;
				cout << "\t: >> Done" << endl;
				break;
			}
			int type = 1;
			cout << "\t: >> Ban muon sap xep tang dan (1) hay giam dan (2)" << endl;
			cout << "\t: >> ";
			do {
				cin >> type;
			} while (type < 1 || type >2);
			if (type == 1)
				DefLis.Sort(List::Inc);
			else
				DefLis.Sort(List::Dec);
			cout << "\t: >> Done" << endl;
			break;
		}
			 // Tim kiem
		case 6: {
			if (DefLis.ShowLength() == 0) {
				cout << "\t: >> List khong co phan tu de tim kiem" << endl;
				cout << "\t: >> Done" << endl;
				break;
			}
			int Nxb = 1900;
			cout << "\t: >> Nhap Nam Xuat Ban ban muon tim kiem" << endl;
			cout << "\t: >> ";
			cin >> Nxb;
			cout << "\t: >> Hien thi ket qua tim kiem" << endl;
			List *search = DefLis.Search(Nxb);
			cout << *search << endl;
			cout << "\t: >> Done" << endl;
			break;
		}
		case 7: {
			system("pause");
			return 0;
		}
		//default:
		//	cout << "\tRESULT\t" << endl;
		//	cout << DefLis;
		//	break;
		}
	}
	system("pause");
	return 0;
}