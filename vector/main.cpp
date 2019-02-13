#include "Vector.hpp"
#include <iostream>
int main()
{
    int * my_array;
    my_array = new int[10];
    for (int i = 0; i < 10; i++)
        my_array[i] = i;

    for (int i = 0; i < 10; i++)
        std::cout << my_array[i] << " ";
    std::cout << std::endl;

    Vector<int> my_vector(my_array, 10);
    my_vector.Iterator();
    int j = my_vector.find(2);
    std::cout << j;
    return 0;
}