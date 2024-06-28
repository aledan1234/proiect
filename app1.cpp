#include <iostream>
#include <vector>
#include <fstream>
#include "./shared/classes/jobs.cpp"
#include "./shared/classes/candidat.cpp"
using namespace std;

void saveData(){

}

vector<Job> loadJobs(const string& filename) {
    vector<Job> jobs;
    ifstream file(filename);

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

int main(int argc, char *argv[]) // g++ -Wall -o p app1.cpp
{
    vector<Job> jobs = loadJobs("jobs.txt");

    if (argc < 2) {
        cout << "Commands:" << endl;
        cout << "  add_jobs" << endl;
        cout << "  modify_job <skill>" << endl;
        cout << "  delete <job_id>" << endl;
        cout << "  job_candidates <job_id>" << endl;
        return 1;
    }

    string command = argv[1];

    if (command == "view_jobs") {

    } else if (command == "filter_jobs" && argc == 3) {

    } else if (command == "apply_job" && argc == 4) {

    } else {
        cout << "Invalid command or arguments." << endl;
    }



    saveData();

    return 0;
}
