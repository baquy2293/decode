
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void docFile(int a[][100],int b[][100],int* d,int* c,char* tenfile)
{
   FILE* f=fopen(tenfile,"r");
   fscanf(f,"%d%d",d,c);
   char tmp1[30],tmp2[30];


   fgets(tmp1,30,f);
   for(int i=0;i<*d;i++)
   {
       for(int j=0;j<*c;j++)
       {
           fscanf(f,"%d",&a[i][j]);
       }
   }


   fgets(tmp2,30,f);
   for(int i=0;i<*d;i++)
   {
       for(int j=0;j<*c;j++)
       {
           fscanf(f,"%d",&b[i][j]);
       }
   }
   fclose(f);

}
void themVaoFile(int a[][100],int d,int c,char* tenfile)
{
    FILE* f=fopen(tenfile,"a");
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<c;j++)
        {
            fprintf(f,"%3d",a[i][j]);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}
void cong(int A[][100],int B[][100],int C[][100],int d,int c)
{
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<c;j++)
        {
           C[i][j]=A[i][j]+B[i][j];
        }

    }
}
void inMang(int a[][100],int d,int c)
{
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
}
void menu()
{
    printf("\t\t\tMENU\n");
    printf("\t1.DOC TEP MA TRAN\n");
    printf("\t2.GHI MA TRAN C BO SUNG VAO TEP\n");
    printf("\t3.KET THUC\n");
    printf("Vui Long chon: ");
}
int main()
{
    int A[100][100],B[100][100],C[100][100];
    int d,c;
    while(1==1)
    {
        menu();
        int chon;
        scanf("%d",&chon);
        system("cls");
        if(chon==1)
        {
            docFile(A,B,&d,&c,"MA_TRAN.X");
            printf("MA TRAN A\n");
            inMang(A,d,c);
            printf("MA TRAN B\n");
            inMang(B,d,c);

        }
        else if(chon==2)
        {
            docFile(A,B,&d,&c,"MA_TRAN.X");
            printf("MA TRAN A\n");
            inMang(A,d,c);
            printf("MA TRAN B\n");
            inMang(B,d,c);
            cong(A,B,C,d,c);
            inMang(C,d,c);
            themVaoFile(C,d,c,"MA_TRAN.X");
        }
        else if(chon==3)
        {
            printf("\t\tBYE\n");
            exit(0);
        }
        else
            printf("Vui Long Nhap 1-3\n");

    }
    printf("Bam Bat Ki Ve Menu\n");
    getch();
    system("cls");
}
