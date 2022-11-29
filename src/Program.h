//
// Created by JUAN ESTEBAN BECERRA on 27/09/2022.
//

#ifndef PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_PROGRAM_H
#define PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_PROGRAM_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include "string.h"
#include "Candidate.h"
#include "Interview.h"
#include <ctime>

using namespace std;


class Program{
private:
    unordered_map<string, Country*> countries;
    unordered_map<string, Candidate*> candidates;
    unordered_map<tm*, vector<Interview*>> interviewPerDay;
    tm* day;
    double idInterview;
public:
    //Constructor/destructor

    Program();

    ~Program();

    //metodos
    void addCandidate(string name, string email, string linkedIn, string github, string passport, Country* nationality);
    void addCountry(Candidate *candidate, bool opc, string name, bool type, string eyeCStyle, string gestures, string touch, bool pyshicalSpace, string timeManage, string comStyle, string siestasTrad, vector<tm> holidays);
    void addInterview(Candidate *candidate);
    void changeDay(); //Método que cambiará las fechas dependiendo de las circunstancias.
    Interview *existInterview(double ID);
    void showInfoCon();
    void showInfoCan();

    /*
    Estos dos metodos SOLO se van a usar en los casos de prueba.
    */
    bool existCountry(string country);
    bool existCandidate(string name);

    void createInterviewGuide();
    void createWelcomeLetter();

    unordered_map<string, Country*> getCountries() const;
    unordered_map<string, Candidate*> getCandidates() const;


};

#endif