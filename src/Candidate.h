//
// Created by JUAN ESTEBAN BECERRA on 27/09/2022.
//

#ifndef PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_CANDIDATE_H
#define PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_CANDIDATE_H
#include <iostream>
#include "string"
#include "Country.h"

using namespace std;
using std::endl;

class Candidate {
private:
    string name;
    string email;
    string linkedIn;
    string github;
    string passport;
    Country* nationality;
public:
    //Constructor/destructor

    Candidate();
    Candidate(string name, string email, string linkedIn, string github, string passport, Country *nationality);
    ~Candidate();

    //metodos setters
    void setName(string nameIN);
    void setEmail(string emailIN);
    void setLinkedIn(string linkedInIN);
    void setGithub(string githubIN);
    void setPassport(string passportIN);
    void setNationality(Country* nationalityIN);

    //metodos getters
    string getName() const;
    string getEmail() const;
    string getLinkedIn() const;
    string getGithub() const;
    string getPassport() const;
    Country* getNationality() const;

    //metodos adicionales
    void showInfoCan();

};


#endif //PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_CANDIDATE_H
