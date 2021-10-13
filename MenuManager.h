//
// Created by Jacob Corcho on 10/12/21.
//
#pragma once
#include "ContactManager.h"

class MenuManager {
public:
    void LaunchUI();
private:
    void LaunchSearch();
    int tempInput;
    ContactManager cm;

};


