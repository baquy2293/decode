#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define true 1

typedef struct {
    char maSV[10];
    char hoTen[20];
    int namSinh;
} SinhVien;

SinhVien nhapThongTinSinhVien ()
{
    SinhVien sv;
    printf("\tNhap ma SV: ");
    fflush(stdin);
    gets(sv.maSV);

    printf("\tNhap ho ten: ");
    fflush(stdin);
    gets(sv.hoTen);

    printf("\tNhap nam sinh: ");
    scanf("%d",&sv.namSinh);

    return sv;
}

int taoDanhSachSinhVien (SinhVien dssv[])
{
    int n;
    scanf("%d",&n);

    for (int i=0; i<n; i++)
    {
        printf("\t\tNhap thong tin sinh vien thu %d\n",i+1);
        dssv[i] = nhapThongTinSinhVien();
    }

    return n;
}

void luuThongTinDSSVLenFile (SinhVien dssv[], int n, char* filePath)
{
    //Mở file
    FILE* f = fopen (filePath, "wb");

    //Xử lý thông tin
    for(int i = 0 ; i < n ; i ++)
    {
        fwrite(&dssv[i],sizeof(SinhVien),1,f);
    }
    //Đóng file
    fclose(f);
}

void hienThiMotSinhVien (SinhVien sv)
{
    printf("%10s%20s%8d\n",sv.maSV,sv.hoTen,sv.namSinh);
}

void hienThiDanhSachSinhVien (SinhVien sv[], int n)
{
    printf("\tDANH SACH SINH VIEN\n");
    printf("\t%5s%10s%20s%8s\n","STT","Ma SV", "Ho ten", "Nam sinh");
    for (int i=0; i<n; i++)
    {
        printf("\t%5d",i+1);
        hienThiMotSinhVien(sv[i]);
    }
}

int docDSSVTuFile (SinhVien sv[], char* filePath)
{
    int n=0;
    FILE* f = fopen(filePath,"rb");

    while (true)
    {
        if (fread(&sv[n++], sizeof(SinhVien), 1, f)<=0)
            break;
    }

    fclose(f);
    return n-1;
}

//return chỉ số sinh viên có mã SV tương ứng, nếu không có trả về -1
int timSinhVienTheoMaSV(SinhVien sv[], int n, char maSVCanTim[])
{
    for (int i=0; i<n; i++)
    {
        if (strcmp(sv[i].maSV,maSVCanTim)==0)
        {
            return i;
        }
    }
    return -1;
}

void suaThongTinSinhVien (SinhVien sv[], int n, char* maSVCanTim, char* filePath)
{
    n = docDSSVTuFile(sv,filePath);
    int index = timSinhVienTheoMaSV(sv,n,maSVCanTim);
    if (index < 0)
    {
        printf("\tKhong tim thay sinh vien co ma SV la %s\n",maSVCanTim);
    }
    else
    {
        printf("\tNhap lai thong tin sinh vien\n");
        sv[index] = nhapThongTinSinhVien();
        luuThongTinDSSVLenFile(sv,n,filePath);
    }
}

void menu()
{
    printf("\t\tMENU\n");
    printf("\t1. Tao danh sach\n");
    printf("\t2. Hien thi danh sach\n");
    printf("\t3. Sua thong tin sinh vien\n");
    printf("\t4. Ket thuc\n");
    printf("\t\tVui long chon: ");
}

int main()
{
    SinhVien dssv[MAX];
    int n = 0;

    while (true)
    {
        menu();
        int chon;
        scanf("%d",&chon);

        switch (chon)
        {
            case 1:
            {
                printf("\tNhap so luong sinh vien: ");
                n = taoDanhSachSinhVien(dssv);
                luuThongTinDSSVLenFile(dssv,n,(char*)"DS_SV.C");
                break;
            }

            case 2:
            {
                n = docDSSVTuFile(dssv,(char*)"DS_SV.C");
                hienThiDanhSachSinhVien(dssv,n);
                break;
            }

            case 3:
            {
                printf("\tNhap ma sinh vien can sua thong tin: ");
                char maSVCanSua[10];
                fflush(stdin);
                gets(maSVCanSua);
                suaThongTinSinhVien(dssv,n,maSVCanSua,(char*)"DS_SV.C");
                break;
            }

            case 4:
            {
                printf("BYE\n");
                return 0;
            }

            default:
                printf("\tChi nhap tu 1 den 4\n");
        }
    }
}
