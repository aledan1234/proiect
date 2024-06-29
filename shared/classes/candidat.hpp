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
    vector<int> aplicatiiId;
public:
    Candidat();

    Candidat(string nume, int varsta, int experienta, vector<int> aplicatiiId);

    ~Candidat();
    string getNume() const;
    int getVarsta() const;
    int getExperienta() const;
    vector<int> getAplicatiiId() const;
};

#endif
