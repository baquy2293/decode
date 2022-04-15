#include <stdio.h>
#include <stdlib.h>

int nhapso()
{
    int n;
    do
    {
        scanf("%d",&n);
        if(n>0)
            break;
        printf("nhap so lon hon 0 \n");

    }
    while(n<=0);
    return n;
}

void nhap(int a[][200],int n,int m)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j ++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void in(int a[][200],int n,int m)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j ++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void tich(int a[][200],int b[][200],int c[][200],int n,int m,int t)
{

    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < t ; j ++)
        {
            int tmp = 0;
            for(int k = 0 ; k < m ; k ++)
            {
                tmp+=a[i][k]*b[k][j];
            }
            c[i][j] = tmp;
        }
    }
}

void menu()
{
    printf("-----MENU------\n");
    printf("\t 1: nhap 2 ma tran\n");
    printf("\t 2: in 2 ma tran\n");
    printf("\t 3: tinh tich 2 ma tran\n");
    printf("\t 4: thoat\n");
    printf("\tvui long chon  ");
}
int main()
{
    int a[200][200],b[200][200],c[200][200];
    int n,m,t,flag = 0,flag2 =0;
labale:
    system("cls");
    int chon;

    menu();
    scanf("%d",&chon);
    switch(chon)
    {
    case 1:
    {
        printf("nhap han va cot ma tran 1\n");
        n = nhapso();
        m = nhapso();
        printf("ban da nhap xong");
        Sleep(500);
        printf("nhap cot cua ma tran 2 \n");
        t = nhapso();
        flag =1;
        goto labale;
    }
    case 2:
    {
        if(flag==0)
        {
            printf("nhap ma tran di\n");
            getch();
            goto labale;
        }
        else if(flag2 == 0)
        {
            printf("tinh tich truoc \n");
            getch();
            goto labale;
        }
        printf("ma tran 1\n");
        in(a,n,m);
        printf("ma tran 2\n");
        in(b,m,t);

        printf("ma tran tich\n");
        in(c,n,t);
        getch();
        goto labale;

    }
    case 3:
    {
        if(flag==0)
        {
            printf("nhap ma tran di\n");
            getch();
            goto labale;
        }
        flag2 =1;
        tich(a,b,c,n,m,t);
        getch();
        goto labale;
    }
    case 4:
    {
        return 0;
    }
    default :
    {
        printf("nhap sai nhap laij\n");
        getch();
        goto labale;
    }



    }



}
