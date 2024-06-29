#ifndef JOBS_MANAGEMENT_HPP
#define JOBS_MANAGEMENT_HPP

#include <iostream>
#include <vector>
#include <string>
#include "candidat.hpp"

using namespace std;

class Job {
private:
    int id;
    string compania;
    string pozitia;
    int experienta;
    vector<string> skills;
    int nrCandidati;
    Candidat candidati[900];

public:
    Job(int id, string compania, string pozitia, int experienta, vector<string> skills, int nrCandidati, Candidat candidati[]);

    ~Job();

    // getters
    int getId() const;
    string getCompania() const;
    string getPozitia() const;
    int getExperienta() const;
    vector<string> getSkills() const;
    int getNrCandidati() const;
    vector<Candidat> getCandidati() const;

    // setters
    void setCompania(const string compania);
    void setPozitia(const string pozitia);
    void setExperienta(const int experienta);
    void addSkill(const string& skill);
};

#endif
