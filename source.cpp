#include <iostream>
#include <string>
#include <sstream>
#include <random>


#include "Item.cpp"


using namespace std;

void info_getter(){

    int ID;
    string name;
    string description;
      //time
      int year;
      int month;
      int day;
    string location;
    long int contuct_number;

    cout<<"Input following information: "<<endl;

    cout<<"Item name: ";
    cin>>name;
    cout<<""<<endl;

    cout<<"Item description: ";
    cin.ignore();
    getline(cin, description);
    cout<<""<<endl;

    cout<<"--Date--"<<endl;
    cout<<"Year: ";
    cin>>year;
    cout<<""<<endl;
    cout<<"Month: ";
    cin>>month;
    cout<<""<<endl;
    cout<<"Day: ";
    cin>>day;
    cout<<""<<endl;

    cout<<"Location: ";
    cin.ignore();
    getline(cin, location);
    
    cout<<"\nContuct number: ";
    cin>>contuct_number;

    Item i1;
    i1.setID(1);
    i1.setName(name);
    i1.setDescription(description);
    i1.setYear(year);
    i1.setMonth(month);
    i1.setDay(day);
    i1.setLocation(location);
    i1.setContuct_number(contuct_number);
    
    
}

int main()
{   
    
    int option;

    cout<<"---Lost & Found---"<<endl;
    cout<<"___________________________"<<endl;
    cout<<"Report lost item (1)"<<endl;
    cout<<"Register found item (2)"<<endl;
    cout<<"Lost item list (3)"<<endl;
    cout<<"Found item list (4)"<<endl;
    cout<<"Exit (5)"<<endl;
    cout<<"___________________________"<<endl;
    cout<<"Choose option: ";
    cin>>option;
    
    switch (option)
    {
    case 1:
    cout<<"1"<<endl;
    info_getter();
        break;
    
    case 2:
    cout<<"2"<<endl;
        break;

    case 3:
    cout<<"3"<<endl;
        break;

    case 4:
        cout<<"4"<<endl;
        break;

    case 5:
        cout<<"5"<<endl;
        break;

    default:
        cout<<"Invalid user input, Please try again"<<endl;
        break;
    }

    return 0;
}
