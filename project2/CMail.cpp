// project2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "CMail.h"

int CMail::count = 0;

CMail::CMail()
    : country(""), index(""), region(""), area(""),
    locality(""), street(""), home(""), flat(""), placeType(0)
{
    count++;
}

CMail::CMail(const std::string& country,
    const std::string& index,
    const std::string& region,
    const std::string& area,
    const std::string& locality,
    const std::string& street,
    const std::string& home,
    const std::string& flat,
    int placeType)
    : country(country), index(index), region(region), area(area),
    locality(locality), street(street), home(home), flat(flat),
    placeType(placeType)
{
    count++;
}

CMail::CMail(const CMail& other)
    : country(other.country), index(other.index),
    region(other.region), area(other.area),
    locality(other.locality), street(other.street),
    home(other.home), flat(other.flat), placeType(other.placeType)
{
    count++;
}

std::string CMail::getCountry() const { return country; }
std::string CMail::getIndex() const { return index; }
std::string CMail::getRegion() const { return region; }
std::string CMail::getArea() const { return area; }
std::string CMail::getLocality() const { return locality; }
std::string CMail::getStreet() const { return street; }
std::string CMail::getHome() const { return home; }
std::string CMail::getFlat() const { return flat; }
int CMail::getPlaceType() const { return placeType; }

std::string CMail::info() const {
    std::string type = placeType == 1 ? "Город" :
        placeType == 2 ? "Сельская местность" :
        "Не указано";

    return "Страна: " + country +
        "; Индекс: " + index +
        "; Область: " + region +
        "; Район: " + area +
        "; Населенный пункт: " + locality +
        "; Улица: " + street +
        "; Дом: " + home +
        "; Квартира: " + flat +
        "; Тип местности: " + type;
}

bool CMail::operator==(const CMail& other) const {
    return country == other.country &&
        index == other.index &&
        region == other.region &&
        area == other.area &&
        locality == other.locality &&
        street == other.street &&
        home == other.home &&
        flat == other.flat &&
        placeType == other.placeType;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
