#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

std::vector<char> tab(15, '.');

int main()
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j<3; j++)
        {
            std::cout<< '.';
        }
        std::cout<<' ' << std::endl;
    }
        
}