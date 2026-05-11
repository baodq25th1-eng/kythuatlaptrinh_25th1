
#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    float diemCC;  
    float diemGK;  
    float diemCK;  
    float diemHP;   

    friend istream& operator>>(istream& in, SinhVien& sv) {
        cout << "Nhap thong tin sinh vien:";
        cout << "\t+ Ma SV: ";
        in >> sv.maSV;
        in.ignore();
        cout << "\t+ Ho ten: ";
        getline(in, sv.hoTen);
        cout << "\t+ Diem chuyen can: ";
        in >> sv.diemCC;
        cout << "\t+ Diem giua ky: ";
        in >> sv.diemGK;
        cout << "\t+ Diem cuoi ky: ";
        in >> sv.diemCK;
        sv.diemHP = sv.diemCC * 0.1 + sv.diemGK * 0.3 + sv.diemCK * 0.6;
        return in;
    }

    friend ostream& operator<<(ostream& out, SinhVien& sv) {
        out << "\t+ Ma SV: " << sv.maSV << endl;
        out << "\t+ Ho ten: " << sv.hoTen << endl;
        out << "\t+ Diem HP: " << sv.diemHP << endl;
        return out;
    }
};

#define MAX 100
int nSV = 0;
SinhVien ds[MAX];


void AddSV(SinhVien sv) {
    if (nSV >= MAX) {
        cout << "Vuot qua so luong toi da!" << endl;
        return;
    }
    ds[nSV++] = sv;
}


void Show() {
    for (int i = 0; i < nSV; i++) {
        cout << "Sinh vien [" << (i + 1) << "]" << endl;
        cout << ds[i];
    }
}


void SortByHP() {
    for (int i = 0; i < nSV - 1; i++) {
        for (int j = i + 1; j < nSV; j++) {
            if (ds[j].diemHP > ds[i].diemHP) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}


void SortByMa() {
    for (int i = 0; i < nSV - 1; i++) {
        for (int j = i + 1; j < nSV; j++) {
            if (ds[j].maSV < ds[i].maSV) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

int BinarySearch(string ma) {
    int left = 0, right = nSV - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (ds[mid].maSV == ma) return mid;
        else if (ds[mid].maSV < ma) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    do {
        system("cls");
        cout << "------- QUAN LY SINH VIEN ------------" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Hien thi danh sach" << endl;
        cout << "3. Sap xep giam dan theo diem HP" << endl;
        cout << "4. Tim kiem sinh vien theo ma so" << endl;
        cout << "0. Thoat" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Chon: ";
        int choose;
        cin >> choose;
        switch (choose) {
        case 1: {
            SinhVien sv;
            cin >> sv;
            AddSV(sv);
            break;
        }
        case 2: {
            Show();
            break;
        }
        case 3: {
            SortByHP();
            cout << "Da sap xep giam dan theo diem HP!";
            break;
        }
        case 4: {
            SortByMa();
            string ma;
            cout << "Nhap ma SV can tim: ";
            cin >> ma;
            int pos = BinarySearch(ma);
            if (pos != -1) {
                cout << "Tim thay sinh vien:";
                cout << ds[pos];
            }
            else {
                cout << "Khong tim thay sinh vien co ma " << ma << endl;
            }
            break;
        }
        case 0:
            return 0;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
        system("pause");
    } while (true);
}
