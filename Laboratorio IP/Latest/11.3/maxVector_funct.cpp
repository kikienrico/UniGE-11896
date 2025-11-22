#include "maxVector.h"

using namespace std;

int maxVector(const std::vector<int>& t) {
    string e="ERROR: vector size = 0";
    if (t.size()==0) throw e;

    int max=t[0];
    for(size_t i = 1; i < t.size(); i++) {
        if (max<t[i]) max=t[i];
    }

    return max;
}