#include <iostream>
using namespace std;

int main(){
    int numeroA, numeroB;
    cout << "ingrese el numero A: ";
    cin >> numeroA;
    cout << "ingrese el numero B: ";
    cin >> numeroB;
    if (numeroA > numeroB){
        cout << numeroA << " es mayor que " << numeroB << endl;
    }
    else{
        cout << numeroB << " es mayor que " << numeroA << endl;
    }
    return 0;
}
