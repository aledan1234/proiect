#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    string title;
    vector<string> skills;
};

struct Application {
    int jobId;
    string applicantName;
};

// Funcții
vector<Job> loadJobs(const string& filename) {
    vector<Job> jobs;
    ifstream file(filename);
    if (file.is_open()) {
        int id;
        string title;
        int numSkills;
        while (file >> id >> title >> numSkills) {
            Job job;
            job.id = id;
            job.title = title;
            for (int i = 0; i < numSkills; ++i) {
                string skill;
                file >> skill;
                job.skills.push_back(skill);
            }
            jobs.push_back(job);
        }
        file.close();
    }
    return jobs;
}

void displayJobs(const vector<Job>& jobs) {
    for (const auto& job : jobs) {
        cout << "Job ID: " << job.id << ", Title: " << job.title << ", Skills: ";
        for (const auto& skill : job.skills) {
            cout << skill << " ";
        }
        cout << endl;
    }
}

vector<Job> filterJobsBySkill(const vector<Job>& jobs, const string& skill) {
    vector<Job> filteredJobs;
    for (const auto& job : jobs) {
        if (find(job.skills.begin(), job.skills.end(), skill) != job.skills.end()) {
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

// Funcția principală
int main() {
    vector<Job> jobs = loadJobs("jobs.txt");

    int choice;
    while (true) {
        cout << "1. View all jobs" << endl;
        cout << "2. Filter jobs by skill" << endl;
        cout << "3. Apply for a job" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayJobs(jobs);
        } else if (choice == 2) {
            string skill;
            cout << "Enter skill to filter by: ";
            cin >> skill;
            vector<Job> filteredJobs = filterJobsBySkill(jobs, skill);
            displayJobs(filteredJobs);
        } else if (choice == 3) {
            int jobId;
            string applicantName;
            cout << "Enter Job ID to apply for: ";
            cin >> jobId;
            cout << "Enter your name: ";
            cin >> applicantName;
            applyForJob("applications.txt", jobId, applicantName);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
