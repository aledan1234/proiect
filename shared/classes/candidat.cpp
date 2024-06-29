#include "candidat.hpp"

Candidat::Candidat() {
    //
}

Candidat::Candidat(string nume, int varsta, int experienta, int nrAplicatii, vector<int> aplicatiiId)
: nume(nume), varsta(varsta), experienta(experienta), nrAplicatii(nrAplicatii), aplicatiiId(aplicatiiId){}

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

int Candidat::getNrAplicatii() const {
    return nrAplicatii;
}

vector<int> Candidat::getAplicatiiId() const {
    return aplicatiiId;
}
