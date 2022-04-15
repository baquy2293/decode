#include <stdio.h>
#include <stdlib.h>

int main()
{
    float  tien,lai;
    int dem=0;
    printf("nhap so tien ban gui\n");
    scanf("%f",&tien);
    printf("nhap so % ban muon tinh\n");
    scanf("%f",&lai);
    float tmp = tien;
    while(1)
    {
        printf("%.2f\n",tien);
        if(tien>=2*tmp)
        {
            break;
        }

        dem++;
        tien=tien+tien*lai/100;
    }
    printf("%d",dem);



}
