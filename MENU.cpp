#include<bits/stdc++.h>
using namespace std;

int main(){
    // Nhap so nguyen n va mang gom n phan tu
    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << "\nMENU\n" 
         << "1. Tinh trung binh cong so le trong mang.\n"
         << "2. Tim so lon nhat trong mang.\n"
         << "3. Tim vi tri cac so lon nhat trong mang.\n"
         << "4. Dem so chan trong mang.\n"
         << "5. Sap xep mang theo thu tu tang dan.\n";
    //Nhap yeu cau thuc hien
    cout << "Nhap so thu tu cua cong viec can lam: ";
    int id; cin >> id; cout << '\n';
    //Xu ly du lieu bo nho tam
    int tmp[n + 1] = {0};
    for(int i = 1; i <= n; i++) 
        tmp[i] = a[i];
    sort(tmp + 1, tmp + 1 + n);
    //Thuc hien yeu cau duoc chon
    if(id == 1){
        cout << "Trung binh cong cac so le trong mang la: ";
        int sum_le = 0, res = 0;
        for(int i = 1; i <= n; i++)
            if(a[i] % 2 == 1){ 
                sum_le += a[i];
                res++;
            }
        //cout << sum_le << ' ' << res << '\n';
        cout << (double)sum_le / res << fixed << setprecision(3) << '\n';
    }
    else if(id == 2)
        cout << "So lon nhat trong mang la:" << tmp[n] << '\n';
    else if(id == 3){
        cout << "Vi tri cac so lon nhat: ";
        for(int i = 1; i <= n; i++)
            if(a[i] == tmp[n]) 
                cout << i << ' ';
        cout << '\n';
    }
    else if(id == 4){
        int res = 0;
        for(int i = 1; i <= n; i++)
            if(a[i] % 2 == 0) res++;
        cout << "So luong so chan cua mang la: " << res << '\n';
    }
    else if(id == 5){
        cout << "Thu tu tang dan cua mang la: ";
        for(int i = 1; i <= n; i++)
            cout << tmp[i] << ' ';
    }
    return 0;
}
