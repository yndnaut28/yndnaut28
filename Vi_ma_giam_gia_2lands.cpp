#include<bits/stdc++.h>
using namespace std;

struct SinhVien{
    string msv, sex, name;
	double t, l, h, tb;
};
bool cmp1(SinhVien &a, SinhVien &b){
	return a.tb > b.tb;
}

int main(){
    int n; cin >> n;
    struct SinhVien a[n + 1];
    for(int i = 1; i <= n; i++){
    	double to, ly, ho;
		  cin.ignore();
      getline(cin, a[i].msv);
      getline(cin, a[i].name);
      getline(cin, a[i].sex);
      cin >> to >> ly >> ho;
      a[i].t = to;
      a[i].l = ly;
      a[i].h = ho;
      a[i].tb = (a[i].t + a[i].l + a[i].h) / 3;
    }
    int ok = 1;
    while(ok != 0){
    	cout << "Nhap yeu cau cua ban theo menu sau:\n";
    	cout << "0. Dung lai\n";
	cout << "1. In ra danh sach sinh vien\n";
    	cout << "2. Tinh diem trung binh 3 mon cua cac sinh vien\n";
    	cout << "3. Diem trung binh cua sinh vien theo thu tu tang dan\n";
    	cout << "4. Xep loai sinh vien theo diem trung binh\n";
    	cout << "5. Tim sinh vien co diem trung binh cao nhat\n";
    	cout << "6. Tim kiem sinh vien theo ho ten\n";
    	int id; cin >> id;
	if(id == 1){
        	cout << "Danh sach sinh vien: \n";
        	for(int i = 1; i <= n; i++)
          	cout << a[i].msv << " | " << a[i].name << " | " << a[i].sex << '\n';
	}
	else if(id == 2)
        	for(int i = 1; i <= n; i++)
        		cout << a[i].msv << " co diem trung binh: " << fixed << setprecision(2) << a[i].tb << '\n';
      	else if(id == 3){
        	cout << "Diem trung binh cua sinh vien theo thu tu tang dan la: \n";
		sort(a + 1, a + 1 + n, cmp1);
		for(int i = 1; i <= n; i++)
			cout << i << ". " << a[i].msv << " co diem trung binh: " << fixed << setprecision(2) << a[i].tb << '\n';
	}
	else if(id == 4){
		for(int i = 1; i <= n; i++){
			if(a[i].tb >= 8.0) cout << a[i].msv << " | Xep loai: Gioi\n";
			else if(a[i].tb < 8.0 && a[i].tb >= 6.0) cout << a[i].msv << " | Xep loai: Kha\n";
			else if(a[i].tb < 6.0 && a[i].tb >= 4.0) cout << a[i].msv << " | Xep loai: Trung binh\n";
			else if(a[i].tb < 4.0) cout << a[i].msv << " | Xep loai: Yeu\n";
		}
	}
	else if(id == 5){
		sort(a + 1, a + 1 + n, cmp1);
		for(int i = 1; i <= n; i++){
			cout << "Sinh vien co diem trung binh cao nhat la: " << a[i].msv << " | " << a[i].tb << '\n';
			if(a[i].tb > a[i + 1].tb) break;
		}
		}
	else if(id == 6){
		cin.ignore();
		string name_find; getline(cin, name_find);
		int res = 0;
		for(int i = 1; i <= n; i++){
			if(name_find == a[i].name){
				res = 1;
				cout << "Tra lai ket qua tim kiem: ";
				cout << a[i].msv << " | " << a[i].name << " | " << a[i].sex << '\n';
			}
		}
		if(res == 0) cout << "Khong co ket qua tim kiem!\n";
	}
        ok = id;
    }
    return 0;
}
