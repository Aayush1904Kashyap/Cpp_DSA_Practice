//functions are set of code which performs somethings for you
//functons are used to modularise code
//functions are used to increase readability
//used to use same code multiple times
//types:void,return,parameterised,non parameterised



#include <iostream>
using namespace std;

void printName(string name){
    cout<<"hey "<<name;
}
int main() {
    string name;
    cin>>name;
    printName(name);
    return 0;
}
