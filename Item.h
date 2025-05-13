
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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
    int year;
    string month;
    int day;
    string location;
    long int contuct_number;
public:
    virtual ~Item() {}

    Item(){
        ID=0;
        name="Unknown";
        description="Unknown";
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

    void Find_Item(){
        string SearchName;
        cout<<"Enter the name of Item you want to find: ";
        getline(cin,SearchName);

        ifstream lost_db("lost_database.csv");
        ifstream found_db("found_database.csv");

        if (!lost_db.is_open()) {
            cerr<<"Error: Cannot open file "<<endl;
            return;
        }

        if (!found_db.is_open()) {
            cerr<<"Error: Cannot open file "<<endl;
            return;
        }

        bool found=false;
        string line;

        while (getline(lost_db,line))
        {
            stringstream ss(line);
            string id, name, description, year, month, day, location, contact;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, description, ',');
            getline(ss, year, ',');
            getline(ss, month, ',');
            getline(ss, day, ',');
            getline(ss, location, ',');
            getline(ss, contact);

            if (name.find(SearchName)!=string::npos)
            {
                found=true;
                cout<<"\n================= Lost Item =================" << endl;
                cout<<"ID:           "<<id << endl;
                cout<<"Name:         "<<name << endl;
                cout<<"Description:  "<<description << endl;
                cout<<"Lost date:    "<<year << "-" << month << "-" << day << endl;
                cout<<"Location:     "<<location << endl;
                cout<<"Contact Info: "<<contact << endl;
            }

        }

        while (getline(found_db,line))
        {
            stringstream ss(line);
            string id, name, description, year, month, day, location, contact;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, description, ',');
            getline(ss, year, ',');
            getline(ss, month, ',');
            getline(ss, day, ',');
            getline(ss, location, ',');
            getline(ss, contact);

            if (name.find(SearchName)!=string::npos)
            {
                found=true;
                cout<<"\n================= Found Item =================" << endl;
                cout<<"ID:           "<<id << endl;
                cout<<"Name:         "<<name << endl;
                cout<<"Description:  "<<description << endl;
                cout<<"Lost date:    "<<year << "-" << month << "-" << day << endl;
                cout<<"Location:     "<<location << endl;
                cout<<"Contact Info: "<<contact << endl;
            }

        }

        if (!found) {
            cout<<"No items found matching name: "<<SearchName<<endl;
        }

        lost_db.close();
        found_db.close();
    }

    void Find_Item_Fuzzy() {
        string SearchName;
        int threshold;

        cout << "Enter the name of Item you want to find: ";
        getline(cin, SearchName);

        cout << "Enter maximum tolerance for spelling errors (1-5, recommended 2): ";
        threshold = datatype_checker<int>("");
        if (threshold < 1) threshold = 1;
        if (threshold > 5) threshold = 5;

        ifstream lost_db("lost_database.csv");
        ifstream found_db("found_database.csv");

        if (!lost_db.is_open()) {
            cerr << "Error: Cannot open file lost_database.csv" << endl;
            return;
        }

        if (!found_db.is_open()) {
            cerr << "Error: Cannot open file found_database.csv" << endl;
            return;
        }

        bool found = false;
        int match_count = 0;

        struct SearchResult {
            string id;
            string name;
            string description;
            string year;
            string month;
            string day;
            string location;
            string contact;
            int distance;
            bool is_lost;
        };

        const int MAX_RESULTS = 100;
        SearchResult results[MAX_RESULTS];
        int result_count = 0;

        string line;
        while (getline(lost_db, line) && result_count < MAX_RESULTS) {
            stringstream ss(line);
            string id, name, description, year, month, day, location, contact;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, description, ',');
            getline(ss, year, ',');
            getline(ss, month, ',');
            getline(ss, day, ',');
            getline(ss, location, ',');
            getline(ss, contact);

            if (name.length() >= 2 && name[0] == '"' && name[name.length() - 1] == '"') {
                name = name.substr(1, name.length() - 2);
            }
            if (description.length() >= 2 && description[0] == '"' && description[description.length() - 1] == '"') {
                description = description.substr(1, description.length() - 2);
            }
            if (location.length() >= 2 && location[0] == '"' && location[location.length() - 1] == '"') {
                location = location.substr(1, location.length() - 2);
            }

            int distance = levenshtein_distance(to_lower(name), to_lower(SearchName));

            if (distance <= threshold) {
                found = true;
                match_count++;

                results[result_count].id = id;
                results[result_count].name = name;
                results[result_count].description = description;
                results[result_count].year = year;
                results[result_count].month = month;
                results[result_count].day = day;
                results[result_count].location = location;
                results[result_count].contact = contact;
                results[result_count].distance = distance;
                results[result_count].is_lost = true;

                result_count++;
            }
        }

        while (getline(found_db, line) && result_count < MAX_RESULTS) {
            stringstream ss(line);
            string id, name, description, year, month, day, location, contact;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, description, ',');
            getline(ss, year, ',');
            getline(ss, month, ',');
            getline(ss, day, ',');
            getline(ss, location, ',');
            getline(ss, contact);

            if (name.length() >= 2 && name[0] == '"' && name[name.length() - 1] == '"') {
                name = name.substr(1, name.length() - 2);
            }
            if (description.length() >= 2 && description[0] == '"' && description[description.length() - 1] == '"') {
                description = description.substr(1, description.length() - 2);
            }
            if (location.length() >= 2 && location[0] == '"' && location[location.length() - 1] == '"') {
                location = location.substr(1, location.length() - 2);
            }

            int distance = levenshtein_distance(to_lower(name), to_lower(SearchName));

            if (distance <= threshold) {
                found = true;
                match_count++;

                results[result_count].id = id;
                results[result_count].name = name;
                results[result_count].description = description;
                results[result_count].year = year;
                results[result_count].month = month;
                results[result_count].day = day;
                results[result_count].location = location;
                results[result_count].contact = contact;
                results[result_count].distance = distance;
                results[result_count].is_lost = false;

                result_count++;
            }
        }

        for (int i = 0; i < result_count - 1; i++) {
            for (int j = 0; j < result_count - i - 1; j++) {
                if (results[j].distance > results[j + 1].distance) {
                    SearchResult temp = results[j];
                    results[j] = results[j + 1];
                    results[j + 1] = temp;
                }
            }
        }

        if (found) {
            cout << "\n====== Search Results (" << result_count << " items found) ======" << endl;

            for (int i = 0; i < result_count; i++) {
                cout << "\n================= "
                     << (results[i].is_lost ? "Lost" : "Found")
                     << " Item #" << (i + 1) << " =================" << endl;
                cout << "ID:           " << results[i].id << endl;
                cout << "Name:         " << results[i].name << endl;
                cout << "Similarity:   " << (results[i].distance == 0 ? "Exact match" :
                                          "Similar (distance: " + to_string(results[i].distance) + ")") << endl;
                cout << "Description:  " << results[i].description << endl;
                cout << "Date:         " << results[i].year << "-" << results[i].month << "-" << results[i].day << endl;
                cout << "Location:     " << results[i].location << endl;
                cout << "Contact Info: " << results[i].contact << endl;
            }
        } else {
            cout << "No items found matching or similar to: \"" << SearchName << "\"" << endl;
            cout << "Try increasing the tolerance value or check your spelling." << endl;
        }

        lost_db.close();
        found_db.close();
    }
};

#endif