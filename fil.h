#pragma once
#include "std_lib_facilities.h"


class Fil {

    private:
    
    public:
    map<string, double> results_with_nerds;

    void addNerds(const string& username, const double& time);
    void removeNerds(const string& username);
    double getNerds(const string& username) const;

    void saveToFile(const string& filename);
    void loadFromFile(); 

    friend ostream& operator<<(ostream os, const Fil& ff);
};

