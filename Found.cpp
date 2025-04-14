#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits>

#include "myfunshare.h"
#include "Item.cpp"

using namespace std;

int main()
{
    int option;

    option=datatype_checker<int>("Enter your choice: ");

    cout<<option<<endl;

    return 0;
}
