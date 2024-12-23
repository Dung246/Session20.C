 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char maSP[20];
    char tenSP[50];
    float giaNhap;
    float giaBan;
    int soLuong;
} SanPham;

SanPham danhSachSP[MAX_PRODUCTS];
int soLuongSP = 0;
float doanhThu = 0;

int timKiemSP(char maSP[]) {
    for (int i = 0; i < soLuongSP; i++) {
        if (strcmp(danhSachSP[i].maSP, maSP) == 0) {
            return i; 
        }
    }
    return -1; 
}

void nhapSanPham() {
    SanPham sp;
    printf("Nhap ma san pham: ");
    scanf("%s", sp.maSP);

    int index = timKiemSP(sp.maSP);
    if (index != -1) {
        printf("San pham da ton tai. Nhap so luong them vao: ");
        int soLuongThem;
        scanf("%d", &soLuongThem);
        danhSachSP[index].soLuong += soLuongThem;
        doanhThu -= soLuongThem * danhSachSP[index].giaNhap;
        printf("Da cap nhat so luong san pham.\n");
        return;
    }

    printf("Nhap ten san pham: ");
    scanf(" Ten san pham : ", sp.tenSP); 
    printf("Nhap gia nhap: ");
    scanf("%f", &sp.giaNhap);
    printf("Nhap gia ban: ");
    scanf("%f", &sp.giaBan);
    printf("Nhap so luong: ");
    scanf("%d", &sp.soLuong);

    danhSachSP[soLuongSP++] = sp;
    doanhThu -= sp.soLuong * sp.giaNhap;
    printf("Da them san pham moi.\n");
}

void hienThiDSSP() {
    if (soLuongSP == 0) {
        printf("Danh sach san pham trong.\n");
        return;
    }
    printf("Danh sach san pham:\n");
    printf("%-20s %-50s %-10s %-10s %-10s\n", "Ma SP", "Ten SP", "Gia Nhap", "Gia Ban", "So Luong");
    for (int i = 0; i < soLuongSP; i++) {
        printf("%-20s %-50s %-10.2f %-10.2f %-10d\n", danhSachSP[i].maSP, danhSachSP[i].tenSP, danhSachSP[i].giaNhap, danhSachSP[i].giaBan, danhSachSP[i].soLuong);
    }
}

void banSanPham() {
    char maSP[20];
    int soLuongBan;

    printf("Nhap ma san pham can ban: ");
    scanf("%s", maSP);

    int index = timKiemSP(maSP);
    if (index == -1) {
        printf("Khong tim thay san pham.\n");
        return;
    }

    printf("Nhap so luong can ban: ");
    scanf("%d", &soLuongBan);

    if (danhSachSP[index].soLuong == 0) {
        printf("Het hang.\n");
    } else if (soLuongBan > danhSachSP[index].soLuong) {
        printf("Khong con du hang.\n");
    } else {
        danhSachSP[index].soLuong -= soLuongBan;
        doanhThu += soLuongBan * danhSachSP[index].giaBan;
        printf("Ban hang thanh cong.\n");
    }
}

void hienThiDoanhThu() {
    printf("Doanh thu hien tai: %.2f\n", doanhThu);
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Ban san pham\n");
        printf("5. Doanh thu hien tai\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 3:
                nhapSanPham();
                break;
            case 2:
                hienThiDSSP();
                break;
            case 4:
                banSanPham();
                break;
            case 5:
                hienThiDoanhThu();
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 0);

    return 0;
}
