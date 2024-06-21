#include "candidat.hpp"

Candidat::Candidat(string nume, int varsta, int experienta, int nrAplicatii, vector<int> aplicatiiId)
: nume(nume), varsta(varsta), experienta(experienta), nrAplicatii(nrAplicatii), aplicatiiId(aplicatiiId){}

Candidat::~Candidat() {
    //
}
