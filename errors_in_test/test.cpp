#include <iostream>
using namespace std;

class MyInt
{
public:
    MyInt(int* pdNum)
    {
        cout<<"in MyInt(int*)"<<endl;
        m_pdNum=pdNum;
    }
    int getMyInt() const
    {
        return *m_pdNum;
    }
    ~MyInt()
    {
        cout<<"in ~MyInt()"<<endl;
        if(m_pdNum)
        {
            delete m_pdNum;
        }
    }
private:
    int* m_pdNum;
};

void print(MyInt objMyInt)
{
    cout<<"in print_MyInt"<<endl;
    cout<<objMyInt.getMyInt()<<endl;
}


int main()
{
    int num = 114;
    MyInt myInt(&num);
    int* pdNum=new int(114);
    print(pdNum);               //意外的被隐式转换为MyInt对象
    int* pdNewNum=new int(514);
    *pdNum=1919810;
    cout << *pdNewNum << endl; // 应该输出514，结果为1919810
    delete pdNum; // 释放pdNum分配的内存
    delete pdNewNum; // 释放pdNewNum分配的内存

}