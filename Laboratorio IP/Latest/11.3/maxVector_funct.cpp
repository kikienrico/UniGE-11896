#include "maxVector.h"

using namespace std;

int maxVector(const std::vector<int>& v) {
    string e="ERROR: vector size = 0";
    if (v.size()==0) throw e;

    int max=v[0];
    for(int i = 1; i < v.size(); i++) {
        if (max<v[i]) max=v[i];
    }

    return max;
}