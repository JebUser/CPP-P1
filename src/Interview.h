//
// Created by JUAN ESTEBAN BECERRA on 27/09/2022.
//

#ifndef PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_INTERVIEW_H
#define PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_INTERVIEW_H
#include <iostream>
#include <ctime>
#include <fstream>
#include "Candidate.h"

using namespace std;

class Interview {
private:
    Candidate* candidateV;
    double id;
    int hour;
public:
    //Constructor/destructor

    Interview();
    Interview(Candidate *candidateV, double id, int hour);
    ~Interview();

    //metodos setters
    void setCandidate(Candidate* newCandidate);
    void setId(double idIn);
    void setHour(int hourIn);

    //metodos getter
    Candidate* getCandidate() const;
    double getId() const;
    int getHour() const;

    //metodos adicionales
    void createInterviewGuide(tm *day);
};


#endif //PROYECTO_RECRUITMENT_PANDEBONOCONPANELA_INTERVIEW_H
