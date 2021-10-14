//
// Created by Jacob Corcho on 10/12/21.
//

#include "ContactManager.h"
#include <iostream>

void ContactManager::Start() {
    fm.ConfigureSettings();
    RefreshContacts();
}

void ContactManager::RefreshContacts() {
    liveContacts = fm.ParseContactsFromFile();
}

void ContactManager::DisplayContact(Contact c) {
    std::cout << "(" << c.GetID() << "). ";
    std::cout << c.GetFirst() << " " << c.GetLast() << std::endl;
    std::cout << "     " << c.GetAddress().GetStreet() << ", ";
    if(!c.GetAddress().GetApt().empty()) { std::cout << c.GetAddress().GetApt() << std::endl; } else { std::cout << "\n";}
    std::cout << "     " << c.GetAddress().GetState() << ",  " << c.GetAddress().GetZip() << std::endl;
    std::cout << "     " << c.GetCPhone() << " | " << c.GetHPhone() << std::endl;
}

void ContactManager::DisplayContacts() {
    RefreshContacts();
    for (const Contact& curContact: liveContacts) {
        DisplayContact(curContact);
    }
}

void ContactManager::CreateContact() {
    // todo throw http status calls for DB implementation
    // todo make function for error couts
    fm.Open(std::ios_base::app);
    std::string temp;
    if(!fm.db.is_open())
        std::cout << "file is not Open";

    fm.db << "\n"; // todo only if prev contact/line exists in db

    std::cout << "(1). Contact Name" << std::endl;
    std::cout << " - First: " << std::endl;
    std::getline(std::cin, temp);
    fm.SaveInput(temp);
    std::cout << " - Last: " << std::endl;
    std::getline(std::cin, temp);
    fm.SaveInput(temp);
    std::cout << "(2). Address" << std::endl;
    std::cout << " - Street: " << std::endl;
    std::getline(std::cin, temp);
    fm.SaveInput(temp);
    std::cout << " - Apartment | Address 2:" << std::endl;
    std::getline(std::cin, temp);
    fm.SaveInput(temp);
    std::cout << " - State: " << std::endl;
    std::getline(std::cin, temp);
    fm.SaveInput(temp);
    while(true) {
        try {
            std::cout << " - Zip Code:" << std::endl;
            std::getline(std::cin, temp);
            std::stoi(temp);
            if(temp.length() <= 10) { // <-- the world's longest zip code as of 2021 is 10 digits so if it exceeds it's probably not valid
                fm.SaveInput(temp);
                break;
            }
        } catch (...) {
            std::cout << "\x1b[31m" << " - [ERROR]: " << temp << " is not a valid zip code of Earth. \x1b[34m  \n";
            std::cout << '\a';
        }
    }

    std::cout << "(3). Contact Information" << std::endl;
    while(true) {
        try {
            std::cout << " - Cell Phone Number: " << std::endl;
            std::getline(std::cin, temp);
            std::stol(temp);
            fm.SaveInput(temp);
            break;

        } catch (...) {
            std::cout << "\x1b[31m" << " - [ERROR]: " << temp << " is not a valid phone number. \x1b[34m  \n";
            std::cout << '\a';
        }
    }
    while(true) {
        try {
            std::cout << " - Home Phone Number: " << std::endl;
            std::getline(std::cin, temp);
            std::stol(temp);
            fm.SaveInput(temp);
            break;

        } catch (...) {
            std::cout << "\x1b[31m" << " - [ERROR]: " << temp << " is not a valid phone number. \x1b[34m  \n";
            std::cout << '\a';
        }
    }
    std::cout << " - Email Address: " << std::endl;
    while(true) {
        std::getline(std::cin, temp);
        if(temp.length() <= 320) { // <-- world's longest email address as of 2021 is 320 characters
            fm.SaveInput(temp, true);
            break;
        }

        std::cout << "\x1b[31m" << " - [ERROR]: " << temp << " is not a valid email address | limit 320 characters. \x1b[34m  \n";
        std::cout << '\a';

    }
    fm.Close();
}

Contact ContactManager::GetContact(int id) {
    return liveContacts[id];
}

long ContactManager::GetSize() {
    return liveContacts.size();
}


