#include <iostream>
void swap(int * pa, int * pb) 
{
    int t =(*pa);
    *pa = *pb;
    *pb = t;
    
}
int main() 
{
    int a = 82;
    int b = -72;
    int * pa = &a;
    int * pb = &b;
    swap(pa,pb);
    std:: cout << a << ' ' << b << std::endl;
    return 0;
}