#ifndef IO_H
#define IO_H

#include <iostream>

using namespace std;

class IO{
public:
    virtual istream& read(istream&) = 0;
    virtual ostream& write(ostream&) const = 0;

    virtual ~IO(){ cout << "IO destroyed!\n"; }
};

#endif // IO_H
