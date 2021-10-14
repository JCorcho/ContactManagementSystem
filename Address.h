//
// Created by Jacob Corcho on 10/7/21.
//

#ifndef CONTACTMANAGEMENT_ADDRESS_H
#define CONTACTMANAGEMENT_ADDRESS_H

#include <iostream>
class Address {

private:
    int id{};
    std::string street;
    std::string apt;
    std::string state;
    int zip{};

public:
    // Constructors
    Address(int idArg, std::string streetArg,std::string aptArg,std::string stateArg, int zipArg);
    Address();

    // Getters
    int GetID() const;
    std::string GetStreet();
    std::string GetApt();
    std::string GetState();
    int GetZip() const;

    // Setters
    void SetID(int id_input);
    void SetStreet(std::string street_input);
    void SetAPT(std::string apt_input);
    void SetState(std::string state_input);
    void SetZip(int zip_input);

};


#endif //CONTACTMANAGEMENT_ADDRESS_H
