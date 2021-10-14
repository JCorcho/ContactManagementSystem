//
// Created by Jacob Corcho on 10/12/21.
//

#pragma once

#include "MenuManager.h"
#include <iostream>

void MenuManager::LaunchUI() {
    cm.Start();
    std::cout << "\x1b[34m";

    std::cout << "*******************************" << std::endl;
    std::cout << "*  CONTACT MANAGEMENT SYSTEM  *" << std::endl;
    std::cout << "*******************************" << std::endl;

    while(true) {
        // todo catch invalid inputs
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Please select from the following..." << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "(1). Contact List  (2). Search Contacts (3). Create Contact (4). Exit" << std::endl;
        std::cin >> tempInput;
        std::cin.ignore();

        if (tempInput == 1) {
            std::cout << "------------------------------" << std::endl;
            std::cout << "|        Contact List        |" << std::endl;
            std::cout << "------------------------------" << std::endl;
            cm.DisplayContacts();
        } else if (tempInput == 2) {
            std::cout << "---------------------" << std::endl;
            std::cout << "|  SEARCH CONTACTS  |" << std::endl;
            std::cout << "---------------------" << std::endl;
            LaunchSearch();
        } else if (tempInput == 3) {
            std::cout << "-------------------------------" << std::endl;
            std::cout << "|        Create Contact        |" << std::endl;
            std::cout << "-------------------------------" << std::endl;
            cm.CreateContact();
        } else if (tempInput == 4) {
            cm.fm.Close();
            std::cout << "*************" << std::endl;
            std::cout << "*  GOODBYE  *" << std::endl;
            std::cout << "*************" << std::endl;
            exit(0);
        }
    }
}

void MenuManager::LaunchSearch() {
    while(true) {
        int searchIndex;
        std::cout << "(1). Enter contact ID (2). '-1' to go back" << std::endl;
        std::cin.ignore();
        std::cin >> searchIndex;

        if(searchIndex == -1)
            break;

        if(searchIndex < 0 || searchIndex > cm.GetSize() - 1) {
            std::cout << "\x1b[31m" << " - [ERROR]: " << searchIndex << " does not exist! try using a different ID\x1b[34m  \n";
            std::cout << '\a';
        } else {
            ContactManager::DisplayContact(cm.GetContact(searchIndex));
        }
    }
}


