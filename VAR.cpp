#include <iostream>

using namespace std;

int main()
{
    int  var1;
    char var2[10];
    int* ip;    /* 一个整型的指针 */
    double* dp;    /* 一个 double 型的指针 */
    float* fp;    /* 一个浮点型的指针 */
    char* ch;    /* 一个字符型的指针 */
    ip = &var1; /* var1的地址传递给ip */

    cout << "var1 id： ";
    cout << &var1 << endl;

    cout << "var2 id： ";
    cout << &var2 << endl;
    cout << "var3 id： ";
    cout << &ip << endl;
    cout << "var4 id： ";
    cout << ip << endl;
    cout << "var5 id： ";
    cout << *ip << endl;

    return 0;
}