#include "AddressValidator.h"

std::vector<std::string> AddressValidator::validate(const CMail& m) {
    std::vector<std::string> errors;

    if (m.getCountry().empty()) errors.push_back("Страна не указана");
    if (m.getIndex().empty()) errors.push_back("Индекс не указан");
    if (m.getRegion().empty()) errors.push_back("Область не указана");
    if (m.getArea().empty()) errors.push_back("Район не указан");
    if (m.getLocality().empty()) errors.push_back("Населенный пункт не указан");
    if (m.getStreet().empty()) errors.push_back("Улица не указана");
    if (m.getHome().empty()) errors.push_back("Дом не указан");
    if (m.getFlat().empty()) errors.push_back("Квартира не указана");
    if (m.getPlaceType() == 0) errors.push_back("Тип местности не выбран");

    return errors;
}
