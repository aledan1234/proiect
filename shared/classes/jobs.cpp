#include "jobs.hpp"

Job::Job(int id, string compania, string pozitia, int experienta, vector<string> skills, int nrCandidati, Candidat candidati[])
: id(id), compania(compania), pozitia(pozitia), experienta(experienta), skills(skills), nrCandidati(nrCandidati) {

    for(int i = 0; i < nrCandidati; ++i) {
        this->candidati[i] = candidati[i];
    }

}

Job::~Job() {
    //delete[] candidati;
}

// getters

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

// setters

void Job::setCompania(const string comp) {
    compania = comp;
}

void Job::setPozitia(const string poz) {
    pozitia = poz;
}

void Job::setExperienta(const int exp) {
    experienta = exp;
}

void Job::addSkill(const string& skill) {
    skills.push_back(skill);
}
