#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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
            
    //     }

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
            
    //     }

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
        }


    void Display(){
        cout<<"\nID: "<<ID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Description: "<<description<<endl;
        // cout<<"Time: "<<day<<"/"<<month<<"/"<<year<<endl;
        cout<<"Location: "<<location<<endl;
        cout<<"Contuct number: "<<contuct_number<<endl;
    }
    
    ofstream lost_db;
    void Lost_database_info_saving(){
        lost_db.open("lost_database.csv",ios::app);
        lost_db<<ID<<","<<name<<","<<description<<","<<year<<","<<month<<","<<day<<","<<location<<","<<contuct_number<<endl;
        lost_db.close();
    }

};

