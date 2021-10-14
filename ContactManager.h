//
// Created by Jacob Corcho on 10/12/21.
//

#pragma once

#include "Contact.h"
#include "FileManager.h"
#include <vector>

class ContactManager {
public:
    void Start();
    void CreateContact();
    static void DisplayContact(Contact c);
    void DisplayContacts();
    long GetSize();
    Contact GetContact(int id);
    FileManager fm;
private:
    void RefreshContacts();
    std::vector<Contact> liveContacts;
};

