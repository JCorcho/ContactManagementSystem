//
// Created by Jacob Corcho on 10/7/21.
//

#pragma once

#include <iostream>
#include <utility>
#include "Address.h"

class Contact {

public:
    // Constructors
    Contact(long idArg, std::string firstArg, std::string lastArg, Address addressArg, long cPhoneArg, long hPhoneArg);

    // Getters
    long GetID() const;
    long GetCPhone() const;
    long GetHPhone() const;
    std::string GetFirst();
    std::string GetLast();
    Address GetAddress();

    // Setters
    void SetID(long id_input);
    void SetFirst(std::string first_input);
    void SetLast(std::string last_input);
    void SetCPhone(long num);
    void SetHPhone(long num);

private:
    long id; // unique identifier
    std::string first; // users first name
    std::string last; // users last name
    Address address; // address object
    long cPhone; // cellphone number

    long hPhone; // home phone number

};
