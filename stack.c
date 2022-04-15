#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

typedef struct
{
    int top;
    int data[MAX];
} TStack;

TStack stack;

//refresh stack
void taoStack ()
{
    stack.top = 0;
}

//Kiem tra xem stack rong hay khong
int isEmpty()
{
    return (stack.top == 0);
}

//Kiem tra stack day hay chua
int isFull ()
{
    return (stack.top == MAX);
}

//Them 1 phan tu vao stack
void push ( int x)
{
    if (!isFull())
    {
        stack.data[stack.top] = x;
        stack.top++;
    }
}

//Lay du lieu tren cung
int peak ()
{
    return stack.data[stack.top-1];
}

//Xoa du lieu tren cung va return gia tri ra ngoai
int pop ()
{
    if (!isEmpty())
    {
        stack.top--;
        return stack.data[stack.top];
    }
}

void outputStack ()
{
    int i;
    for (i=stack.top-1; i>=0; i--)
    {
        if(stack.data[i]>=10)
        {
            char tmp = (int)stack.data[i] - 10 +'A';
            printf("%c",tmp);
        }else
        {

            printf("%d",stack.data[i]);
        }

    }
}

void heCoSo_2 ( int n)
{
    while (n>0)
    {
        push(n%2);
        n/=2;
    }
}

void hecoso_8(int n)
{
    while(n>0)
    {
        push(n%8);
        n/=8;
    }
}

void hecoso_16(int n)
{
    while(n>0)
    {
        push(n%16);
        n/=16;
    }
}


int main()
{
    int n;
    int chon;
    taoStack();
    while (1)
    {
        printf("\t\tNhap n: ");
        scanf("%d",&n);
        if (n<=0)
            printf("\tVui long nhap so nguyen duong\n");
        else
            break;
    }
    heCoSo_2(n);
    printf("\t\t%d(10) = ",n);
    outputStack();
    printf("(2)\n");
stack.top=0;
       hecoso_8(n);
    printf("\t\t%d(10) = ",n);
    outputStack();
    printf("(8)\n");
stack.top=0;
       hecoso_16(n);
    printf("\t\t%d(10) = ",n);
    outputStack();
    printf("(16)\n");

    return 0;
}
