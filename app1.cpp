#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "./shared/classes/jobs.cpp"
#include "./shared/classes/candidat.cpp"
using namespace std;

void saveDataJob(const vector<Job>& jobs, const string& filename) {
    string directory = "./shared/files/";
    string filePath = directory + filename;

    ofstream file(filePath);

    if (file.is_open()) {
        for (const auto& job : jobs) {
            file << job.getId() << " "
                 << job.getCompania() << " "
                 << job.getPozitia() << " "
                 << job.getExperienta() << " "
                 << job.getSkills().size() << " ";
            for (const auto& skill : job.getSkills()) {
                file << skill << " ";
            }

            file << "\n";
        }
        file.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

void saveDataCandidat(const vector<Job>& jobs, const string& filename) {
    string directory = "./shared/files/";
    string filePath = directory + filename;

    ofstream file(filePath);
            // file << job.getNrCandidati() << " ";
            // for (const auto& candidat : job.getCandidati()) {
            //     file << candidat.getNume() << " "
            //          << candidat.getVarsta() << " "
            //          << candidat.getExperienta() << " "
            //          << candidat.getNrAplicatii() << " ";
            //     for (const auto& aplicatieId : candidat.getAplicatiiId()) {
            //         file << aplicatieId << " ";
            //     }
            // }
            // file << endl;

}

vector<Job> loadJobs(const string& filename) {
    string directory = "./shared/files/";
    string filePath = directory + filename;
    vector<Job> jobs;
    ifstream file(filePath);

    if (file.is_open()) {
        int id;
        string compania, pozitia, title;
        int experienta, nrCandidati, numSkills;
        while (file >> id >> compania >> pozitia >> experienta >> numSkills) {
            vector<string> skills;
            for (int i = 0; i < numSkills; ++i) {
                string skill;
                file >> skill;
                skills.push_back(skill);
            }
            Candidat candidati[900];
            jobs.emplace_back(id, compania, pozitia, experienta, skills, nrCandidati, candidati);
        }
        file.close();
    }

    return jobs;  //g++ -o app view_jobs
}

void adaugare_job(vector<Job>& jobs, int id, const string& compania, const string& pozitia, int experienta, const vector<string>& skills) {
    int nrCandidati = 0;
    Candidat candidati[900];
    jobs.emplace_back(id, compania, pozitia, experienta, skills, nrCandidati, candidati);

    saveDataJob(jobs, "jobs.txt");
}

void stergere_job(vector<Job>& jobs, int id, bool shoouldSave) {
    auto it = std::find_if(jobs.begin(), jobs.end(), [id](const Job& job) {
        return job.getId() == id;
    });

    if (it != jobs.end()) {
        jobs.erase(it);
    } else {
        cout << "Job with ID " << id << " not found." << endl;
    }

    if(shoouldSave) {
        saveDataJob(jobs, "jobs.txt");
    }
}

void modificare_job(vector<Job>& jobs, int id, const string& field, const string& new_value) {
    // find the job we want
    auto it = find_if(jobs.begin(), jobs.end(), [id](const Job& job) { return job.getId() == id; });

    if (it != jobs.end()) {
        // Delete the job
        stergere_job(jobs, id, 0);

        if (field == "nume") {
            it->setCompania(new_value);
        } else if (field == "pozitia") {
            it->setPozitia(new_value);
        } else if (field == "skill") {
            it->addSkill(new_value);
        } else if (field == "experienta") {
            int new_experienta = stoi(new_value);
            it->setExperienta(new_experienta);
        } else {
            cout << "Invalid field! Should be: 'nume', 'pozitia', 'skill', 'experienta'" << endl;
            return;
        }

        // Add the modified job
        adaugare_job(jobs, it->getId(), it->getCompania(), it->getPozitia(), it->getExperienta(), it->getSkills());

        saveDataJob(jobs, "jobs.txt");
    } else {
        cout << "Job was not found to change." << endl;
    }
}

int main(int argc, char *argv[]) // g++ -Wall -o p app1.cpp
{
    vector<Job> jobs = loadJobs("jobs.txt");

    if (argc < 2) {
        cout << "Commands:" << endl;
        cout << "  adaugare_job <id> <nume companie> <pozitia> <experienta> <skill> " << endl;
        cout << "  modificare_job <id> <nume|pozitia|skill|experienta> <valoarea_corespunzatoare>" << endl;
        cout << "  stergere_job <id>" << endl;
        cout << "  vizualizare_candidati <job id>" << endl;
        return 1;
    }

    string command = argv[1];

    if (command == "adaugare_job" && argc >= 7) { // ex: .\p.exe adaugare_job 1 Theranos cto 7 management c++ communication
        // TODO: validate the input
        int id = stoi(argv[2]);
        string compania = argv[3];
        string pozitia = argv[4];
        int experienta = stoi(argv[5]);
        vector<string> skills;

        for (int i = 6; i < argc; ++i) {
            skills.push_back(argv[i]);
        }

        adaugare_job(jobs, id, compania, pozitia, experienta, skills);
    } else if (command == "modificare_job" && argc >= 5) {
        modificare_job(jobs, stoi(argv[2]), argv[3], argv[4]);
    }
    else if (command == "stergere_job" && argc == 3) {
        stergere_job(jobs, stoi(argv[2]), 1);
    } else if (command == "apply_job" && argc == 4) {

    } else {
        cout << "Invalid command or arguments." << endl;
    }




    return 0;
}
