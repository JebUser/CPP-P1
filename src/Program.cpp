//
// Created by JUAN ESTEBAN BECERRA on 27/09/2022.
//

#include "Program.h"

Program::Program() {
    time_t now = time(0);
    day = localtime(&now);
    day->tm_hour = 10;
    idInterview = 0;
    vector <tm>ColHolidays;
    vector <tm>AndHolidays;
    vector <tm>MacHolidays;
    vector <tm>SerbHolidays;

    tm holiday = *day;//Variable que ayudara a crear los festivos.

    /*
        Se pondran solo unos cuantos festivos de cada pais por terminos de facilidad.
    */

   //Para Colombia:
   holiday.tm_mday = 21;
   holiday.tm_mon = 3;
   ColHolidays.push_back(holiday);

   holiday.tm_mday = 14;
   holiday.tm_mon = 4;
   ColHolidays.push_back(holiday);

   holiday.tm_mday = 15;
   holiday.tm_mon = 4;
   ColHolidays.push_back(holiday);

   //Para Andorra:
   holiday.tm_mday = 14;
   holiday.tm_mon = 3;
   AndHolidays.push_back(holiday);

   holiday.tm_mday = 1;
   holiday.tm_mon = 5;
   AndHolidays.push_back(holiday);

   holiday.tm_mday = 15;
   holiday.tm_mon = 8;
   AndHolidays.push_back(holiday);

   //Para Macedonia:
   holiday.tm_mday = 24;
   holiday.tm_mon = 10;
   MacHolidays.push_back(holiday);

   holiday.tm_mday = 30;
   holiday.tm_mon = 10;
   MacHolidays.push_back(holiday);

   holiday.tm_mday = 30;
   holiday.tm_mon = 11;
   MacHolidays.push_back(holiday);

   //Para Serbia:
   holiday.tm_mday = 13;
   holiday.tm_mon = 1;
   SerbHolidays.push_back(holiday);

   holiday.tm_mday = 9;
   holiday.tm_mon = 5;
   SerbHolidays.push_back(holiday);

   holiday.tm_mday = 11;
   holiday.tm_mon = 11;
   SerbHolidays.push_back(holiday);

    auto *Colombia = new Country("Colombia", true, "It is not usually intensive, although some maintain it when speaking","oe, ave maría, Mira ve , Parcero, Parche, Amañado", "They are expressive, they shake hands, hugs and kisses, in fact they are usually even trusting since they treat everyone like brothers.", false,"They are not organized, they leave everything for the last.","Some speak very confused and with slang from each town, their rhythm can vary and the tone is usually enough to understand it.","For every 4 hours of work, take 1 hour off (usually for lunch)",ColHolidays);
    auto *Andorra = new Country("Andorra", false, "It is usually long since they keep their eyes on every conversation","liloyo, rongano, pinta", "They are not usually very expressive and more reserved", true,"They are organized","Some are usually very communicative like youtubers, but the whole community is not.","For every 6 hours of work, take half an hour off.",AndHolidays);
    auto *Macedonia = new Country("Macedonia", true, "is usually short","Dobro sum, Kolku cini?, Na zdravje!", "They are usually very friendly and shake hands", true,"are more or less organized","speak slowly and softly","For every 4 hours of work, take 1 hour off (usually for lunch)",MacHolidays); //Los horarios de descanso son practicamente iguales que los de Colombia (por lo menos de lo que investigamos).
    auto *Serbia = new Country("Serbia", false, "It is not intensive, although it can vary in a conversation","Kako se zoves?, vidimo se kasnije, Mozete li da mi pomognete?", "They usually shake hands but are very reserved with physical contact.", true,"are often respected for their traditions","they speak slowly and with much respect","For every 4 hours of work, take 15 minutes. Has an additional 15 minute break for every additional 2 hours of work.",SerbHolidays);

    countries["Colombia"] = Colombia;
    countries["Andorra"] = Andorra;
    countries["Macedonia"] = Macedonia;
    countries["Serbia"] = Serbia;
}

Program::~Program() {
    for (const auto& pToCountry: countries) {
        delete pToCountry.second;
    }
    for (const auto& pToCandidate: candidates) {
        delete pToCandidate.second->getNationality();
        delete pToCandidate.second;
    }
    for (const auto& pToInterviews: interviewPerDay) {
        for (auto & i : pToInterviews.second) {
            delete i;
        }
    }

    cout << "Se ha borrado todo correctamente. \a" << endl;
}

//Metodo para agregar un nuevo candidato al mapa de candidatos.
void Program::addCandidate(string name, string email, string linkedIn, string github, string passport, Country* nationality) {
    auto* newCandidate = new Candidate(name, email, linkedIn, github, passport, nationality); //Se crea el nuevo objeto con los atributos.
    candidates[passport] = newCandidate; //Se agrega al mapa NO ordenado con la llave como su pasaporte.
}

//Metodo para agregar nuevas nacionalidades dependiendo de la seleccion opc. Esto permitira entender la cultura unica de cada candidato y agregar nuevas nacionalidades a futuro. 1: Se agregara una nueva nacionalidad por defecto, 0: Sera una nacionalidad personalizada para un candidato en particular.
void Program::addCountry(Candidate *candidate, bool opc, string name, bool type, string eyeCStyle, string gestures, string touch, bool pyshicalSpace, string timeManage, string comStyle, string siestasTrad, vector<tm> holidays) {
    auto *newCountry = new Country(name, type, eyeCStyle, gestures, touch, pyshicalSpace, timeManage, comStyle, siestasTrad, holidays);
    /*
    1: Se agregara una nueva nacionalidad por defecto.
    0: Sera una nacionalidad personalizada para un candidato en particular.
    */
    if (opc) {
        countries[name] = newCountry;
    }
    else {
        candidate->setNationality(newCountry);
    }
}

//Metodo encargado de gestionar el cambio de horas y dias para dar disponibilidad de las entrevistas.
void Program::changeDay() {
    //Si hay espacio el mismo dia.
    if (day->tm_hour <= 14) {
        day->tm_hour += 1;
    }
    //Si a la hora de cambiar el dia se llega al final de los meses que tienen 30 dias.
    else if (day->tm_mday == 30 && day->tm_mon % 2 != 0) {
        day->tm_mon += 1;
        day->tm_mday = 1;
        day->tm_hour = 10;
    }
    //Si a la hora de cambiar el dia se llega al final de los meses que tienen 31 dias.
    else if (day->tm_mday == 30 && day->tm_mon % 2 == 0) {
        day->tm_mon += 1;
        day->tm_mday = 1;
        day->tm_hour = 10;
    }
    //Si a la hora de cambiar el dia se llega al final del anyo.
    else if (day->tm_mon == 11 && day->tm_mday == 31) {
        day->tm_year += 1;
        day->tm_mon = 1;
        day->tm_mday = 1;
        day->tm_hour = 10;
    }
    //Si no hay espacio el mismo dia pero no pasa nada de las anteriores condiciones.
    else {
        day->tm_mday += 1;
        day->tm_hour = 10;
    }
}
//Metodo que agrega entrevistas dependiendo de la disponibilidad de los dias.
void Program::addInterview(Candidate *candidate) {
    tm newDay = *day;

    auto *newInterview = new Interview(candidate, idInterview + 1, newDay.tm_hour); //Se crea el nuevo objeto con los atributos correspondientes.
    idInterview += 1;

    //Si no hay un dia establecido.
    if (interviewPerDay.find(&newDay) == interviewPerDay.end()) {
        vector<Interview*> interviews;

        //Agregamos el nuevo vector que guardara las entrevistas de ese dia en el mapa no ordenado.
        interviews.push_back(newInterview);
        interviewPerDay[&newDay] = interviews;
    }
    else {
        //Si lo hay y hay espacio en ese mismo dia.
        if (interviewPerDay[&newDay].size() < 5) {
            interviewPerDay[&newDay].push_back(newInterview);
        }
        else {
            //Como no hay espacio en el dia actual, entonces pasamos al siguiente dia. Podemos reutilizar el metodo para crear la entrevista.
            changeDay();
            addInterview(candidate);
        }
    }
    changeDay(); //Si o si se tiene que ejecutar este metodo para cambiar las fechas que se requeriran para futuras entrevistas.
}
//Metodo para revisar si existe una entrevista, ya que, dentro del mapa no ordenado, hay vectores.
Interview *Program::existInterview(double ID) {
    //Buscamos en los vectores que tiene cada llave del mapa no ordenado. Si se encuentra, se retorna el puntero de la entrevista, si no, se retorna un valor nulo.
    for (auto umap: interviewPerDay) {
        for (int i = 0; i < umap.second.size(); i++) {
            if (umap.second[i]->getId() == ID) {
                return umap.second[i];
            }
        }
    }
    return nullptr;
}

void Program::showInfoCon() {
    //Muestra toda la informacion de los paises que esten en el mapa no ordenado
    for(auto umap: countries){
        umap.second->returnInfo();
    }
}

void Program::showInfoCan() {
    for(auto umap: candidates){
        umap.second->showInfoCan();
    }
}

void Program::createInterviewGuide() {
    double id;
    cout << "Write the id of the inteview to generate the guide: ";
    cin >> id;
    if(existInterview(id) != nullptr){
        existInterview(id)->createInterviewGuide(day);
    }
    else{
        cout << "Interview not avaliable\n";
    }
}

unordered_map<string, Candidate *> Program::getCandidates() const {
    return candidates;
}

unordered_map<string, Country *> Program::getCountries() const{
    return countries;
}

bool Program::existCandidate(string name) {
    //Buscamos en los vectores que tiene cada llave del mapa no ordenado. Si se encuentra, se retorna el puntero de la entrevista, si no, se retorna un valor nulo.
    for (auto umap: candidates) {
        if (umap.second->getName() == name) {
            //(candidates.find(passport)==candidates.end())
            //return false
            return true;
        }
    }
    return false;
}

bool Program::existCountry(string country) {
    //Buscamos en los vectores que tiene cada llave del mapa no ordenado. Si se encuentra, se retorna el puntero de la entrevista, si no, se retorna un valor nulo.
    for (auto umap: countries) {
        if (umap.second->getName()== country) {
            return true;
        }
    }
    return false;
}

void Program::createWelcomeLetter() {
    string text;
    fstream outfile;

    text = "CODIGO DE LICENCIA Y CONDUCTA DE PARKINGSOFT COLOMBIA PARA EMPLEADOS, GERENTES Y AFILIADOS A LA EMPRESA\n"
           "Felicitaciones y bienvenido a la empresa de ParkingSoft Colombia, esperamos que sea una agradable experiencia tu integración en la empresa. En este documento explicamos todas las reglas básicas de comportamiento, confidencialidad y de trabajo de la empresa.\n"
           "==COMPORTAMIENTO==\n"
           "Durante la estadía en la empresa se les pide a todos los empleadores que se respete las tradiciones de los demás trabajadores con el fin de mantener un ambiente sano durante la jornada laboral. Las reglas aplicadas en el ambiente laborar serán las dictadas en la actual constitución política de Colombia.\n"
           "En caso de haber un conflicto en el ambiente laborar por favor interponer una denuncia a los gerentes de recursos humanos o remitir un correo a la misma institución. La empresa se reserva el derecho a despedir a un empleado si infringe las normas de convivencia en el ambiente laboral.\n"
           "Correo: rHumanosParkingSoft@gmail.com\n"
           "==INTERCULTURALIDAD==\n"
           "ParkingSoft Colombia tiene como objetivo integrar a la comunidad internacional con el objetivo de enriquecer su conocimiento intercultural, por lo que estamos completamente abiertos frente a las tradiciones de los demás países y no nos oponemos frente a ello.\n"
           "==CONFIDENCIALIDAD==\n"
           "ParkingSoft se reserva el derecho a tomar acciones legales en el caso de que se promueva información sobre estrategias laborales, software y planes económicos que se planeen y/o produzcan.\n"
           "==DESCANSO LABORAL==\n"
           "La empresa respeta todo el derecho sobre los descansos sobre la jornada laboral tendrá en cuenta remunerar debidamente si se le pide a un empleador trabajar fuera de su jornada de descanso. Además, se respetarán los día festivos de acuerdo a la nacionalidad de los empleadores.";
    string filename("WelcomeLetter.txt"); //Generamos el nombre del nuevo archivo como el codigo de pasaporte del candidato (recordemos que es un codigo unico).
    FILE *newFile = fopen(filename.c_str(), "w+"); //Creamos o abrimos el archivo correspondiente.
    //Verificar si se abrio o creo correctamente.
    if (newFile) {
        fwrite(text.c_str(), 1, text.size(), newFile); //Agregar el texto al archivo.
        cout << "The new file has generated correctly!" << endl;
    }
    fclose(newFile); //IMPORTANTE siempre cerrar un archivo una vez que hayas terminado de trabajar en el.
}