#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
//#include "C:\Users\alexc\OneDrive\Desktop\shared\classes\jobs.hpp" //g++ -o app app2.cpp
#include "./shared/classes/jobs.cpp"
#include "./shared/classes/candidat.cpp"

using namespace std;

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

void displayJobs(const vector<Job>& jobs) {
    for (const auto& job : jobs) {
        cout << "Job ID: " << job.getId() << ", Company: " << job.getCompania() << ", Position: " << job.getPozitia() << ", Experienta: " << job.getExperienta() << " ani" << endl;
        cout << "Skills: ";
        for (const auto& skill : job.getSkills()) {
            cout << skill << " ";
        }
        cout << endl;
    }
}

vector<Job> filterJobsBySkill(const vector<Job>& jobs, const string& skill) { //app.exe filter_jobs C++ sau g++ -o app filter_jobs
    vector<Job> filteredJobs;
    for (const auto& job : jobs) {
        vector<string> jobSkills = job.getSkills();
        if (find(jobSkills.begin(), jobSkills.end(), skill) != jobSkills.end()) {
            filteredJobs.push_back(job);
        }
    }
    return filteredJobs;
}

void applyForJob(const string& filename, int jobId, const string& applicantName) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << jobId << " " << applicantName << endl;
        file.close();
        cout << "Application submitted successfully!" << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

int main(int argc, char* argv[]) {
    vector<Job> jobs = loadJobs("jobs.txt");

    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <command> [options]" << endl;
        cout << "Commands:" << endl;
        cout << "  view_jobs" << endl;
        cout << "  filter_jobs <skill>" << endl;
        cout << "  apply_job <job_id> <applicant_name>" << endl;
        return 1;
    }

    string command = argv[1];

    if (command == "view_jobs") {
        displayJobs(jobs);
    } else if (command == "filter_jobs" && argc == 3) {
        string skill = argv[2];
        vector<Job> filteredJobs = filterJobsBySkill(jobs, skill);
        displayJobs(filteredJobs);
    } else if (command == "apply_job" && argc == 4) {
        int jobId = stoi(argv[2]);
        string applicantName = argv[3];
        applyForJob("candidati.txt", jobId, applicantName);
    } else {
        cout << "Invalid command or arguments." << endl;
    }

    return 0;
}
