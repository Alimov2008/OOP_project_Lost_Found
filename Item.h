#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>


#include "myfunshare.h"

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item
{
protected:
    int ID;
    string name;
    string description;
      //time
      int year;
      string month;
      int day;
    string location;
    long int contuct_number;
public:
    Item(){
        ID=0;
        name="Unknown";
        description="Unknown";
            //time
            year=0;
            month="Unknown";
            day=0;
        location="Unknown";
        contuct_number=0;
    }

    Item(int _ID,string _name,string _description,int _year,string _month,int _day,string _location,int _contuct_number)
    {   
        ID=_ID;
        name=_name;
        description=_description;
        year=_year;
        month=_month;
        day=_day;
        location=_location;
        contuct_number=_contuct_number;
    }
    
    void setData(int __ID,string __name,string __description,int __year,string __month,int __day,string __location,int __contuct_number)
    {   
        ID=__ID;
        name=__name;
        description=__description;
        year=__year;
        month=__month;
        day=__day;
        location=__location;
        contuct_number=__contuct_number;
    };

    bool operator=(const Item &it){
        this->ID=it.ID;
        this->name=it.name;
        this->description=it.description;
        this->year=it.year;
        this->month=it.month;
        this->day=it.day;
        this->location=it.location;
        this->contuct_number=it.contuct_number;
        return 0;
    }

    void Display(){
        cout<<"Info Provided: ";
        cout<<"\nID: "<<ID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Description: "<<description<<endl;
        cout<<"Time: "<<day<<"/"<<month<<"/"<<year<<endl;
        cout<<"Location: "<<location<<endl;
        cout<<"Contuct number: "<<contuct_number<<endl;
    }
    
    string removeCommas(const string& input) {
        string result;
        for (char ch : input) {
            if (ch != ',') {
                result += ch; 
            }
        }
        return result;
    }

};

#endif