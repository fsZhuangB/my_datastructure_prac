#include "list.hpp"
#include <iostream>

using namespace std;
int main()
{
    List<int> myList;
    myList.BuildOneTwoThree();
    myList.Iterator();
    int length = myList.size();
    cout << length << endl;

    return 0;
}