#include <string>
#include <list>

#include "Service.h"

Service :: Service(string t, Date d, string f, string l) : type(t), date(d), employee(f), license(l){}


string Service :: getType(){
    return this->type;
}

string Service :: getEmployee(){
    return this->employee;
}

string Service :: getLicense(){
    return this->license;
}

Date Service::getDate(){
    return this->date;
}

bool Service::operator<(const Service &s) const{
    if(date.year==s.date.year){
        if(date.month==s.date.month){
            if(date.day==s.date.day){
                return date.hour<s.date.hour;
            }
            return date.day<s.date.day;
        }
        return date.month<s.date.month;
    }
    return date.year<s.date.year;
}
