//
// Created by JUAN ESTEBAN BECERRA on 27/09/2022.
//

#include "Candidate.h"
Candidate::Candidate() {
    name = "";
    email = "";
    linkedIn = "";
    github = "";
    passport = "";
    nationality = nullptr;

}
Candidate::~Candidate() {}

Candidate::Candidate(string name, string email, string linkedIn, string github, string passport, Country *nationality) {
    this->name = name;
    this->email = email;
    this->linkedIn = linkedIn;
    this->github = github;
    this->passport = passport;
    this->nationality = nationality;
}
void Candidate::setName(string nameIN) {
    name = nameIN;
}
void Candidate::setEmail(string emailIN) {
    email = emailIN;
}
void Candidate::setLinkedIn(string linkedInIN) {
    linkedIn = linkedInIN;
}
void Candidate::setGithub(string githubIN) {
    github = githubIN;
}
void Candidate::setPassport(string passportIN) {
    passport = passportIN;
}
void Candidate::setNationality(Country* nationalityIN) {
    nationality = nationalityIN;
}

string Candidate::getName() const {
    return name;
}
string Candidate::getEmail() const {
    return email;
}
string Candidate::getLinkedIn() const {
    return linkedIn;
}
string Candidate::getGithub() const {
    return github;
}
string Candidate::getPassport() const {
    return passport;
}
Country* Candidate::getNationality() const {
    return nationality;
}

void Candidate::showInfoCan() {
    cout << "Passport ID: " << passport << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "LinkedIn: " << linkedIn << endl;
    cout << "Github: " << github << endl;
    nationality->returnInfo();
}
