#ifndef ATOM_H
#define ATOM_H

#include "atomic_formula.h"

class Atom : public AtomicFormula
{
public:
    Atom(unsigned p);
    virtual std::ostream& print(std::ostream &out) const;
    virtual bool equalTo(const Formula &f) const;
    virtual void getAtoms(AtomSet &aSet) const;
    virtual bool eval(const Valuation &val) const;
    virtual LiteralListList listDNF() const;
    virtual LiteralListList listCNF() const;
private:
    unsigned m_p;
};

#endif // ATOM_H
