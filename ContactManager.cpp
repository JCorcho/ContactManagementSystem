//
// Created by Jacob Corcho on 10/12/21.
//

#pragma once
#include "ContactManager.h"

void ContactManager::Start() {
    fm.ConfigureSettings();
    RefreshContacts();
}

void ContactManager::RefreshContacts() {
    liveContacts = fm.ParseContactsFromFile();
}

void ContactManager::DisplayContact(Contact c) {
    std::cout << c.GetID() << std::endl;
    std::cout << c.GetFirst() << " " << c.GetLast() << std::endl;
    std::cout << c.GetAddress().GetStreet() << std::endl;
    std::cout << c.GetAddress().GetState() << ",  " << c.GetAddress().GetZip() << std::endl;
    std::cout << c.GetCPhone() << " | " << c.GetHPhone() << std::endl;
}

void ContactManager::DisplayContacts() {
    RefreshContacts();
    for (const Contact& curContact: liveContacts) {
        DisplayContact(curContact);
    }
}

void ContactManager::CreateContact() {
    fm.Open(std::ios_base::app);
    if(!fm.db.is_open())
        std::cout << "file is not Open";

    fm.db << "\n"; // todo only if prev contact/line exists in db

    std::cout << "-=-=-=-=-=-=-=-" << std::endl;
    std::cout << "| NEW CONTACT |" << std::endl;
    std::cout << "-=-=-=-=-=-=-=-" << std::endl;

    std::cout << std::endl;

    std::cout << "************" << std::endl;
    std::cout << "*   NAME   *" << std::endl;
    std::cout << "************" << std::endl;
    std::cout << "First: " << std::endl;
    fm.SaveInput();
    std::cout << "Last: " << std::endl;
    fm.SaveInput();

    std::cout << "***************" << std::endl;
    std::cout << "*   ADDRESS   *" << std::endl;
    std::cout << "***************" << std::endl;
    std::cout << "Street: " << std::endl;
    fm.SaveInput();
    std::cout << "Apartment | Address 2:" << std::endl;
    fm.SaveInput();
    std::cout << "State: " << std::endl;
    fm.SaveInput();
    std::cout << "Zip Code:" << std::endl;
    fm.SaveInput();

    std::cout << "********************" << std::endl;
    std::cout << "*   CONTACT INFO   *" << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "Cell Phone Number: " << std::endl;
    fm.SaveInput();
    std::cout << "Home Phone Number: " << std::endl;
    fm.SaveInput();
    std::cout << "Email Address: " << std::endl;
    fm.SaveInput(true);

    fm.Close();
}

Contact ContactManager::GetContact(int id) {
    return liveContacts[id];
}


