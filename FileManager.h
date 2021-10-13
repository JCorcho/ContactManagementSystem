//
// Created by Jacob Corcho on 10/11/21.
//

#pragma once

#include "Contact.h"
#include <vector>
#include <fstream>

class FileManager {

public:
    void Open(std::ios_base::openmode mode);
    void Close();
    void SaveInput(bool final = false);
    void ConfigureSettings();
    const std::vector<Contact> & ParseContactsFromFile();
    std::fstream db; // db object
private:
    static Contact ParseContact(std::string data, int index);

    static Address ParseAddress(std::vector<std::string> data);
    std::vector<Contact> contacts{};
    std::string tempInput;

    std::string dbFileLocation;

};


