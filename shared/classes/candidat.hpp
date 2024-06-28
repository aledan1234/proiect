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
    vector<int> aplicatiiId;
public:
    Candidat();

    Candidat(string nume, int varsta, int experienta, int nrAplicatii, vector<int> aplicatiiId);

    ~Candidat();
};

#endif
