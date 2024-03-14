#include <stdio.h>
struct sa
{
    int a[3];
};

void test0(struct sa str) { str.a[0] = 7; }
void test1(int *arr) { arr[1] = 8; }
void test2(int arr[3]) { arr[2] = 9; }

int main(void)
{
    struct sa mystr;
    for (int i = 0; i < 3; ++i)
        mystr.a[i] = i;
    test0(mystr);
    printf("hello : %d\n", mystr.a[0]); // prints 0
    test1(mystr.a);
    printf("hello : %d\n", mystr.a[1]); // prints 8
    test2(mystr.a);
    printf("hello : %d\n", mystr.a[2]); // prints 9
    return 0;
}