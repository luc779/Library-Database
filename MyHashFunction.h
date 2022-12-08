#include "Customer.h"

class MyHashFunction {
public:
    bool operator()(const Customer& cust) const {
        return cust.getID();
    }
};