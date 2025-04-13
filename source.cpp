#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <random>

#include "myfunshare.h"
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
    srand(time(NULL));
    

    int ID;
    string name;
    string description;
      //time
      int year;
      int month;
      int day;
    string location;
    long int contuct_number;

    int temp_year;
    int temp_month;
    int temp_day;

    ID=(rand()%1000);
    cout<<"Input following information: "<<endl;

    cout<<"Item name: ";
    cin.ignore();
    getline(cin, name);
    cout<<""<<endl;

    cout<<"Item description: ";
    // cin.ignore();
    getline(cin, description);
    cout<<""<<endl;

    cout<<"--Date--"<<endl;
    
    while (true)
    {
        temp_year=datatype_checker<int>("Year: ");
        if (temp_year>0){
            year=temp_year;
            break;
        }
        else{
            cout<<"Year must be more than 0, try again\n";
        }
    }
    
    while (true)
    {
        temp_month=datatype_checker<int>("Month: ");
        if (temp_month>0 && temp_month<=12){
            month=temp_month;
            break;
        }
        else{
            cout<<"Month must be more than 0 and less than 12, try again\n";
        }
    }
    
    while (true)
    {
        temp_day=datatype_checker<int>("Day: ");
        if (temp_day>0 && temp_day<=31){
            day=temp_day;
            break;
        }
        else{
            cout<<"Day must be more than 0 and less than 31, try again";
        }
    }

    cout<<"Location: ";
    // cin.ignore();
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
    
    _item.setData(ID,name,description,year,month,day,location,contuct_number);
    
}

int main()
{   
    bool W=true;
    Item i1;
    int option;
    
   while(W){

        cout<<"\n---Lost & Found---"<<endl;
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
            cout<<"Choosed option: Report item loss"<<endl;
            info_getter(i1);
            // i1.Display();
            i1.Lost_database_info_saving();
            break;
        
        case 2:
        cout<<"2"<<endl;
            break;

        case 3:
            cout<<"3"<<endl;
            i1.Lost_database_list();
            break;

        case 4:
            cout<<"4"<<endl;
            break;

        case 5:
            cout<<"Exiting..."<<endl;
            W=false;
            break;

        default:
            cout<<"Invalid user input, Please try again"<<endl;
            
        }
    }

    return 0;
}
