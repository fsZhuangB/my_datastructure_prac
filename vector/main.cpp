#include "Vector.hpp"

int main()
{
    int * my_array;
    my_array = new int[10];
    for (int i = 0; i < 10; i++)
        my_array[i] = i;

    Vector<int> my_vector(my_array, 10);

    return 0;
}