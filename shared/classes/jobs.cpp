#include "jobs.hpp"

Jobs::Jobs(int id, string compania, string pozitia, int experienta, vector<string> skills, int nrCandidati, Candidat candidati[])
: id(id), compania(compania), pozitia(pozitia), skills(skills), experienta(experienta), nrCandidati(nrCandidati) {

    for(int i = 0; i < nrCandidati; i++) {
        this->candidati[i] = candidati[i];
    }

}

Jobs::~Jobs() {
    //delete[] candidati;
}
