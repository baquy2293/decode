#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1
#define false 0
void nhapMang(int a[][100],int d,int c)
{
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<c; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
int timMax(int a[][100],int d,int c)
{
    int max=a[0][0];
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(max<a[i][j])
            {
                max=a[i][j];
            }
        }
    }
    return max;
}
int timMin(int a[][100],int d,int c)
{
    int min=a[0][0];
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(min>a[i][j])
            {
                min=a[i][j];
            }
        }
    }
    return min;
}
int laSNT (int n)
{
    if (n<2)
        return false;
    int i;
    for (i=2; i<n; i++)
        if (n%i==0)
            return false;
    return true;
}
int laSNT (int n)
{
    if (n<2)
        return 0;
    int i;
    for (i=2; i<=sqrt(n); i++)
        if (n%i==0)
            return 0;
    return 1;
}
int tongSNT(int a[][100],int d,int c)
{
    int sum=0;
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(laSNT(a[i][j])==true)
            {
                sum=sum+a[i][j];

            }
        }
    }
    return sum;
}
void inMang(int a[][100],int d,int c)
{
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int a[100][100];
    int d,c;
    scanf("%d%d",&d,&c);
    nhapMang(a,d,c);
    inMang(a,d,c);
    printf("SO Lon Nhat Trong Matrix La: %d\n",timMax(a,d,c));
    printf("SO Nho Nhat Trong Matrix La: %d\n",timMin(a,d,c));
    printf("Tong cac SNT Trong Matrix La: %d\n",tongSNT(a,d,c));

}
