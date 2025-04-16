#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>


#include "myfunshare.h"

using namespace std;

class Item
{
protected:
    int ID;
    string name;
    string description;
      //time
      int year;
      int month;
      int day;
    string location;
    long int contuct_number;
    // bool W=true;
public:
    Item(){
        ID=0;
        name="Unknown item";
        description="Unknown item";
            //time
            year=0;
            month=0;
            day=0;
        location="Unknown";
        contuct_number=0;
    }

    Item(int _ID,string _name,string _description,int _year,int _month,int _day,string _location,int _contuct_number)
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
    
    void setData(int __ID,string __name,string __description,int __year,int __month,int __day,string __location,int __contuct_number)
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

    // void setID(int __id){
    //     ID=__id;
    // }
    
    // void setName(string __name){
    //     name=__name;
    // }

    // void setDescription(string __description){
    //     description=__description;
    // }
    //Time
    //     void setYear(int __year){
    //         if (__year>0){
    //             year=__year;
    //         }
    //         else{
    //             cout<<"JESUS";
    //         }
            
    //     void setMonth(int __month){
    //         if (__month>0 && __month<12){
    //             month=__month;
    //         }
    //         else{
    //             cout<<"month cannot be more than 12 or less than 1";
    //         }
    //     }

    //     void setDay(int __day){
    //         if (__day>0 && __day<31){
    //             day=__day;
    //         }
    //         else{
    //             cout<<"there are no less than 1 and no more than 31 days in a  month";
    //         }
            
    // void setLocation(string __location){
    //     location=__location;
    // }

    // void setContuct_number(long int __con_number){
    //     contuct_number=__con_number;
    // }

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

//Info insertion 
    ofstream lost_db;
    void Lost_database_info_saving(){
        lost_db.open("lost_database.csv",ios::app);
        lost_db<<ID<<","
        <<"\""<<removeCommas(name)<<"\""<< ","
        <<"\""<<removeCommas(description)<< "\""<<","
        <<year<<","
        <<month<<","
        <<day<<","
        <<"\""<<removeCommas(location)<<"\""<<","
        <<contuct_number<<endl;
        lost_db.close();
    }

    ofstream found_db;
    void Found_database_info_saving(){
        found_db.open("found_database.csv",ios::app);
        found_db << ID << ","
        <<"\""<<removeCommas(name)<<"\""<<","
        <<"\""<<removeCommas(description)<<"\""<<","
        <<year<<","
        <<month<<","
        <<day<<","
        <<"\""<<removeCommas(location)<<"\""<<","
        <<contuct_number << endl;
        found_db.close();
    }

//Opposite database item identification
    void Lost_check_found_database(){
        bool already_does_exists=false;
        int Max_array_siza=1000;
        
        string found_names[Max_array_siza];

        ifstream found_checker("found_database.csv");
        string temp_line_found;
     
        int count_found=0;
        int count_lost=0;

  

        while (getline(found_checker, temp_line_found) && count_found < Max_array_siza) {
            stringstream ss(temp_line_found);
            string found_id, found_name;
    
            getline(ss, found_id, ',');
            getline(ss, found_name, ',');
    
            found_names[count_found++] = found_name;
        }
        
        found_checker.close();
        
    }

    void Found_check_lost_database(){}

//Database item deletion
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
    
    void delete_found_database_item(const string& targetID){
        ifstream inputFile("found_database.csv");
        ofstream tempFile("temp.csv");
        string temp_line;
        bool found=false;

        while (getline(inputFile,temp_line))
        {
            stringstream ss(temp_line);
            string temp_ID;
            getline(ss, temp_ID,',');
            if (temp_ID==targetID)
            {
                found=true;
            }
            else{
                tempFile<<temp_line<<"\n";
            }
            
        }

        inputFile.close();
        tempFile.close();

        remove("found_database.csv");
        rename("temp.csv","found_database.csv");

        if (found){
        cout<<"\n----Item with ID "<<targetID<<" has been deleted/claimed from database----"<<endl;
        }
        else{
        cout<<"No item with such ID exists in database";
        } 
        
    }

//Database item managment
    void Lost_database_list() {
        ifstream file("lost_database.csv");
        string line;
        int option;
        int Target_ID;
    
        if (!file.is_open()) {
            cout << "Could not open lost_database.csv\n";
            return;
        }
        
        cout<<left
            <<setw(8)<<"ID"
            <<setw(15)<<"Name"
            <<setw(25)<<"Description"
            <<setw(6)<<"Year"
            <<setw(8)<<"Month"
            <<setw(6)<<"Day"
            <<setw(15)<<"Location"
            <<setw(15)<<"Contact"<<endl;
        cout<<string(102, '-')<<endl;

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
    
            cout << left
                 << setw(8) << id
                 << setw(15) << name
                 << setw(25) << desc
                 << setw(6) << year
                 << setw(8) << month
                 << setw(6) << day
                 << setw(15) << location
                 << setw(15) << contact << endl;
        }
        
    
        file.close();

        cout << "Enter 1 to delete item" << endl;
        cout << "Enter 2 to exit" << endl;
        

        option = datatype_checker<int>("Enter option: ");
    
            if (option == 1) {
                Target_ID = datatype_checker<int>("Enter ID of item you want to delete/claim: ");
                delete_found_database_item(to_string(Target_ID));
                // break; 
            } else if (option == 2) {
                cout << "Exiting to main menu..." << endl;
                // break;
            } else {
                cout << "No such option, Please try again\n\n" << endl;
            }
    }

    void Found_database_list(){
        ifstream file("found_database.csv");
        string line;
        int option;
        int Target_ID;
    
        if (!file.is_open()) {
            cout << "Could not open found_database.csv\n";
            return;
        }
    
        cout << left
             << setw(8)  << "ID"
             << setw(15) << "Name"
             << setw(25) << "Description"
             << setw(6)  << "Year"
             << setw(8)  << "Month"
             << setw(6)  << "Day"
             << setw(15) << "Location"
             << setw(15) << "Contact" << endl;
        cout << string(102, '-') << endl;

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
    
            cout << left
                 << setw(8) << id
                 << setw(15) << name
                 << setw(25) << desc
                 << setw(6) << year
                 << setw(8) << month
                 << setw(6) << day
                 << setw(15) << location
                 << setw(15) << contact << endl;
        }

            cout<<"Enter 1 to delete item" << endl;
            cout<<"Enter 2 to claim item"<<endl;
            cout<<"Enter 3 to exit" << endl;
            
            option = datatype_checker<int>("Enter option: ");
    
            if (option == 1||option==2) {
                Target_ID = datatype_checker<int>("Enter ID of item you want to delete/claim: ");
                delete_found_database_item(to_string(Target_ID));
                // break; 
            } else if (option == 3) {
                cout << "Exiting to main menu..." << endl;
                // break;
            } else {
                cout << "No such option, Please try again\n\n" << endl;
            }
    }


};