//
// Created by Jacob Corcho on 10/7/21.
//

#include "Address.h"

#include <utility>

// Getters

int Address::GetID() const {
    return id;
}

std::string Address::GetStreet() {
    return street;
}

std::string Address::GetApt() {
    return apt;
}

std::string Address::GetState() {
    return state;
}

int Address::GetZip() const {
    return zip;
}

// Setters

void Address::SetID(int id_input) {
    id = id_input;
}

void Address::SetStreet(std::string street_input) {
    street = std::move(street_input);
}

void Address::SetAPT(std::string apt_input) {
    apt = std::move(apt_input);
}

void Address::SetState(std::string state_input) {
    state = std::move(state_input);
}

void Address::SetZip(int zip_input) {
    zip = zip_input;
}

Address::Address(int idArg, std::string streetArg, std::string aptArg, std::string stateArg, int zipArg) {
    id = idArg;
    street = std::move(streetArg);
    apt = std::move(aptArg);
    state = std::move(stateArg);
    zip = zipArg;
}

Address::Address() = default;
