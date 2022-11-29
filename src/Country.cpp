//
// Created by JUAN ESTEBAN BECERRA on 27/09/2022.
//

#include "Country.h"
#include <iostream>

Country::Country() {
    cout<<"Entre al constructor por defecto"<<endl;
    this->name = "";
    this->type = false;
    this->eyeCStyle = "";
    this->gestures = "";
    this->touch = "";
    this->physicalSpace = false;
    this->timeManage = "";
    this->comStyle = "";
    this->siestasTrad = "";
}

Country::~Country() {}

//Constructor con parametros establecidos por el usuario.
Country::Country(string name, bool type, string eyeCStyle, string gestures, string touch, bool pyshicalSpace, string timeManage, string comStyle, string siestasTrad, vector<tm> holidays) {
    this->name = name;
    this->type = type;
    this->eyeCStyle = eyeCStyle;
    this->gestures = gestures;
    this->touch = touch;
    this->physicalSpace = pyshicalSpace;
    this->timeManage = timeManage;
    this->comStyle = comStyle;
    this->siestasTrad = siestasTrad;
    this->holidays = holidays;
}

//Metodos setters de la clase country

void Country::setName(string & name) {
    this->name = name;
}

void Country::setType(bool type) {
    this->type = type;
}

void Country::setEyeCStyle(string & eyeCstyle){
    this->eyeCStyle= eyeCstyle;
}

void Country::setGestures(string & gestures) {
    this->gestures = gestures;
}

void Country::setTouch(string & touchStyle){
    this->touch = touchStyle;
}

void Country::setPhysicalSpace(bool pSpace){
    this->physicalSpace = pSpace;
}

void Country::setTimeManage(string & tManage){
    this->timeManage = tManage;
}

void Country::setComStyle(string & cStyle){
    this->comStyle = cStyle;
}

void Country::setSiestasTrad(string & sTrad) {
    this->siestasTrad = sTrad;
}

void Country::setHolidays(vector<tm> holidays) {
    this->holidays = holidays;
}

//Metodos getters de la clase country

string Country::getName() const {
    return name;
}

bool Country::getType() const {
    return type;
}

string Country::getEyeCStyle() const {
    return eyeCStyle;
}

string Country::getGestures() const {
    return gestures;
}

string Country::getTouch() const {
    return touch;
}

bool Country::getPhysicalSpace() const {
    return physicalSpace;
}

string Country::getTimeManage() const {
    return timeManage;
}

string Country::getComStyle() const {
    return comStyle;
}

string Country::getSiestasTrad() const {
    return siestasTrad;
}

vector<tm> Country::getHolidays() {
    return holidays;
}

//Metodo adicional de la clase Country

void Country::returnInfo(){
    string charType;
    string charPSpace;
    if(type){
        charType = "Yes";
    }
    else{
        charType = "No";
    }
    if(physicalSpace){
        charPSpace = "Yes";
    }
    else{
        charPSpace = "No";
    }
    cout<<"The name of the country is: "<<name<<endl;
    cout<<"Is the culture reserved or expressive? "<<charType<<endl;
    cout<<"The duration and intensity of eye contacts is: "<<eyeCStyle<<endl;
    cout<<"How expresive they are? " << gestures <<endl;
    cout<<"The expressive characteristics are: "<<touch<<endl;
    cout<<"They like being together? "<<charPSpace<<endl;
    cout<<"How to manage the time the people of the country?"<<timeManage<<endl;
    cout<<"How do people in this country communicate?"<<comStyle<<endl;
    cout<<"How are the siesta traditions of this country?"<<siestasTrad<<endl;
    cout<<"Holidays:"<<endl;
    for (int i = 0; i < holidays.size(); i++) {
        cout<<holidays[i].tm_mday<<"/"<<holidays[i].tm_mon<<endl;
    }
}

//Metodo que agrega de manera individual festivos de la ciudad. No tiene mucha ciencia la verdad.
void Country::addHolidays(tm holiday) {
    holidays.push_back(holiday);
}

bool Country::existHoliday(tm holiday){
    for (int i = 0; i < holidays.size(); i++) {
        if( holiday.tm_mon == holidays[i].tm_mon && holiday.tm_mday == holidays[i].tm_mday ){
            return true;
        }
    }
    return false;

}



