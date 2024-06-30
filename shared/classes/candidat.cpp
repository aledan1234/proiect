#include "candidat.hpp"

Candidat::Candidat() {
    //
}

Candidat::Candidat(string nume, int varsta, int experienta, vector<int> aplicatiiId)
: nume(nume), varsta(varsta), experienta(experienta), aplicatiiId(aplicatiiId){}

Candidat::~Candidat() {
    //
}

string Candidat::getNume() const {
    return nume;
}

int Candidat::getVarsta() const {
    return varsta;
}

int Candidat::getExperienta() const {
    return experienta;
}

vector<int> Candidat::getAplicatiiId() const {
    return aplicatiiId;
}
