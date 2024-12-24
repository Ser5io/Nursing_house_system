#pragma once

#include <iostream>
using namespace std;

class HealthFile
{
public:
    string residentName;
    string medicalHistory;
    string allergies;
    string medications;
    string vitalStats;

    HealthFile();
    void addHealthinfo();
    void displayHealthInfo();
};

