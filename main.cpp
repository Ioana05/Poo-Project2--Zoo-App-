#include <bits/stdc++.h>

using namespace std;

//clasa interfata contine functia NumberofWorkers, care va
//calcula numarul de angajati in functie de numarul de exemplare
//pentru reptile si pasari , voi considera un muncitor
//pt trei exemplare, iar la animale, un muncitor pentru patru exemplare
class Interface{
public:
    virtual int NumberofWorkers()=0;
};

class ReadandWrite{
public:
    virtual istream& Read(istream&) = 0;
    virtual ostream& Write(ostream&) const = 0;
};

class Reptiles:public Interface {
private:
    int numberofSpecies;
    char* NameofSpecies;
    int EvolutionaryHistory;
    string Habitat;
    float temperature;
    bool isVenomous;

public:
    int NumberofWorkers(){
    if (this->numberofSpecies<=3 && this->numberofSpecies>0)
        return 1;
    else
        return int(this->numberofSpecies/3);
    return 0;
    }
    Reptiles();
    Reptiles(int numberofSpecies,char* NameofSpecies, int EvolutionaryHistory,string Habitat,float temperature, bool isVenomous);
    Reptiles(int numberofSpecies, char* NameofSpecies);
    Reptiles(string Habitat, float temperature);
    Reptiles(const Reptiles &obj);
    ~Reptiles(){
        if (this->NameofSpecies != NULL) {
            delete[] this->NameofSpecies;
            this->NameofSpecies = NULL;
        }
    }

    //functia mostenita


    // Getters
    int getNumberofSpecies() {return this->numberofSpecies;}
    const char* getNameofSpecies() {return this->NameofSpecies;}
    int getEvolutionaryHistory() {return this->EvolutionaryHistory;}
    string getHabitat() {return this->Habitat;}
    float getTemperature() {return this->temperature;}
    bool getIsVenomous() {return this->isVenomous;}

    // Setters
    void setNumberofSpecies(int value) {this->numberofSpecies=value;}
    void setNameofSpecies(char* value) {this->NameofSpecies=value;}
    void setEvolutionaryHistory(int value) {this->EvolutionaryHistory=value;}
    void setHabitat(string object ) {this->Habitat=object;}
    void  setTemperature(float value) {this->temperature=value;}
    void setIsVenomous(bool value) {this->isVenomous=value;}


    // Functii, citire & afisare
    bool protectedspace();
    friend ostream& operator <<(ostream& out, const Reptiles& obj);
    friend istream& operator >>(istream& in, Reptiles& obj);

    // Operatori
    bool operator ==(const Reptiles &obj);
    Reptiles& operator=(const Reptiles & obj);
    Reptiles& operator++();
    Reptiles operator++(int);
    Reptiles& operator--();
    Reptiles operator--(int);
    Reptiles operator+(const Reptiles&);
    Reptiles operator+(int);
    Reptiles operator-(const Reptiles&);
    Reptiles operator-(int);
    bool operator>=(const Reptiles&);
    bool operator<=(const Reptiles&);
    char operator [] (int);
    operator float();
};

Reptiles::Reptiles(){
    numberofSpecies=0;
    NameofSpecies=new char[strlen("Anonim"+1)]; ///alocam memorie
    strcpy(NameofSpecies,"Anonim"); /// atribui valoarea pentru care am alocat memorie
    EvolutionaryHistory=0;
    Habitat="Lacuri";
    temperature=0;
    isVenomous=false;
}

Reptiles::Reptiles(int numberofSpecies, char* NameofSpecies, int EvolutionaryHistory,string Habitat,float temperature,bool isVenomous){
    this->numberofSpecies = numberofSpecies;
    this->NameofSpecies=new char[strlen(NameofSpecies)+1]; ///doar alocam memorie
    strcpy(this->NameofSpecies,NameofSpecies);
    this->EvolutionaryHistory=EvolutionaryHistory;
    this->Habitat=Habitat;
    this->temperature=temperature;
    this->isVenomous=isVenomous;
}

Reptiles::Reptiles(int numberofSpecies, char *NameofSpecies) {
    this->numberofSpecies = numberofSpecies;
    this->NameofSpecies=new char[strlen(NameofSpecies)+1];
    strcpy(this->NameofSpecies,NameofSpecies);
}

Reptiles::Reptiles(string Habitat, float temperature) {
    this->Habitat=Habitat;
    this->temperature=temperature;
}

Reptiles::Reptiles(const Reptiles& obj){
    this->numberofSpecies=obj.numberofSpecies;
    this->NameofSpecies=new char[strlen(obj.NameofSpecies)+1]; ///doar alocam memorie
    strcpy(this->NameofSpecies,obj.NameofSpecies);
    this->EvolutionaryHistory=obj.EvolutionaryHistory;
    this->Habitat=obj.Habitat;
    this->temperature=obj.temperature;
    this->isVenomous=obj.isVenomous;
}

// Functii, citire & afisare
////////////////////////////

ostream& operator<<(ostream& out, const Reptiles& obj){
    out << " Number of Specimens: " << obj.numberofSpecies << endl;
    out << " Name of Specimen: " << obj.NameofSpecies <<endl;
    out << " Evolutionary History: " << obj.EvolutionaryHistory << endl;
    out << " Habitat: " << obj.Habitat << endl;
    out << " Required temperature: " << obj.temperature << endl;
    out << " Is it Venomous? " << obj.isVenomous << endl;
    return out;
}

istream& operator>>(istream& in, Reptiles& obj){  //
    cout << "Number of Specimens: ";
    in >> obj.numberofSpecies;
    cout << "Name of specimen: ";
    char aux[500];
    in >> aux;
    if (obj.NameofSpecies != NULL){
        delete[] obj.NameofSpecies;
    }
    obj.NameofSpecies=new char[strlen(aux)+1];
    strcpy(obj.NameofSpecies,aux);

    cout<< " Evolutionary History: ";
    in >> obj.EvolutionaryHistory;

    cout << " Habitat: ";
    in >> obj.Habitat;

    cout << " Required temperature ";
    in >> obj.temperature;

    int venomous;
    cout << " Is it venomous?( 0 = no, 1 = yes) ";
    in >> venomous;
    if(venomous==1)
        obj.isVenomous=true;
    else
        obj.isVenomous=false;

    return in;
}

// Operatori
////////////
Reptiles& Reptiles::operator=(const Reptiles& obj){
    if (this!=&obj){
        if (this->NameofSpecies != NULL) {
            delete[] this->NameofSpecies;
            this->NameofSpecies = NULL;
        }
        this->numberofSpecies=obj.numberofSpecies;
        this->NameofSpecies=new char[strlen(obj.NameofSpecies)+1]; ///doar alocam memorie
        strcpy(this->NameofSpecies,obj.NameofSpecies);
        this->EvolutionaryHistory=obj.EvolutionaryHistory;
        this->Habitat=obj.Habitat;
        this->temperature=obj.temperature;}
    return *this;
}

bool Reptiles:: operator== (const Reptiles &obj) {
    if (this->numberofSpecies!=obj.numberofSpecies)
        return false;
    if (strcmp(this->NameofSpecies,obj.NameofSpecies)!=0)
        return false;
    if (this->EvolutionaryHistory!=obj.EvolutionaryHistory)
        return false;
    if  (this->Habitat!=obj.Habitat)
        return false;
    if (this->temperature!=obj.temperature)
        return false;
    if (this->isVenomous!=obj.isVenomous)
        return false;
    return true;
}

char Reptiles::operator[](int index) {
    if(index<0)
        throw runtime_error("index invalid");
    else
        return this->NameofSpecies[index];
}

Reptiles::operator float() {
    return this->EvolutionaryHistory;
}

Reptiles &Reptiles::operator++() {  ///++a
    this->numberofSpecies++;
    return *this;
}

Reptiles Reptiles::operator++(int) {  ///a++
    Reptiles aux(*this);
    this->numberofSpecies++;
    return aux;
}

Reptiles &Reptiles::operator--() {  ///--a
    this->numberofSpecies--;
    return *this;
}

Reptiles Reptiles::operator--(int) {  ///a--
    Reptiles aux(*this);
    this->numberofSpecies--;
    return aux;
}

Reptiles Reptiles::operator+(const Reptiles & obj) {
    Reptiles aux(*this);
    aux.numberofSpecies=aux.numberofSpecies+obj.numberofSpecies;
    return aux;
}

Reptiles Reptiles::operator+(int species) {
    Reptiles aux(*this);
    aux.numberofSpecies=aux.numberofSpecies+species;
    return aux;
}

Reptiles Reptiles::operator-(const Reptiles & obj) {
    Reptiles aux(*this);
    if(aux.numberofSpecies-obj.numberofSpecies>=0){
        aux.numberofSpecies=aux.numberofSpecies-obj.numberofSpecies;
    }
    return aux;
}

Reptiles Reptiles::operator-(int species) {
    Reptiles aux(*this);
    if(aux.numberofSpecies-species>=0){
        aux.numberofSpecies=aux.numberofSpecies-species;
    }
    return aux;
}

bool Reptiles::operator<=(const Reptiles &obj) {
    if(this->numberofSpecies > obj.numberofSpecies)
        return false;
    return true;
}

bool Reptiles::operator>=(const Reptiles &obj) {
    if(this->numberofSpecies < obj.numberofSpecies)
        return false;
    return true;
}

bool Reptiles::protectedspace() {
    if (this->isVenomous){
        return true;}
    else{
        return false;}
}

class Birds {
private:
    string Name;
    bool isEndangered;
    static int numberofSpecies;
    double DailyCantitiesofFood;
    string BreedingSeason;
    string *PlumageColors;
    int NumberofPlumageColors;
    int membersOfFamily;
public:
    int NumberofWorkers(){
        if (this->numberofSpecies<=3 && this->numberofSpecies>0)
            return 1;
        else
            return int(this->numberofSpecies/3);
        return 0;
    }

    Birds();
    Birds(string Name,bool isEndangered, double DailyCantitiesofFood, string BreedingSeason, string *PlumageColors, int NumberofPlumageColors, int membersOfFamily);
    Birds(string Name);
    Birds(bool isEndangered, double DailyCantitiesofFood);
    Birds(const Birds &obj);
    ~Birds()
    {
        if(this->PlumageColors !=NULL)
        {
            delete[] this->PlumageColors;
            this->PlumageColors=NULL;
        }
        numberofSpecies--;
    }

    //Getters
    string getName() {return this->Name;}
    bool getIsEndangered() {return this->isEndangered;}
    static int getnumberOfSpecies() {return Birds::numberofSpecies;}
    double getDailyCantitiesofFood() {return this->DailyCantitiesofFood;}
    string getBreedingSeason() {return this->BreedingSeason;}
    const string* getPlumageColors() {return this->PlumageColors;}
    int getNumberofPlumageColors() {return this->NumberofPlumageColors;}
    int getMembersOfFamily() {return this->membersOfFamily;}

    //Setters
    void setName(string nume) {this->Name=nume;}
    void setIsEndangered(bool value) {this->isEndangered=value;}
    void setnumberofSpecies(int value) {this->numberofSpecies=value;}
    void setDailyCantitiesofFood(double value) {this->DailyCantitiesofFood=value;}
    void setBreedingSeason(string value) {this->BreedingSeason=value;}
    void setNumberofPlumageColors(int value) {this->NumberofPlumageColors=value;}
    void setMembersOfFamily(int value) {this->membersOfFamily=value;}
    void setPlumageColors(string* value,int NumberOfPlumageColors)
    {if (this->PlumageColors!=NULL){
            delete [] PlumageColors;
        }
        this->PlumageColors=new string[NumberOfPlumageColors];
        for(int i=0; i<NumberOfPlumageColors;i++)
            this->PlumageColors[i]=PlumageColors[i];
    }

    // Functii, citire & afisare
    ////////////////////////////
    int estimateNumberofFamilies();
    friend ostream& operator <<(ostream& out, const Birds& obj);
    friend istream& operator >>(istream& in, Birds& obj);

    // Operatori
    ////////////
    bool operator == (const Birds &obj);
    Birds& operator=(const Birds & obj);
    string operator [] (int);
    Birds& operator++();
    Birds operator++(int);
    Birds& operator--();
    Birds operator--(int);
    Birds operator+(const Birds&);
    Birds operator+(int);
    Birds operator-(const Birds&);
    Birds operator-(int);
    bool operator >=(const Birds&);
    bool operator <=(const Birds&);
    operator float();

};

int Birds::numberofSpecies=0;

// Constructori
///////////////

Birds::Birds(){
    Name="x";
    isEndangered=false;
    DailyCantitiesofFood=0;
    BreedingSeason="Nu stim";
    PlumageColors=NULL;
    NumberofPlumageColors=0;
    numberofSpecies++;
    membersOfFamily=0;
}

Birds::Birds(string Name,bool isEndangered, double DailyCantitiesofFood, string BreedingSeason,
             string *PlumageColors, int NumberofPlumageColors, int membersOfFamily) {
    this->Name=Name;
    this->isEndangered=isEndangered;
    this->DailyCantitiesofFood=DailyCantitiesofFood;
    this->BreedingSeason=BreedingSeason;
    this->NumberofPlumageColors=NumberofPlumageColors;
    this->PlumageColors=new string[NumberofPlumageColors];
    for(int i=0;i<NumberofPlumageColors;i++)
        this->PlumageColors[i]=PlumageColors[i];
    numberofSpecies++; //fara this pentru ca e element static si poate fi accesat
    this->membersOfFamily=membersOfFamily;
}

Birds::Birds(string Name) {
    this->Name=Name;
}

Birds::Birds(bool isEndangered, double DailyCantitiesofFood){
    this->isEndangered=isEndangered;
    this->DailyCantitiesofFood=DailyCantitiesofFood;
}

Birds::Birds(const Birds &obj) {
    this->Name=obj.Name;
    this->isEndangered=obj.isEndangered;
    this->DailyCantitiesofFood=obj.DailyCantitiesofFood;
    this->BreedingSeason=obj.BreedingSeason;
    this->NumberofPlumageColors=obj.NumberofPlumageColors;
    this->PlumageColors=new string[obj.NumberofPlumageColors];
    for(int i=0;i<NumberofPlumageColors;i++)
        this->PlumageColors[i]=obj.PlumageColors[i];
    numberofSpecies++;
    this->membersOfFamily=obj.membersOfFamily;
}

// Functii, citire & afisare
////////////////////////////

ostream& operator<<(ostream& out, const Birds& obj){
    out << " Name of Specimen: " << obj.Name << endl;
    out << " Is it endangered? " << obj.isEndangered << endl;
    out << " Daily Cantities of food: " << obj.DailyCantitiesofFood << endl;
    out << " Breeding Season: " << obj.BreedingSeason << endl;
    out << " Nestlings every year: ";
    for(int i=0;i<obj.NumberofPlumageColors;i++)
        cout<<obj.PlumageColors[i]<<" ";
    cout<<endl;
    out << " Maximum Eggs: " << obj.NumberofPlumageColors << endl;
    out << " Members of family: " << obj.membersOfFamily << endl;
    return out;
}

istream& operator >>(istream& in, Birds& obj){
    cout <<  " Name of Specimen: ";
    in >> obj.Name;

    int endangered;
    cout << " Is it endangered?( 0 = no, 1 = yes) ";
    in >> endangered;
    if(endangered==1)
        obj.isEndangered=true;
    else
        obj.isEndangered=false;

    cout << " Daily Cantities of food: ";
    in >> obj.DailyCantitiesofFood;
    cout <<  "Breeding Season:";
    in >> obj.BreedingSeason;
    cout << "Maximum eggs:";
    in >> obj.NumberofPlumageColors;
    cout << "Nestlings every Year:";
    if ( obj.PlumageColors!=NULL)
        delete [] obj.PlumageColors;
    obj.PlumageColors=new string[obj.NumberofPlumageColors];
    for(int i=0;i<obj.NumberofPlumageColors;i++)
        in >> obj.PlumageColors[i];
    cout << "Members of family:";
    in >> obj.membersOfFamily;
    return in;
}

// Operatori - birds
////////////////////
bool Birds::operator == (const Birds &obj) {
    if (this->Name != obj.Name)
        return false;
    if (this->isEndangered != obj.isEndangered)
        return false;
    if (this->DailyCantitiesofFood != obj.DailyCantitiesofFood)
        return false;
    if (this->BreedingSeason != obj.BreedingSeason)
        return false;
    if (this->PlumageColors != obj.PlumageColors)
        return false;
    if (this->NumberofPlumageColors!=obj.NumberofPlumageColors)
        return false;
    if(this->membersOfFamily!=obj.membersOfFamily)
        return false;
    return true;
}
Birds& Birds::operator=(const Birds& obj){
    if (this!=&obj){
        if(this->PlumageColors !=NULL)
        {
            delete[] this->PlumageColors;
            this->PlumageColors=NULL;
        }
        this->Name=obj.Name;
        this->isEndangered=obj.isEndangered;
        this->DailyCantitiesofFood=obj.DailyCantitiesofFood;
        this->BreedingSeason=obj.BreedingSeason;
        this->NumberofPlumageColors=obj.NumberofPlumageColors;
        this->PlumageColors=new string[obj.NumberofPlumageColors];
        for(int i=0;i<NumberofPlumageColors;i++)
            this->PlumageColors[i]=obj.PlumageColors[i];
        numberofSpecies++;
        this->membersOfFamily=obj.membersOfFamily;
    }
    return *this;
}
string Birds::operator[](int a) {
    if(this->NumberofPlumageColors == 0)
        throw runtime_error("Do not exist datas about plumage");
    if(a<0 || a>this->NumberofPlumageColors)
        throw runtime_error("index invalid");
    else
        return this->PlumageColors[a];

}

Birds::operator float() {
    return this->DailyCantitiesofFood;
}

Birds &Birds::operator++() {
    this->membersOfFamily++;
    return *this;
}

Birds Birds::operator++(int) {
    Birds aux(*this);
    this->membersOfFamily++;
    return aux;
}

Birds &Birds::operator--() {
    this->membersOfFamily--;
    return *this;
}

Birds Birds::operator--(int) {
    Birds aux(*this);
    this->membersOfFamily--;
    return aux;
}

Birds Birds::operator+(const Birds &obj) {
    Birds aux(*this);
    aux.membersOfFamily=aux.membersOfFamily+obj.membersOfFamily;
    return aux;
}

Birds Birds::operator+(int members) {
    Birds aux(*this);
    aux.membersOfFamily=aux.membersOfFamily+members;
    return aux;
}

Birds Birds::operator-(const Birds &obj) {
    Birds aux(*this);
    if(aux.membersOfFamily-obj.membersOfFamily>=0){
        aux.membersOfFamily=aux.membersOfFamily-obj.membersOfFamily;
    }
    return *this;
}

Birds Birds::operator-(int members) {
    Birds aux(*this);
    if(aux.membersOfFamily-members>=0){
        aux.membersOfFamily=aux.membersOfFamily-members;
    }
    return *this;
}

bool Birds::operator>=(const Birds &obj) {
    if(this->membersOfFamily < obj.membersOfFamily){
        return false;
    }
    return true;
}

bool Birds::operator<=(const Birds &obj) {
    if(this->membersOfFamily > obj.membersOfFamily){
        return false;
    }
    return false;
}

int Birds::estimateNumberofFamilies() {
    int Families=0;
    if (this->numberofSpecies>0)
        Families=int(this->numberofSpecies/this->membersOfFamily);
}

class Animals: public ReadandWrite{
protected:
    string Name;
    int NumberofSpecimens;
    float Cantityoffood;
    int Lifespan;

public:
    int NumberofWorkers(){
        if (this->NumberofSpecimens<=4 && this->NumberofSpecimens>0)
            return 1;
        else
            return int(this->NumberofSpecimens/4);
        return 0;
    }

    ///constructorii
    Animals();
    Animals(string Name, int NumberofSpecimens, float CantityofFood, int Lifespan);
    Animals(const Animals& obj);
    ///destructor
    virtual ~Animals(){};

    string getName() {return this -> Name; }
    int getNumberofSpecimens() {return this -> NumberofSpecimens; }
    float getCantityoffood() {return this -> Cantityoffood; }
    int getLifespan() {return this -> Lifespan;}

    void setName(string Name) { this->Name = Name; }
    void setNumberofSpecimens(int NumberofSpecimens) {this->NumberofSpecimens= NumberofSpecimens;}
    void setCantityofFood(float Cantityoffood) { this-> Cantityoffood= Cantityoffood;}
    void setLifespan (int Lifespan ) {this->Lifespan = Lifespan; }

    Animals& operator=(const Animals& copy);

    //functii, citire, afisare
    ///
    friend istream& operator>>(istream& in, Animals& copy);
    friend ostream& operator<<(ostream& out, const Animals& copy);

    istream& Read(istream& in){
        cout<< "Name: ";
        in >> this->Name;
        cout << endl << "Number of Specimens";
        in >> this->NumberofSpecimens;
        cout << endl << "Cantity of food: ";
        in >> this->Cantityoffood;
        cout << endl << "Lifespan:  ";
        in >> this->Lifespan;
        return in;
    }

    ostream& Write(ostream& os) const{
        os << "Name: "<< this->Name <<endl;
        os << "Number of Specimens: " << this->NumberofSpecimens << endl;
        os << "Cantity of food: " << this->Cantityoffood << endl;
        os << "Lifespan: " << this->Lifespan <<endl;
        return os;
    }

    virtual float FoodDemand() const=0;
};

Animals::Animals(){
    Name="X";
    NumberofSpecimens=0;
    Cantityoffood=0;
    Lifespan=0;
}
Animals::Animals(string Name, int NumberofSpecimens, float CantityofFood, int Lifespan) {
    this->Name = Name;
    this->NumberofSpecimens = NumberofSpecimens;
    this->Cantityoffood = CantityofFood;
    this ->Lifespan = Lifespan;
}
Animals::Animals(const Animals &obj) {
    this->Name=obj.Name;
    this->NumberofSpecimens=obj.NumberofSpecimens;
    this->Cantityoffood=obj.Cantityoffood;
    this->Lifespan=obj.Lifespan;
}
Animals& Animals::operator=(const Animals& copy){
    if(this != &copy){
        this->Name=copy.Name;
        this->NumberofSpecimens=copy.NumberofSpecimens;
        this->Cantityoffood=copy.Cantityoffood;
        this->Lifespan=copy.Lifespan;
    }
    return *this;
}
istream& operator>>(istream& in,Animals& copy){
    cout<< "Name: ";
    in >> copy.Name;
    cout << endl << "Number of Specimens";
    in >> copy.NumberofSpecimens;
    cout << endl << "Cantity of food: ";
    in >> copy.Cantityoffood;
    cout << endl << "Lifespan:  ";
    in >> copy.Lifespan;

}

ostream& operator<<(ostream& out,const Animals& copy){
    cout << "Name: "<< copy.Name <<endl;
    cout << "Number of Specimens: " << copy.NumberofSpecimens << endl;
    cout << "Cantity of food: " << copy.Cantityoffood << endl;
    cout << "Lifespan: " << copy.Lifespan <<endl;
}

// declaratie forward pentru a putea accesa in clasa Domestic_Animals
class Wild_Animals;

class Domestic_Animals:virtual public Animals{
protected:
    char *GroomDates; //datele la care s -a facut curatenie
    bool VeterinaryCheckup;
    string personality;
    string BirthDate;

public:
    // Constructori
    Domestic_Animals();
    Domestic_Animals(string Name,int NumberofSpecimens, float Cantityoffood, int Lifespan, char *GroomDamtes, bool VeterinaryCheckup,string personality,string BirthDate);
    Domestic_Animals(const Domestic_Animals &obj);
    virtual ~Domestic_Animals()
    {
        if(this->GroomDates!=NULL)
        {
            delete [] this->GroomDates;
            this->GroomDates=NULL;
        }
    }

    //Getters
    const char* getGroomDates() {return this->GroomDates;} ///const char*
    bool getVeterinaryCheckup() {return this->VeterinaryCheckup;}
    string getPersonality() {return this->personality;}
    string getBirthDate() {return this->BirthDate;}

    //Setters
    void setGroomDates(char* value)
    {if (this->GroomDates!=NULL)
        {delete[] this->GroomDates;
            this->GroomDates=new char[strlen(value)+1];
            strcpy(this->GroomDates,value);}
    }
    void setVeterinaryCheckup(bool value) {this->VeterinaryCheckup=value;}
    void setPersonality(string value) {this->personality=value;}

    // Functii, citire & afisare
    ////////////////////////////
    string ScheduleforPlaying(); //va primi ca parametru personality iar personality se va imparti in 3 categorii,altfel realizand un rptogram de joaca
    friend ostream& operator << (ostream& out, const Domestic_Animals& obj);
    friend istream& operator >> (istream& in, Domestic_Animals& obj);

    istream& Read(istream& in){
        this->Animals::Read(in);
        cout << " Groom dates: ";
        char aux[50];
        in >> aux;
        if (this->GroomDates!=NULL)
            delete [] this->GroomDates;
        this->GroomDates=new char[strlen(aux)+1];
        strcpy(this->GroomDates,aux);
        int checkup;
        cout << " Veterinary Checkup( 0 = no, 1 = yes) ";
        in >> checkup;
        if(checkup==1)
            this->VeterinaryCheckup=true;
        else
            this->VeterinaryCheckup=false;

        cout << " Personality: ";
        in >> this->personality;
        cout << "Birth Date: ";
        in >> this->BirthDate;

        return in;
    }

    ostream& Write(ostream& os) const{
        this->Animals::Write(os);
        os << " Groom dates: " << this->GroomDates << endl;
        os << " Veterinary Checkup: " << this->VeterinaryCheckup << endl;
        os << " Personality: " << this->personality << endl;
        os << " Birth Date: "<< this->BirthDate << endl;
        return os;

    }

    // Operatori
    ////////////
    bool operator == (const Domestic_Animals &obj);
    Domestic_Animals& operator=(const Domestic_Animals & obj);
    operator int();
    bool operator <= (const Domestic_Animals &obj);
    bool operator >= (const Domestic_Animals &obj);
    Domestic_Animals& operator++();
    Domestic_Animals operator++(int);
    Domestic_Animals& operator--();
    Domestic_Animals operator--(int);
    Domestic_Animals operator+(const Domestic_Animals&);
    Domestic_Animals operator+(int);
    Domestic_Animals operator+(Wild_Animals);
    Domestic_Animals operator-(const Domestic_Animals&);
    Domestic_Animals operator-(int);

    //consideram ca in general animalele domestice sunt ierbivore sau omnivore
    float FoodDemand() const {
        float price=0;
        float totalcantity=this->NumberofSpecimens*this->Cantityoffood;
        price=50*totalcantity;
        return price;
    }
};

// Constructori
Domestic_Animals::Domestic_Animals(): Animals() {
    GroomDates=new char[strlen("16.03.2023")+1]; ///am alocat memorie
    strcpy(GroomDates,"16.03.2023");
    VeterinaryCheckup=0;
    personality="playful";
    BirthDate="20.04.2018";
}
Domestic_Animals::Domestic_Animals(string Name, int NumberofSpecimens, float Cantityoffood, int Lifespan, char *GroomDates, bool VeterinaryCheckup,
                                   string personality,string BirthDate): Animals(Name,NumberofSpecimens, Cantityoffood,  Lifespan) {

    this->GroomDates=new char[strlen(GroomDates)+1];
    strcpy(this->GroomDates,GroomDates);
    this->VeterinaryCheckup=VeterinaryCheckup;
    this->personality=personality;
    this->BirthDate=BirthDate;
}

Domestic_Animals::Domestic_Animals(const Domestic_Animals &obj):Animals(obj) {
    this->GroomDates=new char[strlen(obj.GroomDates)+1];
    strcpy(this->GroomDates,obj.GroomDates);
    this->VeterinaryCheckup=obj.VeterinaryCheckup;
    this->personality=obj.personality;
    this->BirthDate=obj.BirthDate;
}

// Functii, citire & afisare
////////////////////////////
ostream& operator<<(ostream& out, const Domestic_Animals& obj){
    out << (Animals&)obj;
    out << " Groom dates: " << obj.GroomDates << endl;
    out << " Veterinary Checkup: " << obj.VeterinaryCheckup << endl;
    out << " Personality: " << obj.personality << endl;
    out << " Birth Date: "<< obj.BirthDate << endl;
    return out;
}
istream& operator >> (istream& in, Domestic_Animals& obj){
    cout <<(Animals&)obj;
    cout << " Groom dates: ";
    char aux[50];
    in >> aux;
    if (obj.GroomDates!=NULL)
        delete [] obj.GroomDates;
    obj.GroomDates=new char[strlen(aux)+1];
    strcpy(obj.GroomDates,aux);
    int checkup;
    cout << " Veterinary Checkup( 0 = no, 1 = yes) ";
    in >> checkup;
    if(checkup==1)
        obj.VeterinaryCheckup=true;
    else
        obj.VeterinaryCheckup=false;

    cout << " Personality: ";
    in >> obj.personality;
    cout << "Birth Date: ";
    in >> obj.BirthDate;

    return in;
}
bool Domestic_Animals::operator ==(const Domestic_Animals &obj){
    if (this->Name != obj.Name)
        return false;
    if (this->NumberofSpecimens !=NumberofSpecimens)
        return false;
    if (this->Cantityoffood != obj.Cantityoffood)
        return false;
    if(strcmp(this-> GroomDates,obj.GroomDates)!=0)
        return false;
    if (this->VeterinaryCheckup != obj.VeterinaryCheckup)
        return false;
    if (this->personality != obj.personality)
        return false;
    if (this->BirthDate != obj.BirthDate)
    return true;
}
Domestic_Animals& Domestic_Animals::operator=(const Domestic_Animals& obj){
    if (this!=&obj)
    {
        Animals::operator=(obj);
        if(this->GroomDates!=NULL)
        {
            delete [] this->GroomDates;
            this->GroomDates=NULL;
        }
        this->NumberofSpecimens=obj.NumberofSpecimens;
        this->Name=obj.Name;
        this->Cantityoffood=obj.Cantityoffood;
        this->GroomDates=new char[strlen(obj.GroomDates)+1];
        strcpy(this->GroomDates,obj.GroomDates);
        this->VeterinaryCheckup=obj.VeterinaryCheckup;
        this->personality=obj.personality;
        this->BirthDate=obj.BirthDate;
    }
    return *this;
}

Domestic_Animals& Domestic_Animals::operator++() //++a
{
    this->NumberofSpecimens++;
    return *this;
}
Domestic_Animals Domestic_Animals::operator++(int) //a++
{
    Domestic_Animals aux(*this);
    this->NumberofSpecimens++;
    return aux;
}
Domestic_Animals& Domestic_Animals::operator--()
{
    if (this->NumberofSpecimens>=1)
    {
        this->NumberofSpecimens--;
    }
    return *this;
}
Domestic_Animals Domestic_Animals::operator--(int)
{
    Domestic_Animals aux(*this);
    if (this->NumberofSpecimens>=1)
    {
        this->NumberofSpecimens--;
    }
    return aux;
}
Domestic_Animals Domestic_Animals::operator-(const Domestic_Animals &obj)
{
    Domestic_Animals aux(*this);
    if (aux.Cantityoffood-obj.Cantityoffood>=0)
    {
        aux.Cantityoffood=aux.Cantityoffood-obj.Cantityoffood;
    }
    return aux;
}
Domestic_Animals Domestic_Animals::operator-(int food)
{
    Domestic_Animals aux(*this);
    if (this->Cantityoffood-food>=0)
    {
        this->Cantityoffood=this->Cantityoffood-food;
    }
    return aux;
}
Domestic_Animals Domestic_Animals::operator+(const Domestic_Animals &obj)
{
    Domestic_Animals aux(*this);
    aux.Cantityoffood=aux.Cantityoffood+obj.Cantityoffood;
    return aux;
}
Domestic_Animals Domestic_Animals::operator+(int food)
{
    Domestic_Animals aux(*this);
    this->Cantityoffood=this->Cantityoffood+food;
    return aux;
}

bool Domestic_Animals::operator<=(const Domestic_Animals &obj) {
    if (this->NumberofSpecimens > obj.NumberofSpecimens)
        return false;
    return true;
}

bool Domestic_Animals::operator>=(const Domestic_Animals &obj) {
    if (this->NumberofSpecimens < obj.NumberofSpecimens)
        return false;
    return true;
}

// In functie de tipul de personalitate,
// se va alege un interval pentru joaca
string Domestic_Animals::ScheduleforPlaying() {
    string aux=this->personality;
    transform(aux.begin(), aux.end(), aux.begin(), ::toupper);
    if(aux=="PLAYFUL")
    {
        return "Between hours 12:00 and 16:00";
    }
    else if(aux=="SOCIABLE")
    {
        return "Between hours 12:00 and 14:00";
    }
    else if(aux=="AGGRESSIVE")
    {
        return "No schedule for playing ";
    }
    else
    {
        return "Can not calculate schedule for playing";
    }
}

class Wild_Animals:virtual public Animals{
protected:
    bool Hibernate;
    int numberofOffsprings;
    string Behavior;
    bool migrateInHerd;
    string TypeofDiet;

public:
    // Constructori
    Wild_Animals();
    Wild_Animals(string Name ,int NumberofSpecimens, float Cantityoffood, int Lifespan, bool Hibernate, int numberofOffsprings, string Behavior, bool migrateInHerd, string TypeofDiet);
    Wild_Animals(const Wild_Animals& obj);

    virtual ~Wild_Animals(){};

    //Getters
    bool getHibernate() {return this->Hibernate;}
    int getnumberofOffsprings() {return this->numberofOffsprings;}
    string getBehaviour() {return this->Behavior;}
    bool getmigrateinHerd() {return this->migrateInHerd;}
    string getTypeofDiet() const {return this->TypeofDiet;} //am adaugat const pt ca functia din care apelez getterul e tot const

    //Setters
    void setHibernate(bool value) {this->Hibernate=value;}
    void setnumberofOffsprings(int value) {this->numberofOffsprings=value;}
    void setBehaviour(string value) {this->Behavior=value;}
    void setmigrateinHerd(bool value) { this->migrateInHerd=value;}
    void setTypeofDiet(string value) { this->TypeofDiet=value;}

    // Functii, citire & afisare
    ////////////////////////////
    string CooperateHunt(); //I can use migrateinHerd as a parameter //use the Typeofdiet
    friend ostream& operator <<(ostream& out, const Wild_Animals& obj);
    friend istream& operator >>(istream& in, Wild_Animals& obj);

    istream& Read(istream& in){
        this->Animals::Read(in);
        cout << "Does it hibernate? " << endl;
        in >> this->Hibernate;
        cout << "Medium number of offsprings: ";
        in >> this->numberofOffsprings;
        cout << "Characteristic behavior: ";
        in >>this->Behavior;

        int migrate;
        in >> migrate;
        if(migrate==1)
            this->migrateInHerd=true;
        else
            this->migrateInHerd=false;

        cout << "TypeofDiet? ";
        in >> this->TypeofDiet;
        return in;

    }

    ostream& Write(ostream& os) const{
        this->Animals::Write(os);
        os << " Does it hibernates? " << this->Hibernate << endl;
        os << " Medium number of offsprings: " << this->numberofOffsprings << endl;
        os << " Characteristic behavior: " << this->Behavior << endl;
        os << " Does it migrate in herd? " << this->migrateInHerd << endl;
        os << " TypeofDiet: " << this->TypeofDiet << endl;
        return os;

    }

    // Operatori
    bool operator == (const Wild_Animals &obj);
    Wild_Animals& operator=(const Wild_Animals &obj);
    Wild_Animals& operator++();
    Wild_Animals operator++(int);
    Wild_Animals& operator--();
    Wild_Animals operator--(int);
    Wild_Animals operator+(const Wild_Animals&);
    Wild_Animals operator+(int);
    Wild_Animals operator+(Domestic_Animals);
    Wild_Animals operator-(const Wild_Animals&);
    Wild_Animals operator-(int);
    bool operator <= (const Wild_Animals &obj);
    bool operator >= (const Wild_Animals &obj);
    operator float();

    float FoodDemand() const {
        float price=0, price1=0,price2=0;
        if(this->TypeofDiet=="carnivorous")
            {float totalcantityC=this->NumberofSpecimens*this->Cantityoffood;
            float price1=100* totalcantityC;} ///consideram ca
        else
            {float totalcantityV=this->NumberofSpecimens*this->Cantityoffood;
             float price2=50*totalcantityV;}
        price=price1+price2;
        return price;
    }
};

// Constructori
Wild_Animals::Wild_Animals():Animals() {
    Hibernate="no";
    numberofOffsprings=0;
    Behavior="violent";
    migrateInHerd=false;
    TypeofDiet="carnivorous";
}

Wild_Animals::Wild_Animals(string Name, int NumberofSpecimens, float Cantityoffood, int Lifespan, bool Hibernate,
                           int numberofOffsprings, string Behavior, bool migrateInHerd,
                           string TypeofDiet):Animals(Name, NumberofSpecimens, Cantityoffood, Lifespan) {
    this->Hibernate=Hibernate;
    this->numberofOffsprings=numberofOffsprings;
    this->Behavior=Behavior;
    this->migrateInHerd=migrateInHerd;
    this->TypeofDiet=TypeofDiet;
}

Wild_Animals::Wild_Animals(const Wild_Animals &obj): Animals(obj){
    this->Hibernate=obj.Hibernate;
    this->numberofOffsprings=obj.numberofOffsprings;
    this->Behavior=obj.Behavior;
    this->migrateInHerd=obj.migrateInHerd;
    this->TypeofDiet=obj.TypeofDiet;
}

// Functii, citire & afisare
////////////////////////////
ostream& operator<<(ostream& out, const Wild_Animals& obj){
    out << (Animals&)obj;
    out << " Does it hibernates? " << obj.Hibernate << endl;
    out << " Medium number of offsprings: " << obj.numberofOffsprings << endl;
    out << " Characteristic behavior: " << obj.Behavior << endl;
    out << " Does it migrate in herd? " << obj.migrateInHerd << endl;
    out << " TypeofDiet: " << obj.TypeofDiet << endl;
    return out;
}

istream& operator>>(istream& in, Wild_Animals& obj){
    in >> (Animals&)obj;
    cout << endl;
    cout << "Does it hibernate? " << endl;
    in >> obj.Hibernate;
    cout << "Medium number of offsprings: ";
    in >> obj.numberofOffsprings;
    cout << "Characteristic behavior: ";
    in >>obj.Behavior;

    int migrate;
    in >> migrate;
    if(migrate==1)
        obj.migrateInHerd=true;
    else
        obj.migrateInHerd=false;

    cout << "TypeofDiet? ";
    in >> obj.TypeofDiet;
    return in;
}
bool Wild_Animals::operator == (const Wild_Animals &obj){
    if (this->Hibernate != obj.Hibernate)
        return false;
    if (this->numberofOffsprings != obj.numberofOffsprings)
        return false;
    if (this->Behavior != obj.Behavior)
        return false;
    if (this->migrateInHerd!= obj.migrateInHerd)
        return false;
    if (this->TypeofDiet!=obj.TypeofDiet)
        return false;
    return true;
}
Wild_Animals& Wild_Animals::operator=(const Wild_Animals& obj){
    if (this!=&obj)
    {   Animals::operator=(obj);
        this->Hibernate=obj.Hibernate;
        this->numberofOffsprings=obj.numberofOffsprings;
        this->Behavior=obj.Behavior;
        this->migrateInHerd=obj.migrateInHerd;
        this->TypeofDiet=obj.TypeofDiet;
    }
    return *this;
}

Wild_Animals& Wild_Animals::operator++() //++a
{
    this->numberofOffsprings++;
    return *this;
}
Wild_Animals Wild_Animals::operator++(int) //a++
{
    Wild_Animals aux(*this); //ca sa pastram valoarea anterioara,fara sa o crestem
    this->numberofOffsprings++;
    return aux;
}
Wild_Animals& Wild_Animals::operator--()
{
    if (this->numberofOffsprings>=1)
    {
        this->numberofOffsprings--;
    }
    return *this;
}
Wild_Animals Wild_Animals::operator--(int)
{
    Wild_Animals aux(*this);
    if (this->numberofOffsprings>=1)
    {
        this->numberofOffsprings--;
    }
    return aux;
}
Wild_Animals Wild_Animals::operator-(const Wild_Animals &obj)
{
    Wild_Animals aux(*this);
    if (aux.Cantityoffood-obj.Cantityoffood>=0)
    {
        aux.Cantityoffood=aux.Cantityoffood-obj.Cantityoffood;
    }
    return aux;
}
Wild_Animals Wild_Animals::operator-(int food)
{
    Wild_Animals aux(*this);
    if (this->Cantityoffood-food>=0)
    {
        this->Cantityoffood=this->Cantityoffood-food;
    }
    return aux;
}
Wild_Animals Wild_Animals::operator+(const Wild_Animals &obj)
{
    Wild_Animals aux(*this);
    aux.Cantityoffood=aux.Cantityoffood+obj.Cantityoffood;
    return aux;
}

Wild_Animals Wild_Animals::operator+(int food)
{
    Wild_Animals aux(*this);
    this->Cantityoffood=this->Cantityoffood+food;
    return aux;
}

bool Wild_Animals::operator<=(const Wild_Animals &obj) {
    if (this->numberofOffsprings > obj.numberofOffsprings)
        return false;
    return true;
}

bool Wild_Animals::operator>=(const Wild_Animals &obj) {
    if (this->numberofOffsprings < obj.numberofOffsprings)
        return false;
    return true;
}

Wild_Animals::operator float() {
    return this->numberofOffsprings;
}


string Wild_Animals::CooperateHunt() {
    string aux=this->TypeofDiet;
    // Transforma string-ul din litere mici in litere mari
    transform(aux.begin(), aux.end(), aux.begin(), ::toupper);
    if (this->migrateInHerd==1 && aux=="CARNIVOROUS")
        return "The animal hunts in group";
    else
        return "The animal does not hunt in group";
}

// A + A + B, B + A + B + A, A + B + A + B
// Pentru a putea face operatii de adunare pe clase diferite si a
// obtine un total de mancare necesar pentru animalele salbatice si domestice
Domestic_Animals Domestic_Animals::operator+(Wild_Animals obj){
    Domestic_Animals aux(*this);
    aux.Cantityoffood=aux.Cantityoffood+obj.getCantityoffood();
    return aux;
}

Wild_Animals Wild_Animals::operator+(Domestic_Animals obj) {
    Wild_Animals aux(*this);
    aux.Cantityoffood=aux.Cantityoffood+obj.getCantityoffood();
    return aux;
}

class Endangered_Animals:public Wild_Animals,public Domestic_Animals{
    int YearDeclaredEndangered;
public:
    Endangered_Animals(){
        this->YearDeclaredEndangered=0;
    }
    Endangered_Animals(string Name,int NumberofSpecimens, float Cantityoffood,
                       int Lifespan, char *GroomDates, bool VeterinaryCheckup,
                       string personality, string BirthDate, bool Hibernate,
                       int numberofoffsprings, string Behavior, bool migrateInHerd,
                       string TypeofDiet, int YearDeclaredEndangered ): Animals(Name,NumberofSpecimens,Cantityoffood,Lifespan)
                       ,Domestic_Animals(Name,NumberofSpecimens,Cantityoffood,Lifespan,GroomDates,VeterinaryCheckup,personality,BirthDate),
                        Wild_Animals(Name,NumberofSpecimens,Cantityoffood, Lifespan,Hibernate,numberofoffsprings,Behavior, migrateInHerd,TypeofDiet){
        this->YearDeclaredEndangered=YearDeclaredEndangered;
    }
    Endangered_Animals(const Endangered_Animals& obj):Animals(obj), Domestic_Animals(obj), Wild_Animals(obj){
        this->YearDeclaredEndangered=obj.YearDeclaredEndangered;
    }
    Endangered_Animals& operator=(const Endangered_Animals& obj){
        if(this!=&obj){
            Domestic_Animals::operator=(obj);
            Wild_Animals::operator=(obj);
            this->YearDeclaredEndangered=obj.YearDeclaredEndangered;
        }
        return *this;
    }
    ~Endangered_Animals(){};

    float FoodDemand() const {
        float price=0, price1=0,price2=0, price3=0;
        if(this->getTypeofDiet()=="carnivorous")
        {float totalcantityC=this->NumberofSpecimens*this->Cantityoffood;
            price1=100* totalcantityC;} ///consideram ca
        else
        {float totalcantityV=this->NumberofSpecimens*this->Cantityoffood;
            price2=50*totalcantityV;}
        price=(price1+price2)*(1,5); //consideram mai scumpa hrana pt endagered
        return price;
    }

    istream& Read(istream& in){
        Animals::Read(in);

        // citire pentreu DomesticAnimals
        cout << " Groom dates: ";
        char aux[50];
        in >> aux;
        if (this->GroomDates!=NULL)
            delete [] this->GroomDates;
        this->GroomDates=new char[strlen(aux)+1];
        strcpy(this->GroomDates,aux);
        int checkup;
        cout << " Veterinary Checkup( 0 = no, 1 = yes) ";
        in >> checkup;
        if(checkup==1)
            this->VeterinaryCheckup=true;
        else
            this->VeterinaryCheckup=false;

        cout << " Personality: ";
        in >> this->personality;
        cout << "Birth Date: ";
        in >> this->BirthDate;

        // citire pentru WildAnimals
        cout << "Does it hibernate? " << endl;
        in >> this->Hibernate;
        cout << "Medium number of offsprings: ";
        in >> this->numberofOffsprings;
        cout << "Characteristic behavior: ";
        in >> this->Behavior;

        int migrate;
        in >> migrate;
        if(migrate==1)
            this->migrateInHerd=true;
        else
            this->migrateInHerd=false;

        cout << "TypeofDiet? ";
        in >> this->TypeofDiet;

        return in;
    }

    ostream& Write(ostream& os) const{
        Animals::Write(os);

        // afisare pentru DomesticAnimals
        os << " Groom dates: " << this->GroomDates << endl;
        os << " Veterinary Checkup: " << this->VeterinaryCheckup << endl;
        os << " Personality: " << this->personality << endl;
        os << " Birth Date: "<< this->BirthDate << endl;


        // afisare pentru WildAnimals
        os << " Does it hibernates? " << this->Hibernate << endl;
        os << " Medium number of offsprings: " << this->numberofOffsprings << endl;
        os << " Characteristic behavior: " << this->Behavior << endl;
        os << " Does it migrate in herd? " << this->migrateInHerd << endl;
        os << " TypeofDiet: " << this->TypeofDiet << endl;

        return os;
    }

    friend ostream& operator <<(ostream& out, const Endangered_Animals& obj);
    friend istream& operator >>(istream& in, Endangered_Animals& obj);

};

class AnimalsInventory{
    Animals* animals;
public:
    friend istream& operator >>(istream& in, AnimalsInventory& obj){
        cout << "1.Domestic Animal\n";
        cout << "2.Wild Animal\n";
        cout << "3.Endangered Animal\n";
        int k;
        cin >> k;
        if(k == 1){
            obj.animals = new Domestic_Animals();
        }
        if(k == 2){
            obj.animals = new Wild_Animals();
        }
        if(k == 3)
            obj.animals = new Endangered_Animals();
        in >> *obj.animals;
        return in;
    }

    friend ostream& operator <<(ostream& os, const AnimalsInventory& obj){
        os << "Animal: \n" << *obj.animals << endl;
        return os;
    }
    Animals* getAnimals() {return this->animals;}

};
istream& operator >>(istream& in, Endangered_Animals& obj){
    return obj.Read(in);
}
ostream& operator <<(ostream& os, const Endangered_Animals& obj){
    return obj.Write(os);
}

/*class ManagementoftheZOO{
private:
    string VisitingProgram;
    string ListofPrices;
    float TotalCantityofFood;

};
 */
int main() {

Reptiles Igoana(9,"Igoana",1000,"forest",10,0);
Endangered_Animals Panda("Panda",2,30, 10,"05/10/2003",1,"PLAYFUL","05/10/2003", 1, 3, "NICE",0,"ierbivorous",2010);
cout << Panda;
    /*
    cout << "Hello and Welcome to the zoo! What category of animals would you like to visit?";
    Reptiles listReptiles[100];
    Birds listBirds[100];
    Domestic_Animals listDomestic_Animals[100];
    Wild_Animals listWild_Animals[100];
    int contor1 = 0;
    int contor2 = 0;
    int contor3 = 0;
    int contor4 = 0;
    int k = 1;
    while (k == 1) {
        int comanda1; //am creat optiunile
        cout << "\n1-Reptiles";
        cout << "\n2-Birds";
        cout << "\n3-Domestic_Animals";
        cout << "\n4-Wild_Animals";
        cout << "\n5-Exit";
        cin >> comanda1;  //alegem optiunea pe care ne-o dorim
        switch (comanda1) {
            //reptile
            case 1: {
                int l = 1;
                while (l == 1) {
                    int comanda2;
                    cout << "\n11-Give these particular information about a reptile: ";
                    cout << "\n12-See the information you already added ";
                    cout << "\n13-Delete the datas about a specific animal ;";
                    cout << "\n14-Go back to the principal menu";
                    cout << "\n15-Display the number of venomous reptiles";
                    cin >> comanda2;
                    switch (comanda2) {
                        case 11: {
                            Reptiles R;
                            cin >> R;
                            listReptiles[contor1] = R;
                            contor1++;
                            break;
                        }
                        case 12: {
                            for (int i = 0; i < contor1; i++)
                                cout << listReptiles[i] << endl;
                            break;
                        }
                        case 13: {
                            cout << "Write the number of the animal you want to delete from the list:";
                            int nr;
                            cin >> nr;
                            if (nr > contor1)
                                cout << "The number is too big. Try again.";
                            else {
                                for (int i = nr - 1; i < contor1 - 1; i++) {
                                    listReptiles[i] = listReptiles[i + 1];
                                }
                                contor1--;
                            }
                            break;
                        }
                        case 14: {
                            l = 0;
                            break;
                        }
                        case 15: {
                            int veninoase = 0;
                            for (int i = 0; i < contor1; i++) {
                                if (listReptiles[i].protectedspace())
                                    veninoase = veninoase + 1;
                            }
                            cout << "There are " << veninoase << " venomous reptiles in the zoo." << endl;
                            break;
                        }
                    }
                }
                break;
            }
                //birds
            case 2: {
                int m = 1;
                while (m == 1) {
                    int comanda3;
                    cout << "\n21-Give these particular information about a bird: ";
                    cout << "\n22-See the information you already added ";
                    cout << "\n23-Delete the datas about a specific animal ;";
                    cout << "\n24-Go back to the principal menu";
                    cout << "\n25-Display estimated families of birds";
                    cin >> comanda3;
                    switch (comanda3) {
                        case 21: {
                            Birds B;
                            cin >> B;
                            listBirds[contor2] = B;
                            contor2++;
                            break;
                        }
                        case 22: {
                            for (int i = 0; i < contor2; i++)
                                cout << listBirds[i] << endl;
                            break;
                        }
                        case 23: {
                            cout << "Write the number of the animal you want to delete from the list:";
                            int nr;
                            cin >> nr;
                            if (nr > contor2)
                                cout << "The number is too big. Try again.";
                            else {
                                for (int i = nr - 1; i < contor2 - 1; i++) {
                                    listBirds[i] = listBirds[i + 1];
                                }
                                contor2--;
                            }
                            break;
                        }
                        case 24: {
                            m = 0;
                            break;
                        }
                        case 25: {
                            int populatie = 0;
                            for (int i = 0; i < contor2; i++) {
                                populatie = populatie + listBirds[i].estimateNumberofFamilies();
                            }
                            cout << "The estimated number of families is: " << populatie;
                            break;
                        }
                    }
                }
                break;
            }
                //domestic_animals
            case 3: {
                int n = 1;
                while (n == 1) {
                    int comanda4;
                    cout << "\n31-Give these particular information about a Domestic_Animal: ";
                    cout << "\n32-See the information you already added ";
                    cout << "\n33-Delete the datas about a specific animal ;";
                    cout << "\n34-Go back to the principal menu";
                    cout << "\n35-Display the schedule for playing with the animals";
                    cin >> comanda4;
                    switch (comanda4) {
                        case 31: {
                            Domestic_Animals D;
                            cin >> D;
                            listDomestic_Animals[contor3] = D;
                            contor3++;
                            break;
                        }
                        case 32: {
                            for (int i = 0; i < contor3; i++)
                                cout << listDomestic_Animals[i] << endl;
                            break;
                        }
                        case 33: {
                            cout << "Write the number of the animal you want to delete from the list:";
                            int nr;
                            cin >> nr;
                            if (nr > contor3)
                                cout << "The number is too big. Try again.";
                            else {
                                for (int i = nr - 1; i < contor3 - 1; i++) {
                                    listDomestic_Animals[i] = listDomestic_Animals[i + 1];
                                }
                                contor3--;
                            }
                            break;
                        }
                        case 34: {
                            n = 0;
                            break;
                        }
                        case 35: {
                            for (int i = 0; i < contor3; i++) {
                                cout << listDomestic_Animals[i].getName() << " --> "
                                     << listDomestic_Animals[i].ScheduleforPlaying() << endl;
                            }
                            break;
                        }
                    }
                }
                break;
            }
                //wild_animals
            case 4: {
                int o = 1;
                while (o == 1) {
                    int comanda5;
                    cout << "\n41-Give these particular information about a Wild_Animals: ";
                    cout << "\n42-See the information you already added ";
                    cout << "\n43-Delete the datas about a specific animal ;";
                    cout << "\n44-Go back to the principal menu";
                    cout << "\n45-Verify how many animals hunt together";
                    cin >> comanda5;
                    switch (comanda5) {
                        case 41: {
                            Wild_Animals D;
                            cin >> D;
                            listWild_Animals[contor4] = D;
                            contor4++;
                            break;
                        }
                        case 42: {
                            for (int i = 0; i < contor4; i++)
                                cout << listWild_Animals[i] << endl;
                            break;
                        }
                        case 43: {
                            cout << "Write the number of the animal you want to delete from the list:";
                            int nr;
                            cin >> nr;
                            if (nr > contor4)
                                cout << "The number is too big. Try again.";
                            else {
                                for (int i = nr - 1; i < contor4 - 1; i++) {
                                    listWild_Animals[i] = listWild_Animals[i + 1];
                                }
                                contor4--;
                            }
                            break;
                        }
                        case 44: {
                            o = 0;
                            break;
                        }
                        case 45: {
                            int haita = 0;
                            for (int i = 0; i < contor4; i++)
                                if (listWild_Animals[i].CooperateHunt() == "The animal hunts in group")
                                    haita = haita + 1;
                            cout << "There are " << haita << " animals hunting together" << endl;
                        }
                    }
                }
                break;
            }
            case 5: {
                k = 0;
                break;
            }
            default: {
                cout << "Please try again with another number." << endl;
            }
        }
    }
     */


    ///Reptiles Igoana;
    //    Reptiles Sarpe(4,"Sarpe",200,"lakes",20, false);
    //    cout<<Sarpe.getHabitat() << endl; ///folosim un getter ca sa afisam o valoare
    //    Reptiles Soparla(Sarpe), Crocodil=Sarpe; ///aici folosim constructorul de copiere
    //    cout<<Crocodil.getNumberofSpecies()<<endl;
//    Domestic_Animals D;
//    Wild_Animals W;
//    cout<<(D+W+W+W).getfeed();
}