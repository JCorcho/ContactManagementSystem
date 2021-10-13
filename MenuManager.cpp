//
// Created by Jacob Corcho on 10/12/21.
//

#pragma once

#include "MenuManager.h"
#include <iostream>

void MenuManager::LaunchUI() {
    cm.Start();

    std::cout << "*******************************" << std::endl;
    std::cout << "*  CONTACT MANAGEMENT SYSTEM  *" << std::endl;
    std::cout << "*******************************" << std::endl;

    while(true) {
        // todo catch invalid inputs
        std::cout << "Please select from the following..." << std::endl;
        std::cout << "(1). Contact List  (2). Search Contacts (3). Create Contact (4). Exit" << std::endl;
        std::cin >> tempInput;
        std::cin.ignore();

        if (tempInput == 1) {
            cm.DisplayContacts();
        } else if (tempInput == 2) {
            LaunchSearch();
        } else if (tempInput == 3) {
            cm.CreateContact();
        } else if (tempInput == 4) {
            cm.fm.Close();
            exit(0);
        }
    }
}

void MenuManager::LaunchSearch() {
    std::cout << "*********************" << std::endl;
    std::cout << "*  SEARCH CONTACTS  *" << std::endl;
    std::cout << "*********************" << std::endl;

    while(true) {
        // todo catch invalid inputs
        int searchIndex;
        std::cout << "(1). Enter contact ID (2). '-1' to go back" << std::endl;
        std::cin.ignore();
        std::cin >> searchIndex;
        if(searchIndex == -1)
            break;

        ContactManager::DisplayContact(cm.GetContact(searchIndex));
    }
}

