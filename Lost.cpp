#include <iostream>
#include <string>
#include <fstream>

#include "Item.cpp"

using namespace std;

class Lost_database:public Item
{
    public:
    Lost_database(int ID,string name,string description,int year,int month,int day,string location,int contuct_number):
    Item(ID,name,description,year,month,day,location,contuct_number){}

    ofstream L_database;
    

    void data_input(){
        L_database.open("lost_database.csv");
        L_database<<ID<<",";
    }
    
};

