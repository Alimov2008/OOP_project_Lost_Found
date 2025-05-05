#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <random>
#include <fstream>

#include "myfunshare.h"
#include "Item.h"
#include "Lost.h"
#include "Found.h"

using namespace std;

string printMonthName(int monthNumber){
    switch (monthNumber) {
        case 1:
            // cout << "January" << endl;
            return "January";
            break;
        case 2:
            // cout << "February" << endl;
            return "February";
            break;
        case 3:
            // cout << "March" << endl;
            return "March";
            break;
        case 4:
            // cout << "April" << endl;
            return "April";
            break;
        case 5:
            // cout << "May" << endl;
            return "May";
            break;
        case 6:
            // cout << "June" << endl;
            return "June";
            break;
        case 7:
            // cout << "July" << endl;
            return "July";
            break;
        case 8:
            // cout << "August" << endl;
            return "August";
            break;
        case 9:
            // cout << "September" << endl;
            return "September";
            break;
        case 10:
            // cout << "October" << endl;
            return "October";
            break;
        case 11:
            // cout << "November" << endl;
            return "November";
            break;
        case 12:
            // cout << "December" << endl;
            return "December";
            break;
        default:
            cout << "Invalid month number. Please enter a number between 1 and 12." << endl;
    }
    return 0;
}

int monthDaynumber(int monthNumber){
    switch (monthNumber){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 28; 
        default:
            return -1;
    }
} 

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
            if (ss>>leftover){cout<<"Invalid input, enter only numbers\n";}
            else{return value;}     
        }
        else{cout<<"invalid input, try again\n";}
    }
}


void info_getter(Item& _item){
    srand(time(NULL));
    
    int ID;
    string name;
    string description;
      //time
      int year;
      string month;
      int day;
    string location;
    long int contuct_number;

    int temp_year;
    int temp_month;
    int temp_day;

    bool is_leap_year;
    int leap_add=0;

    ID=(rand()%1000);
    cout<<"----Input following information----"<<endl;
    cout<<endl;

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
            if (year%4==0)
            {
                is_leap_year=true;
            }
            break;
        }
        else{
            cout<<"Year must be more than 0, try again"<<endl;
        }
    }
    
    while (true)
    {
        temp_month=datatype_checker<int>("Month: ");
        if (temp_month>0 && temp_month<=12){
            month=printMonthName(temp_month);
            break;
        } 
        else{
            cout<<"Invalid month number, enter number between 1 and 12"<<endl;
        }
    }
    
    while (true)
    {
        temp_day=datatype_checker<int>("Day: ");
        if (is_leap_year && temp_month==2)
        {
            leap_add=1;
        }
        if (temp_day>0 && temp_day<=monthDaynumber(temp_month)+leap_add){
            day=temp_day;
            break;
        }
        else{
            cout<<"There is only "<<monthDaynumber(temp_month)+leap_add<<" in "<<month<<endl;
        }
    }

    cout<<"Location: ";
    getline(cin, location);
    
    contuct_number=datatype_checker<long int>("Your Contuct: ");

    _item.setData(ID,name,description,year,month,day,location,contuct_number);
}

int main()
{   
    bool W=true;
    Item i1;
    Lost l1;
    Found f1;
    int option;
    
   while(W){

        cout<<"\n__________________________________________________"<<endl;
        cout<<"\n--------Lost & Found--------"<<endl;
        cout<<"____________________________________________________"<<endl;
        cout<<"1. Report lost item"<<endl;
        cout<<"2. Register found item"<<endl;
        cout<<"3. Lost item list"<<endl;
        cout<<"4. Found item list"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"____________________________________________________"<<endl;
        cout<<"Choose option: ";

        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Choosen option: Report item loss"<<endl;
            info_getter(l1);
            // i1.Display();
            l1.Lost_database_info_saving();
            break;
        
        case 2:
            cout<<"Choosen option: Register found item"<<endl;
            info_getter(f1);
            // i1.Display();

            f1.Found_database_info_saving();
            break;

        case 3:
            cout<<"Choosen option: Lost item list"<<endl;
            l1.Lost_database_list();
            break;
        case 4:
            cout<<"Choosen option: Found item list"<<endl;
            f1.Found_database_list();
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
