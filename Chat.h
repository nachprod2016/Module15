#pragma once
#include <string>
#include "HashTable.h"


class Chat 
{
public:
    Chat();
    ~Chat();
    void reg(std::string & login, std::string & pass);
    bool login(std::string & login, std::string & pass);
    void test();
private:
    HashTable* logins;
    HashTable* passwords;
};