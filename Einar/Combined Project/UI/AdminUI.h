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
    void startUI();
    void ui_Header();

private:
    AdminService adminservice;
};

#endif // ADMINUI_H
