#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int lamangtangdan(int a[],int n)
{
    for(int i = 0 ; i < n-1; i++)
    {
        for(int j = i +1; j<n; j++)
        {
            if(a[i]>a[j])
                return 0;
        }
    }
    return 1;
}

int nhapso()
{
    int n;
    do
    {
        scanf("%d",&n);
        if(n<=0)
            printf("nhap so lon hon 0\n");
    }
    while(n<=0);
    return n;
}

int  nhapmang(int a[])
{
    int n = nhapso();
    do
    {
        for(int i = 0 ; i < n ; i++)
            scanf("%d",&a[i]);
        if(lamangtangdan(a,n))
            break;
        else
        {
            printf("nhap lai mang tang dan\n");
        }

    }
    while(1);
    return n;
}

void swap(int a[],int b[],int c[],int n,int m)
{
    int i,j,k;
    for(i=0,k=0,j=0; i<n&&j<m;)
    {
          c[k++]=a[i]<b[j]?a[i++]:b[j++];
    }
        while(i<n)
        {
            c[k++]=a[i++];
        }
        while(j<m)
        {
            c[k++]=b[k++];
        }

}

void in(int a[],int n)
{
    for(int i = 0 ; i < n ; i++)
        printf("%4d",a[i]);

    printf("\n");
}

int main()
{
    int a[100],b[100],c[100];
    int n=nhapmang(a);
    int m = nhapmang(b);
    swap(a,b,c,n,m);
    in(c,m+n);

}
