#include "atom.h"

Atom::Atom(unsigned p)
  : AtomicFormula (), m_p(p)
{}

std::ostream &Atom::print(std::ostream &out) const
{
    return out << "p" << m_p;
}

bool Atom::equalTo(const Formula &f) const
{
    if(BaseFormula::equalTo(f)){
        const Atom* pF = static_cast<const Atom *>(f.get());
        return m_p == pF->m_p;
    }
    return false;
}

void Atom::getAtoms(AtomSet &aSet) const
{
    aSet.insert(m_p);
}

bool Atom::eval(const Valuation &val) const
{
    return val.value(m_p);
}

LiteralListList Atom::listDNF() const
{
    return {{std::const_pointer_cast<BaseFormula>(shared_from_this())}};
}

LiteralListList Atom::listCNF() const
{
    return {{std::const_pointer_cast<BaseFormula>(shared_from_this())}};
}

