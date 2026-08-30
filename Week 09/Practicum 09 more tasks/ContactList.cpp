#include <print>
#include <vector>
#include <string>

constexpr std::string DEFAULT_NAME = "NO_NAME";
constexpr std::string DEFAULT_PHONE = "NO_PHONE";

class Contact {
    std::string name;
    std::string phone;

public:
    Contact() : name(DEFAULT_NAME), phone(DEFAULT_PHONE) {}

    Contact(const std::string& _name, const std::string& _phone) : name(_name), phone(_phone) {}

    const std::string& getName() const {
        return this->name;
    }

    const std::string& getPhone() const {
        return this->phone;
    }
};

class ContactList {
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& newContact) {
        contacts.push_back(newContact);
    }

    void findContact(const std::string& name) const {
        for (size_t i = 0; i < contacts.size(); i++) {
            if (contacts[i].getName() == name) {
                println("name: {}   phone: {}", contacts[i].getName(), contacts[i].getPhone());
                return;
            }
        }

        println("Contact with the given name was not found!");
    }

    void printAll() const {
        if (contacts.size() == 0) {
            println("No contacts!");
            return;
        }

        for (size_t i = 0; i < contacts.size(); i++) {
            println("name: {}   phone: {}", contacts[i].getName(), contacts[i].getPhone());
        }
    }
};
