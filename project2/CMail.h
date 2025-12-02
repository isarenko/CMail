#pragma once
#include <string>

class CMail {
private:
    std::string country;
    std::string index;
    std::string region;
    std::string area;
    std::string locality;
    std::string street;
    std::string home;
    std::string flat;
    int placeType; // 1 - город, 2 - сельская местность

public:
    static int count;

    CMail();
    CMail(const std::string& country,
        const std::string& index,
        const std::string& region,
        const std::string& area,
        const std::string& locality,
        const std::string& street,
        const std::string& home,
        const std::string& flat,
        int placeType);

    CMail(const CMail& other);

    // Getters
    std::string getCountry() const;
    std::string getIndex() const;
    std::string getRegion() const;
    std::string getArea() const;
    std::string getLocality() const;
    std::string getStreet() const;
    std::string getHome() const;
    std::string getFlat() const;
    int getPlaceType() const;

    std::string info() const;

    bool operator==(const CMail& other) const;
};
