#include <iostream>
#include <cstring>

using namespace std;
struct type_name {
    int member_name1;
    char member_name2;
} object_names;
int main{
        type_name object_names1;
        type_name object_names2;
        cout << " member_name: " << object_names1.member_name1 << endl;
        cout << " member_name: " << object_names2.member_name2 << endl;


        return 0;
}