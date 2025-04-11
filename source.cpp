#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <random>


#include "Item.cpp"


using namespace std;

template <typename T>
T datatype_checker(const string& prompt){
    string line;
    T value; 
    while (true)
    {
        cout<<prompt;
        getline(cin,line);
        stringstream ss(line);

        if (ss>>value)
        {
            char leftover;
            if (ss>>leftover){cout<<"Invalid input, please enter only numbers\n";}
            else{return value;}     
        }
        else{cout<<"invalid input, pleare try again\n";}
    }
}


void info_getter(Item& _item){

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
    cin.ignore();
    getline(cin, name);
    cout<<""<<endl;

    cout<<"Item description: ";
    cin.ignore();
    getline(cin, description);
    cout<<""<<endl;

    cout<<"--Date--"<<endl;
    year=datatype_checker<int>("Year: ");
    month=datatype_checker<int>("Month: ");
    day=datatype_checker<int>("Day: ");

    cout<<"Location: ";
    cin.ignore();
    getline(cin, location);
    
    contuct_number=datatype_checker<long int>("Your Contuct: ");

    // Item i1;
    // i1.setID(1);
    // i1.setName(name);
    // i1.setDescription(description);
    // i1.setYear(year);
    // i1.setMonth(month);
    // i1.setDay(day);
    // i1.setLocation(location);
    // i1.setContuct_number(contuct_number);
    
    _item.setData(123,name,description,year,month,day,location,contuct_number);
    
}

int main()
{   
    Item i1;

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
    info_getter(i1);
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
