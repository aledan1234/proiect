#include "jobs.hpp"
/*
Jobs::Jobs(int id, string compania, string pozitia, int experienta, vector<string> skills, int nrCandidati, Candidat candidati[])
: id(id), compania(compania), pozitia(pozitia), skills(skills), experienta(experienta), nrCandidati(nrCandidati) {

    for(int i = 0; i < nrCandidati; i++) {
        this->candidati[i] = candidati[i];
    }

}

Jobs::~Jobs() {
    //delete[] candidati;
}
*/
//am schimbat jobs la job, nu stiu de ce, dar altfel da eroare la citire, ceva de suprapunere, nu s sigur
#include "jobs.hpp"

Job::Job(int id, string compania, string pozitia, int experienta, vector<string> skills, int nrCandidati, Candidat candidati[])
: id(id), compania(compania), pozitia(pozitia), skills(skills), experienta(experienta), nrCandidati(nrCandidati) {

    for(int i = 0; i < nrCandidati; ++i) {
        this->candidati[i] = candidati[i];
    }

}

Job::~Job() {
    //delete[] candidati;
}

int Job::getId() const {
    return id;
}

string Job::getCompania() const {
    return compania;
}

string Job::getPozitia() const {
    return pozitia;
}

int Job::getExperienta() const {
    return experienta;
}

vector<string> Job::getSkills() const {
    return skills;
}

int Job::getNrCandidati() const {
    return nrCandidati;
}

vector<Candidat> Job::getCandidati() const {
    return vector<Candidat>(candidati, candidati + nrCandidati);
}
