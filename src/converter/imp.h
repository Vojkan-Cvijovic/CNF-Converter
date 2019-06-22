#ifndef IMP_H
#define IMP_H

#include "binary_connective.h"
#include "constant.h"

class Imp : public BinaryConnective
{
public:
    Imp(const Formula &op1, const Formula &op2);
    virtual std::string symbol() const;
    virtual Formula substitute(const Formula &what, const Formula &with) const;
    virtual bool eval(const Valuation &val) const;
    virtual Formula simplify() const;
    virtual Formula nnf() const;
    virtual LiteralListList listDNF() const;
    virtual LiteralListList listCNF() const;
};

#endif // IMP_H
