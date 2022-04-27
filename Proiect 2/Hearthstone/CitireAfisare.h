#include <bits/stdc++.h>

#ifndef CITIRE_AFISARE_H
#define CITIRE_AFISARE_H

class CitireAfisare{
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) const = 0;
};

#endif // CITIRE_AFISARE_H
