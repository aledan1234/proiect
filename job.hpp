#ifndef JOB_MANAGEMENT_HPP
#define JOB_MANAGEMENT_HPP

#include <vector>
#include <string>

struct Job {
    int id;
    std::string title;
    std::vector<std::string> skills;
};

struct Application {
    int jobId;
    std::string applicantName;
};

std::vector<Job> loadJobs(const std::string& filename);

void displayJobs(const std::vector<Job>& jobs);

std::vector<Job> filterJobsBySkill(const std::vector<Job>& jobs, const std::string& skill);

void applyForJob(const std::string& filename, int jobId, const std::string& applicantName);

#endif
