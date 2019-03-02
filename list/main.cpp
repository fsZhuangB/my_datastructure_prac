// the test file of singly list
#include "list.hpp"
#include <iostream>

using namespace std;
int main()
{
    List<int> myList;
    myList.BuildOneTwoThree();
    myList.Iterator();
    // int length = myList.size();
    // cout << length << endl;

    // int second = myList[1];
    // cout << second << endl;
     myList.remove(2);
     myList.Iterator();
    //myList.insert(3, 5);
    //myList.Iterator();
    //int pos = myList.find(5);
    //cout << pos << endl;
    return 0;
}