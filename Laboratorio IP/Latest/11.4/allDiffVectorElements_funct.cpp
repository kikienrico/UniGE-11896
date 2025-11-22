#include "allDiffVectorElements_funct.h"

bool allDiffVectorElements(const std::vector<int> &t) {

    for(size_t i = 0; i < t.size(); i++) {
        for(size_t j = i+1; j < t.size(); j++) {
            if (t[i]==t[j]) return false;
        }
    }

    return true;
}