#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "myfunshare.h"
#include "Item.h"

using namespace std;

#ifndef LOST_H
#define LOST_H

class Lost:public Item{
    public:
    using Item::Item;

    ofstream lost_db;
    void Lost_database_info_saving(){
        if(Lost_check_found_database(removeCommas(name))){
            cout<<"somebody has already found similar item"<<endl;
            cout<<"Checkout found database list"<<endl;
        }
        else{
        

        lost_db.open("lost_database.csv",ios::app);
        lost_db<<ID<<","
        <<"\""<<removeCommas(name)<<"\""<< ","
        <<"\""<<removeCommas(description)<< "\""<<","
        <<year<<","
        <<removeCommas(month)<<","
        <<day<<","
        <<"\""<<removeCommas(location)<<"\""<<","
        <<contuct_number<<endl;
        cout<<"-----Lost item info has been saved-----"<<endl;
        lost_db.close();}
    }

    bool Lost_check_found_database(const string& Item_name){
        ifstream file("found_database.csv");
        string line;
    
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name;
    
            getline(ss, id, ',');
            getline(ss, name, ',');
            
            if (!name.empty() && name.front() == '"' && name.back() == '"') {
                name = name.substr(1, name.length() - 2);
            }

            if (name == Item_name) {
                return true; 
            }
        }
        return 0;
    }

    void delete_lost_database_item(const string& targetID){
        ifstream inputFile("lost_database.csv");
        ofstream tempFile("temp.csv");
        string temp_line;
        bool found=false;

        while (getline(inputFile,temp_line))
        {
            stringstream ss(temp_line);
            string temp_ID;
            getline(ss, temp_ID,',');
            if (stoi(temp_ID)==stoi(targetID))
            {
                found=true;
            }
            else{
                tempFile<<temp_line<<"\n";
            }
            
        }

        inputFile.close();
        tempFile.close();

        remove("lost_database.csv");
        rename("temp.csv","lost_database.csv");

        if (found){
        cout<<"\n----Item with ID "<<targetID<<" has been deleted from database----"<<endl;
        }
        else{
        cout<<"No item with such ID exists in database";
        } 
        
    }

    void Lost_database_list() {
        ifstream file("lost_database.csv");
        string line;
        int option;
        int Target_ID;
    
        if (!file.good()) {
            cout << "Could not open lost_database.csv\n";
            return;
        }
        
        int count = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, desc, year, month, day, location, contact;
    
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, desc, ',');
            getline(ss, year, ',');
            getline(ss, month, ',');
            getline(ss, day, ',');
            getline(ss, location, ',');
            getline(ss, contact, ',');
    
            auto strip_quotes = [](string &s) {
                if (!s.empty() && s.front() == '"' && s.back() == '"') {
                    s = s.substr(1, s.size() - 2);
                }
            };
    
            strip_quotes(name);
            strip_quotes(desc);
            strip_quotes(location);
    
            cout << "\n================= Lost Item #" << ++count << " =================" << endl;
            cout << "ID:           " << id << endl;
            cout << "Name:         " << name << endl;
            cout << "Description:  " << desc << endl;
            cout << "Lost date:    " << year << "-" << month << "-" << day << endl;
            cout << "Location:     " << location << endl;
            cout << "Contact Info: " << contact << endl;
        }
    
        file.close();
        cout<<"_________________________________________________________"<<endl;
        cout << "Enter 1 to delete item" << endl;
        cout << "Enter 2 to exit" << endl;
        

        option = datatype_checker<int>("Enter option: ");
    
            if (option == 1) {
                Target_ID = datatype_checker<int>("Enter ID of item you want to delete/claim: ");
                delete_lost_database_item(to_string(Target_ID));
                // break; 
            } else if (option == 2) {
                cout << "Exiting to main menu..." << endl;
                // break;
            } else {
                cout << "No such option, Please try again\n\n" << endl;
            }
    }

};

#endif
