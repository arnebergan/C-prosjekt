#include "fil.h"

void Fil::addNerds(const string& username, const double& time){
    results_with_nerds.insert({username, time}); //
    results_with_nerds.at(username) = time; // update to better time
}

void Fil::removeNerds(const string& username){
    results_with_nerds.erase(username);
}

double Fil::getNerds(const string& username) const{
    return results_with_nerds.at(username);
}

void Fil::saveToFile (const string& filename){
    ofstream outFile(filename);
    if (!outFile){
        cout << "You didn't open the file...";
        return;
    }
    for (const auto & result : results_with_nerds){
        outFile << result.first << ": " << result.second << endl;
    }
    outFile.close();
}


ostream& operator<<(ostream& os, const Fil& ff){
    for (const auto& f : ff.results_with_nerds){
        os << f.first << ": " << f.second << endl;
    }
    return os;
}
