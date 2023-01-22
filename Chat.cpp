#include <iostream>
#include "Chat.h"

Chat::Chat()
{
    logins = new HashTable();
    passwords = new HashTable();
}

Chat::~Chat()
{
    delete logins;
    delete passwords;
}

void Chat::reg(std::string & login, std::string & password)
{
   logins->add(login);
   passwords->add(password);
}

bool Chat::login(std::string & login, std::string & password)
{
    bool flag = false;
    int log = logins->find(login);
    int pass = passwords->find(password);
    if (log != -1 && pass != -1)
    {
        flag = true;
    }
    return flag;
}

void Chat::test()
{
    size_t size = passwords->getSize();
    std::cout << "Пароли: " << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << i << " - ";
        if (passwords->getData(i) == nullptr)
        {
            std::cout << "Пустой ";
        }
        else
        {
            std::cout << passwords->getData(i)->value;
            if (passwords->getData(i)->next != nullptr)
            {
                std::cout << " - В списке: ";
                ChainNode* ptr = passwords->getData(i)->next; 
                while (true)
                {
                    if (ptr == nullptr)
                    {
                        break;
                    }
                    std::cout << ptr->value << " ";
                    ptr = ptr->next;
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Логины: " << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << i << " - ";
        if (logins->getData(i) == nullptr)
        {
            std::cout << "Пустой ";
        }
        else
        {
            std::cout << logins->getData(i)->value;
            if (logins->getData(i)->next != nullptr)
            {
                std::cout << " - В списке: ";
                ChainNode* ptr = logins->getData(i)->next; 
                while (true)
                {
                    if (ptr == nullptr)
                    {
                        break;
                    }
                    std::cout << ptr->value << " ";
                    ptr = ptr->next;
                }
            }
        }
        std::cout << std::endl;
    }
}