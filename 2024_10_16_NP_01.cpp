#include <iostream>

using namespace std;

int main() {
   
    int numeros[5] = {10, 20, 30, 40, 50};
   
    int *ptr = numeros;
   
    cout << numeros[0] << endl;
   
    cout << *ptr << endl;
   
    ptr++;
    cout << *ptr << endl;
 
    ptr--;
    cout << *ptr << endl;
 
    cout << *(ptr + 2) << endl;
 
    return 0;
}