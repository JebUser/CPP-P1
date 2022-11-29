//
// Created by JUAN ESTEBAN BECERRA on 27/09/2022.
//

#ifndef PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_COUNTRY_H
#define PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_COUNTRY_H
#include <iostream>
#include <ctime>
#include <vector>
#include "string"

using namespace std;
using std::endl;

class Country {
private:
    string name;
    bool type;
    string eyeCStyle;
    string gestures;
    string touch;
    bool physicalSpace;
    string timeManage;
    string comStyle;
    string siestasTrad;
    vector<tm> holidays;

public:
    //Constructor/destructor
    Country();
    Country(string name, bool type, string eyeCStyle, string gestures, string touch, bool pyshicalSpace, string timeManage, string comStyle, string siestasTrad, vector<tm> holidays);

    ~Country();

    //Metodos setters de la clase country
    void setName(string & name);
    void setType(bool type);
    void setEyeCStyle(string & eyeCstyle);
    void setGestures(string & gestures);
    void setTouch(string & touchStyle);
    void setPhysicalSpace(bool pSpace);
    void setTimeManage(string & tManage);
    void setComStyle(string & cStyle);
    void setSiestasTrad(string & sTrad);
    void setHolidays(vector<tm> holidays);

    //Metodos getters de la clase country
    string getName() const;
    bool getType() const;
    string getEyeCStyle() const;
    string getGestures() const;
    string getTouch() const;
    bool getPhysicalSpace() const;
    string getTimeManage() const;
    string getComStyle() const;
    string getSiestasTrad() const;
    vector<tm> getHolidays();

    //Metodo adicional de la clase Country
    bool existHoliday(tm holiday);
    void returnInfo();
    void addHolidays(tm holiday);

};


#endif //PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_COUNTRY_H
