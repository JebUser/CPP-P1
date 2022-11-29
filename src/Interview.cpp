//
// Created by JUAN ESTEBAN BECERRA on 27/09/2022.
//

#include "Interview.h"

Interview::Interview() {
    this->candidateV = nullptr;
    this->id = 0;
    this->hour = 0;
}

Interview::Interview(Candidate *candidateV, double id, int hour) {
    this->candidateV = candidateV;
    this->id = id;
    this->hour = hour;
}

Interview::~Interview() {

}

void Interview::setCandidate(Candidate *newCandidate) {
    candidateV = newCandidate;
}

void Interview::setHour(int hourIn) {
    hour = hourIn;
}

void Interview::setId(double idIn) {
    id = idIn;
}

Candidate *Interview::getCandidate() const {
    return candidateV;
}
int Interview::getHour() const{
    return hour;
}

double Interview::getId() const {
    return id;
}

//Metodo encargado de generar la guia para el entrevistador.
void Interview::createInterviewGuide(tm *day) {
    string text("CANDIDATE'S GUIDE: \n\nCandidate " + candidateV->getName() + 
    ". Nationality: " + candidateV->getNationality()->getName() + ". Interview Date: " + to_string(day->tm_mday) + "/" + to_string(day->tm_mon) + "/" + to_string(day->tm_year) + " at " + to_string(hour) + "am.\n" + 
    "Has a type of culture (1: Expressive Culture, 0: Reserved Culture): " + to_string(candidateV->getNationality()->getType()) + ".\n" + 
    "Maintains an eye-contact " + candidateV->getNationality()->getEyeCStyle() + 
    "Use some gestures like: " + candidateV->getNationality()->getGestures() + ".\n" + 
    "Reacts to physical contact " + candidateV->getNationality()->getTouch() + ".\n" + 
    "Has problems with the physical space? (1: Yes, 0: No): " + to_string(candidateV->getNationality()->getPhysicalSpace()) + ".\n" + 
    "Time management " + candidateV->getNationality()->getTimeManage() + ".\n" + 
    "Has a communication style " + candidateV->getNationality()->getComStyle() + ".\n" + 
    "About Siestas Traditions: " + candidateV->getNationality()->getSiestasTrad() + ".\n Holidays:\n");

    //Convertimos a string todas las fechas de los festivos.
    for (int i = 0; i < candidateV->getNationality()->getHolidays().size(); i++) {
        text += to_string(candidateV->getNationality()->getHolidays()[i].tm_mday) + "/" + to_string(candidateV->getNationality()->getHolidays()[i].tm_mon) + "\n";
    }

    fstream outfile;

    string filename(candidateV->getPassport() + ".txt"); //Generamos el nombre del nuevo archivo como el codigo de pasaporte del candidato (recordemos que es un codigo unico).
    FILE *newFile = fopen(filename.c_str(), "w+"); //Creamos o abrimos el archivo correspondiente.
    //Verificar si se abrio o creo correctamente.
    if (newFile) {
        fwrite(text.c_str(), 1, text.size(), newFile); //Agregar el texto al archivo.
        cout << "The new file has generated correctly!" << endl;
    }
    fclose(newFile); //IMPORTANTE siempre cerrar un archivo una vez que hayas terminado de trabajar en el.
}