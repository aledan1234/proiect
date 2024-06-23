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

    int getId() const;
    string getCompania() const;
    string getPozitia() const;
    int getExperienta() const;
    vector<string> getSkills() const;
    int getNrCandidati() const;
    vector<Candidat> getCandidati() const;
};

#endif


// old code bellow

/*
struct Job {
    int id;
    string compania;
    string pozitia;
    int experienta;
    vector<string> skills;
};

struct Application {
    int jobId;
    string applicantName;
};

vector<Job> loadJobs(const string& filename);

void displayJobs(const vector<Job>& jobs);

vector<Job> filterJobsBySkill(const vector<Job>& jobs, const string& skill);

void applyForJob(const string& filename, int jobId, const string& applicantName);
*/

#endif
