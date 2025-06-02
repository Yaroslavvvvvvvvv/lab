#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Phone {
private:
    string lastName;
    string firstName;
    string middleName;
    string address;
    string number;
    double localTalkTime;
    double longDistanceTalkTime;

public:

    Phone(string ln = "", string fn = "", string mn = "", string addr = "", string num = "",
          double local = 0, double longDist = 0)
        : lastName(ln), firstName(fn), middleName(mn), address(addr),
          number(num), localTalkTime(local), longDistanceTalkTime(longDist) {}

    void set(string ln, string fn, string mn, string addr, string num,
             double local, double longDist) {
        lastName = ln;
        firstName = fn;
        middleName = mn;
        address = addr;
        number = num;
        localTalkTime = local;
        longDistanceTalkTime = longDist;
    }


    string getLastName() const { return lastName; }
    double getLocalTalkTime() const { return localTalkTime; }
    double getLongDistanceTalkTime() const { return longDistanceTalkTime; }

    void show() const {
        cout << "--------------------------------------\n";
        cout << "ПІБ: " << lastName << " " << firstName << " " << middleName << endl;
        cout << "Адреса: " << address << endl;
        cout << "Номер: " << number << endl;
        cout << "Час внутрішньоміських розмов: " << localTalkTime << " хв\n";
        cout << "Час міжміських розмов: " << longDistanceTalkTime << " хв\n";
        cout << "--------------------------------------\n";
    }
};

bool compareByLastName(const Phone& a, const Phone& b) {
    return a.getLastName() < b.getLastName();
}

int main() {
    const double localLimit = 30.0;
    vector<Phone> subscribers = {
        Phone("Іваненко", "Іван", "Іванович", "вул. Лесі Українки, 5", "0931234567", 45.5, 0.0),
        Phone("Петренко", "Петро", "Петрович", "вул. Шевченка, 10", "0987654321", 25.0, 15.5),
        Phone("Сидоренко", "Олена", "Іванівна", "вул. Грушевського, 3", "0501122334", 10.0, 0.0),
        Phone("Андрієнко", "Андрій", "Андрійович", "вул. Франка, 8", "0973344556", 60.0, 5.0)
    };

    cout << "\nА) Абоненти з перевищеним лімітом внутрішньоміських розмов:\n";
    for (const auto& sub : subscribers) {
        if (sub.getLocalTalkTime() > localLimit) {
            sub.show();
        }
    }

    cout << "\nБ) Абоненти, які користувалися міжміським зв’язком:\n";
    for (const auto& sub : subscribers) {
        if (sub.getLongDistanceTalkTime() > 0) {
            sub.show();
        }
    }

    cout << "\nВ) Абоненти в алфавітному порядку:\n";
    sort(subscribers.begin(), subscribers.end(), compareByLastName);
    for (const auto& sub : subscribers) {
        sub.show();
    }

    return 0;
}
