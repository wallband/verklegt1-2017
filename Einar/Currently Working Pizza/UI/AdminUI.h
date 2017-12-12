#ifndef ADMINUI_H
#define ADMINUI_H
#include "AdminService.h"
#include "FileNotFound.h"
#include "iostream"
#include <typeinfo>


class AdminUI
{
    public:
        AdminUI();
        void startUI();

    private:
        AdminService adminservice;
};

#endif // ADMINUI_H
