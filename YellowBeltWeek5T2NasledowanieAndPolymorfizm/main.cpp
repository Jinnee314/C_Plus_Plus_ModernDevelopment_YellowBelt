#include <iostream>
#include "INotifier.hpp"
#include "SmsNotifier.hpp"
#include "EmailNotifier.hpp"

class Animal {
public:
    // ваш код
    Animal(const std::string name) : Name(name)
    {    }

    const std::string Name;
};


class Dog : Animal{
public:
    // ваш код
    Dog(const std::string name) : Animal(name)
    {    }

    void Bark() {
        std::cout << Name << " barks: woof!" << std::endl;
    }
};

void Notify(INotifier& notifier, const std::string& message) {
    notifier.Notify(message);
}


int main() {
    SmsNotifier sms{ "+7-495-777-77-77" };
    EmailNotifier email{ "na-derevnyu@dedushke.ru" };

    Notify(sms, "I have White belt in C++");
    Notify(email, "And want a Yellow one");
    return 0;
}