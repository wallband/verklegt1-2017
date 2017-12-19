#ifndef ADMINUI_H
#define ADMINUI_H
#include "AdminService.h"
#include "../EXCEPTIONS/FileNotFound.h"
#include "iostream"
#include <typeinfo>


class AdminUI
{
public:
    AdminUI();
    void startUI();         ///Starts Admin user interface
    void ui_Header();       ///Decorational header for Admin interface

private:
    AdminService adminservice;
};

#endif // ADMINUI_H
