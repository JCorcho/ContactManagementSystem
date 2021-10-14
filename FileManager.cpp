//
// Created by Jacob Corcho on 10/11/21.
// small edits made by @WorldWalker 10/12/21. (helped me with the argument type for Open and Close methods)
//

#include <iostream>
#include <algorithm>
#include "FileManager.h"

void FileManager::Open(std::ios_base::openmode mode) {
    try {
        db.open(dbFileLocation, mode);
    } catch (const std::invalid_argument &e) {
        throw std::invalid_argument("could not Open file at: " + dbFileLocation);
    }
}

void FileManager::Close() {
    db.close();
}

void FileManager::SaveInput(const std::string& input, bool final) {
    db << input;
    if (!final)
        db << ",";
}

void FileManager::ConfigureSettings() {
    dbFileLocation = "/Users/jcorcho/CLionProjects/ContactManagement/database.txt";
}

const std::vector<Contact> &FileManager::ParseContactsFromFile() {
    contacts.clear(); // reset
    std::string curLine;

    int lineIndex = 0;
    Open(std::ios_base::in);

    while (getline(db, curLine)) {
        contacts.push_back(ParseContact(curLine, lineIndex));
        lineIndex++;
    }

    Close();
    return contacts;
}

Contact FileManager::ParseContact(std::string data, int index) {
    std::vector<std::string> inputs;

    // based on user283145's c++ string split algorithm
    std::string delimiter = ",";
    size_t pos;
    std::string token;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        token = data.substr(0, pos);
        inputs.push_back(token);
        data.erase(0, pos + delimiter.length());
    }
    inputs.push_back(data);

    // validation is done upon creating contact, double validation here would be redundant
    long tempCPhone = std::stol(inputs[6]);
    long tempHPhone = std::stol(inputs[7]);
    Contact dummyContact(index, inputs[0], inputs[1], ParseAddress(inputs), tempCPhone, tempHPhone);

    return dummyContact;
}

Address FileManager::ParseAddress(std::vector<std::string> data) {

    // first = 0, last = 1, street = 2, apt = 3, state = 4, zip = 5, cPhone = 6, hPhone = 7, email = 8
    int tempZip = std::stoi(data[5]);
    Address dummyAddy(0, data[2], data[3], data[4], tempZip);

    return dummyAddy;
}

