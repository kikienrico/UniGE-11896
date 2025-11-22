#include "vectorIncludedInVector_funct.h"

bool vectorIncludedInVector(const std::vector<int> &t1, const std::vector<int> &t2) {
    if (t1.size()==0) return true;

    int counter=0;

    for(size_t i = 0; i < t2.size(); i++) {
        for(size_t j = i+1; j < t2.size(); j++) {
            if (t1[i]==t2[j]) {
                counter++;
                break;
            }
        }
    }

    if (counter==t1.size()) return true;
    
    return false;
    
}