#ifndef CANDIDAT_MANAGEMENT_HPP
#define CANDIDAT_MANAGEMENT_HPP

#include <vector>
#include <string>

using namespace std;

class Candidat {
private:
    string nume;
    int varsta;
    int experienta;
    int nrAplicatii;
    vector<int> aplicatiiId; // aici o sa fie id-urile de la joburi in loc de referinta la Joburi, precum: "Jobs aplicatii"
    // (ca sa nu avem dependenta ciclica despre care vorbea profesorul ca ar fi bine sa o evitam)
public:
    Candidat();

    Candidat(string nume, int varsta, int experienta, int nrAplicatii, vector<int> aplicatiiId);

    ~Candidat();
};

#endif
