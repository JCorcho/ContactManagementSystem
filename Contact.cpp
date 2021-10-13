//
// Created by Jacob Corcho on 10/7/21.
//

#include "Contact.h"

#include <utility>
#include "Address.h"

// Getters

long Contact::GetID() const {
    return id;
}

long Contact::GetCPhone() const {
    return cPhone;
}

long Contact::GetHPhone() const {
    return hPhone;
}

std::string Contact::GetFirst() {
    return first;
}

std::string Contact::GetLast() {
    return last;
}

Address Contact::GetAddress() {
    return address;
}

// Setters

void Contact::SetID(long id_input) {
    id = id_input;
}

void Contact::SetFirst(std::string first_input) {
    first = std::move(first_input); // move as to not make redundant copies
}

void Contact::SetLast(std::string last_input) {
    last = std::move(last_input);
}

void Contact::SetCPhone(long num) {
    cPhone = num;
}

void Contact::SetHPhone(long num) {
    hPhone = num;
}

Contact::Contact(long idArg, std::string firstArg, std::string lastArg, Address addressArg, long cPhoneArg, long hPhoneArg) {
    id = idArg;
    first = std::move(firstArg);
    last = std::move(lastArg);
    address = std::move(addressArg);
    cPhone = cPhoneArg;
    hPhone = hPhoneArg;
}


