#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
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
        name="Unknown";
        description="Unknown";
      
        location="Unknown";
        contuct_number=0;
    }

    // Item(int _ID,string _name,string _description,long double _time,string _location,int _contuct_number)
    // {   
    //     ID=_ID;
    //     name=_name;
    //     description=_description;
    //     time=_time;
    //     location=_location;
    //     contuct_number=_contuct_number;
    // }

    void setID(int __id){
        ID=__id;
    }
    
    void setName(string __name){
        name=__name;
    }

    void setDescription(string __description){
        description=__description;
    }
    //Time
        void setYear(int __year){
            year=__year;
        }

        void setMonth(int __month){
            month=__month;
        }

        void setDay(int __day){
            day=__day;
        }

    void setLocation(string __location){
        location=__location;
    }

    void setContuct_number(long int __con_number){
        contuct_number=__con_number;
    }

    void Display(){
        cout<<"\nID: "<<ID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Description: "<<description<<endl;
        cout<<"Time: "<<day<<"/"<<month<<"/"<<year<<endl;
        cout<<"Location: "<<location<<endl;
        cout<<"Contuct number: "<<contuct_number<<endl;
    }
    
    
};


