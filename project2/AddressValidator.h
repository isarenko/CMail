#pragma once
#include <vector>
#include <string>
#include "CMail.h"

class AddressValidator {
public:
    static std::vector<std::string> validate(const CMail& mail);
};
