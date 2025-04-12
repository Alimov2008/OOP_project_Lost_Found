#include <iostream>
#include <string>
#include <fstream>

#include "Item.cpp"

using namespace std;

void Lost_database(int _ID,string _name,string _description,int _year,int _month,int _day,string _location,int _contuct_number)
{   
    ofstream Lost_data;
    Lost_data.open("lost_database.csv");
    Lost_data<<_ID<<","<<_name<<","<<_description<<","<<_year<<","<<_month<<","<<_day<<","<<_location<<","<<_contuct_number<<endl;
}