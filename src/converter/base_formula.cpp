#include "base_formula.h"

BaseFormula::BaseFormula(){

}

void BaseFormula::getAtoms(AtomSet &aSet) const
{
    UNUSED_VARIABLE(aSet);
}

bool BaseFormula::equalTo(const Formula &f) const
{
    const BaseFormula *base = f.get();
    return typeid (*this) == typeid (*base);
}

bool operator==(const Formula &lhs, const Formula &rhs)
{
    return lhs->equalTo(rhs);
}

std::ostream& operator<<(std::ostream &out, const Formula &f)
{
    return f->print(out);
}

std::ostream & operator << (std::ostream & out, const LiteralListList & l)
{
  out << "[ ";
  for(auto & ll :  l)
    {
      out << "[ ";
      for(auto & f : ll)
    {
      out << f << " ";
    }
      out << "] ";
    }
  out << " ]";

  return out;
}

BaseFormula::~BaseFormula()
{

}

OptionalValuation BaseFormula::isSatisfiable() const
{
    AtomSet aset;
    getAtoms(aset);
    Valuation val{aset};
    do {
        if(eval(val)){
            return std::move(val);
        }
    } while(val.next());
    return {};
}

OptionalValuation BaseFormula::isNotTautology() const{
    AtomSet aset;
    getAtoms(aset);
    Valuation val{aset};
    do{
        if(!eval(val)){
            return std::move(val);
        }
    } while(val.next());
    return {};
}

void BaseFormula::printTruthTable(std::ostream &out) const{
    AtomSet aset;
    getAtoms(aset);
    Valuation val{aset};
    out << std::noboolalpha;
    do {
        out << val << "|" << eval(val) << "\n";
    } while(val.next());
}

bool BaseFormula::isEquivalent(const Formula &f) const{
    AtomSet aset;
    getAtoms(aset);
    f->getAtoms(aset);
    Valuation val{aset};
    do{
        if(eval(val) != f->eval(val)){
            return false;
        }
    } while(val.next());
    return true;
}

LiteralListList BaseFormula::cross(const LiteralListList &l1, const LiteralListList &l2)
{
    LiteralListList result;
    result.reserve(l1.size() * l2.size());
    for (const auto& outerL : l1) {
        for (const auto& innerL : l2){
            result.push_back(concatenate(outerL, innerL));
        }
    }

    return result;
}

