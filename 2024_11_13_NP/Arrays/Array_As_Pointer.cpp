#include <iostream>
using namespace std;
int main()
{
    // Initialize the array length
    int arrLength = 5;
    int i = 0;
    // Initialize a pointer
    // to hold an array
    int *ptr = new int[arrLength]{21, 47, 87, 35, 92};

    // Display each element value
    // by incrementing the pointer (ptr++)
    cout << "\nUsing pointer increment" << endl;
    cout << "Value\tAddress" << endl;

    // antes estava *ptr no while
    // mas dava problemas de memoria
    // while(*ptr != NULL)
    while (i < arrLength)
    {
        cout << *ptr << "\t";
        cout << ptr << endl;

        ptr++;
        i++;
    }

    // Since we have moved forward the pointer five times
    // we need to move it back
    ptr = ptr - 5;

    // Display each element value
    // by accessing pointer index (ptr[])
    cout << "\nUsing pointer index" << endl;
    cout << "Value\tAddress" << endl;
    for (int i = 0; i < arrLength; ++i)
    {
        cout << ptr[i] << "\t";
        cout << &ptr[i] << endl;
    }

    return 0;
}