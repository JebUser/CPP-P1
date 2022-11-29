//
// Created by JUAN ESTEBAN BECERRA on 27/09/2022.
//
#include "Program.h"

//El metodo recibe candidate en el caso de que se quiera crear una nacionalidad personalizada. Si no se requiere, simplemente que reciba un nullptr. El opc es para seleccionar hacer un pais por defecto o uno personalizado.
void addCountry(Candidate *candidate, Program *proyect, int opc) {
    string name;
    bool type;
    string eyeCStyle;
    string gestures;
    string touch;
    bool pyshicalSpace;
    string timeManage;
    string comStyl;
    string siestasTrad;
    vector<tm> holidays;

    cout<<"Type the name of the country: ";
    cin.ignore();
    getline(cin, name);
    cout<<"Has an expressive culture? (1: Yes 0: No): ";
    cin>>type;
    cout<<"Maintains an eye-contact: ";
    cin.ignore();
    getline(cin, eyeCStyle);
    cout<<"Use some gestures like: ";
    getline(cin, gestures);
    cout<<"Reacts to pyshical contact: ";
    getline(cin, touch);
    cout<<"Has problems with the pyshical space? (1: Yes 0: No): ";
    cin>>pyshicalSpace;
    cout<<"How manage the time?: ";
    cin.ignore();
    getline(cin, timeManage);
    cout<<"Has a communication style: ";
    getline(cin, comStyl);
    cout<<"About siesta traditions: ";
    getline(cin, siestasTrad);

    int tam;
    cout<<"How many holidays does the country have?: ";
    cin>>tam;
    tm eachHoliday;
    for (int i = 0; i < tam; i++) {
        cout<<"Type the day:";
        cin>>eachHoliday.tm_mday;
        cout<<"Type the month:";
        cin>>eachHoliday.tm_mon;
        holidays.push_back(eachHoliday);
    }

    proyect->addCountry(candidate, opc, name, type, eyeCStyle, gestures, touch, pyshicalSpace, timeManage, comStyl, siestasTrad, holidays);
}

void addCandidate(Program *proyect){
    string name, email, linkedIn, github, passport, counName;
    Country *canCountry;
    cout << "Type the candidate's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Type the candidate's email: ";
    getline(cin, email);
    cout << "Type the candidate's linkedIn: ";
    getline(cin, linkedIn);
    cout << "Type the candidate's github: ";
    getline(cin, github);
    cout << "Type the candidate's passport: ";
    getline(cin, passport);
    proyect->showInfoCon(); //Mostramos los paises disponibles por defecto.

    //Consultamos si quiere asignar una nacionalidad por defecto o crear una presonalizada para el candidato.
    bool opc;
    cout<<"Wants to asign a default nationality or create a personalized one?"<<endl;
    cout<<"[1] Default Nationality."<<endl;
    cout<<"[0] Personalized Nationality"<<endl;
    cout<<"SELECT: ";
    cin>>opc;
    if (opc) {
        cout << "Select the candidate's country: ";
        cin.ignore();
        getline(cin, counName);
        //Primero hay que rectificar si el pais por defecto seleccionado se encuentra registrado en el mapa no ordenado.
        if (proyect->getCountries().find(counName) != proyect->getCountries().end()) {
            proyect->addCandidate(name,email,linkedIn,github,passport,  proyect->getCountries()[counName]);
        }
        else {
            cout<<"The selected country is not available\a"<<endl;
        }
    }
    else {
        proyect->addCandidate(name, email, linkedIn, github, passport, nullptr); //Creamos el nuevo candidato sin la nacionalidad establecida, ya que mas adelante se la asignaremos.
        addCountry(proyect->getCandidates()[passport], proyect, 0);

    }
}

void addInterview(Program *proyect){
    string passport;
    proyect->showInfoCan();
    cout << "Type the candidate's passport: ";
    cin.ignore();
    getline(cin, passport);
    //Primero revisamos si el candidato ya esta registrado.
    if (proyect->getCandidates().find(passport) != proyect->getCandidates().end()) {
        proyect->addInterview(proyect->getCandidates()[passport]);
    }
    else {
        cout<<"The candidate doesn't exist, creating a new one...\a"<<endl;
        addCandidate(proyect);
    }
}

void menu(Program *proyect){
    int sel;
    do{
        cout << "WELCOME TO PARKINGSOFT:\n" << endl;
        cout<<"[1] Manage available countries."<<endl;
        cout<<"[2] Add a candidate to the system."<<endl;
        cout<<"[3] Create a new interview."<<endl;
        cout<<"[4] Generate interview guide."<<endl;
        cout<<"[5] Generate a welcome letter."<<endl;
        cout<<"[-1] Exit."<<endl;
        cout << "SELECT: ";
        cin >> sel;
        switch (sel) {
            case 1:
                proyect->showInfoCon();
                break;
            case 2:
                addCandidate(proyect);
                break;
            case 3:
                addInterview(proyect);
                break;
            case 4:
                proyect->createInterviewGuide();
                break;
            case 5:
                proyect->createWelcomeLetter();
                break;
            case -1:
                cout << "Closing the program." << endl;
            default:
                cout << "Command not valid\a" << endl;
                break;
        }
    } while (sel != -1);
};

int main(){
    auto *proyect = new Program();
    menu(proyect);
    return 0;
}