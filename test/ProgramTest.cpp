
#include "gtest/gtest.h"
#include "../src/Program.h"


TEST(ProgramTest, addCandidate){
    string name = "Julio";
    string email = "julio@gmail.com";
    string linkedIn = "Julio Mazo";
    string github = "Julio-Alejandro-Mazo";
    string passport = "12345A5S62";
    auto* nationality = new Country();

    Program myProgram;
    myProgram.addCandidate(name, email, linkedIn, github, passport, nationality);

    EXPECT_TRUE(myProgram.existCandidate(name));
}

TEST(ProgramTest,addCountry){
    Candidate* candidate = nullptr;
    vector<tm> holidays;
    time_t now = time(0);
    tm *day = localtime(&now);

    tm holiday = *day;
    holidays.push_back(holiday);
    string country = "Francia";
    bool opc = true;
    bool type = false;
    string eyeCStyle = "They don't usually make much eye contact";
    string gestures = "yes/no, Ok, good luck";
    string touch = "shaking hands, kissing, hugs, and other physical contact";
    bool pyshicalSpace = true;
    string timeManage = "They are organized and manage time very well.";
    string comStyle = "They do not usually speak very loudly and speak slowly";
    string siestasTrad = "marathons";

    Program myProgram;
    myProgram.addCountry(candidate, opc, country, type, eyeCStyle, gestures, touch, pyshicalSpace, timeManage, comStyle, siestasTrad, holidays);

    EXPECT_TRUE(myProgram.existCountry(country));
}

//Este test verifica que se haga una nacionalidad personalizada, revisando que no haya sido agregada al mapa no ordenado.
TEST(ProgramTest, addCountryPersonalized) {
    string name = "Julio";
    string email = "julio@gmail.com";
    string linkedIn = "Julio Mazo";
    string github = "Julio-Alejandro-Mazo";
    string passport = "12345A5S62";
    vector<tm> holidays;
    auto* candidate = new Candidate(name, email, linkedIn, github, passport, nullptr);
    time_t now = time(0);
    tm *day = localtime(&now);
    tm holiday = *day;
    holidays.push_back(holiday);
    string country = "Francia";
    bool opc = false;
    bool type = false;
    string eyeCStyle = "They don't usually make much eye contact";
    string gestures = "yes/no, Ok, good luck";
    string touch = "shaking hands, kissing, hugs, and other physical contact";
    bool pyshicalSpace = true;
    string timeManage = "They are organized and manage time very well.";
    string comStyle = "They do not usually speak very loudly and speak slowly";
    string siestasTrad = "marathons";

    Program myProgram;
    myProgram.addCountry(candidate, opc, country, type, eyeCStyle, gestures, touch, pyshicalSpace, timeManage, comStyle, siestasTrad, holidays);
    EXPECT_FALSE(myProgram.existCountry(country));
}

TEST(ProgramTest, addInterview){
    auto* candidate = new Candidate();
    double id=1;

    Program myProgram;
    myProgram.addInterview(candidate);

    EXPECT_TRUE(myProgram.existInterview(id));
}
