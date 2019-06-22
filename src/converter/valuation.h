#ifndef VALUATION_H
#define VALUATION_H

#include "atom_set.h"
#include <map>
#include <iostream>

class Valuation
{
public:
    Valuation(const AtomSet &aset = {});

    void reset(const AtomSet &aset);

    bool value(unsigned p) const;

    bool& value(unsigned p);

    bool next();

    std::ostream& print(std::ostream &out) const;
private:
    std::map<unsigned, bool> m_values;
};

std::ostream& operator<<(std::ostream &out, const Valuation &v);

#endif // VALUATION_H
