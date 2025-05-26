#include <iostream>
#include <string>
#include <vector>

class PostalAddress {
private:
    std::string _index;
    std::string _country;
    std::string _city;
    std::string _street;
    std::string _house;
    std::string _office;

    bool isValidIndex(const std::string& index) {
        if (index.empty()) {
            return true;
        }
        if (index.length() != 5) {
            return false;
        }
        for (char c : index) {
            if (c < '0' || c > '9') {
                return false;
            }
        }
        return true;
    }

public:
    PostalAddress(const std::string& index = "", const std::string& country = "",
                  const std::string& city = "", const std::string& street = "",
                  const std::string& house = "", const std::string& office = "") {
        setIndex(index);
        setCountry(country);
        setCity(city);
        setStreet(street);
        setHouse(house);
        setOffice(office);
    }

    std::string getIndex() const {
        return _index;
    }

    void setIndex(const std::string& index) {
        if (!isValidIndex(index)) {
            std::cerr << "Warning: Invalid index '" << index << "' provided. Index should be 5 digits or empty." << std::endl;
        }
        _index = index;
    }

    std::string getCountry() const {
        return _country;
    }

    void setCountry(const std::string& country) {
        _country = country;
    }

    std::string getCity() const {
        return _city;
    }

    void setCity(const std::string& city) {
        _city = city;
    }

    std::string getStreet() const {
        return _street;
    }

    void setStreet(const std::string& street) {
        _street = street;
    }

    std::string getHouse() const {
        return _house;
    }

    void setHouse(const std::string& house) {
        _house = house;
    }

    std::string getOffice() const {
        return _office;
    }

    void setOffice(const std::string& office) {
        _office = office;
    }

    std::string getFullAddress() const {
        std::vector<std::string> parts;
        if (!_index.empty()) parts.push_back(_index);
        if (!_country.empty()) parts.push_back(_country);
        if (!_city.empty()) parts.push_back(_city);
        if (!_street.empty()) parts.push_back(_street);
        if (!_house.empty()) parts.push_back(_house);
        if (!_office.empty()) parts.push_back(_office);

        std::string fullAddress = "";
        for (size_t i = 0; i < parts.size(); ++i) {
            fullAddress += parts[i];
            if (i < parts.size() - 1) {
                fullAddress += ", ";
            }
        }
        return fullAddress;
    }

    friend std::ostream& operator<<(std::ostream& os, const PostalAddress& addr) {
        return os << addr.getFullAddress();
    }
};

int main() {
    PostalAddress address1("01001", "Україна", "Київ", "Хрещатик", "1", "10");
    std::cout << "Адреса 1: " << address1 << std::endl;

    address1.setCity("Львів");
    address1.setIndex("79000");
    std::cout << "Адреса 1 (змінена): " << address1 << std::endl;

    PostalAddress address2;
    std::cout << "Адреса 2 (пуста): " << address2 << std::endl;
    address2.setCountry("Польща");
    address2.setCity("Варшава");
    address2.setStreet("Маршалковська");
    address2.setHouse("100");
    std::cout << "Адреса 2 (заповнена): " << address2 << std::endl;

    std::cout << "\nДемонстрація валідації (попередження для некоректних даних):" << std::endl;

    address1.setIndex("123");
    std::cout << "Адреса 1 (індекс '123'): " << address1 << " (Валідно? " << (address1.isValidIndex(address1.getIndex()) ? "Так" : "Ні") << ")" << std::endl;

    address1.setIndex("ABCDE");
    std::cout << "Адреса 1 (індекс 'ABCDE'): " << address1 << " (Валідно? " << (address1.isValidIndex(address1.getIndex()) ? "Так" : "Ні") << ")" << std::endl;

    return 0;
}