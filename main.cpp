#include <iostream>
#include <locale>
#include <string>
#include "Chat.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    Chat chat;
    std::string choice;
    std::string log;
    std::string pass;
    while (true)
    {
        std::cout << "1 - Регистрация" << std::endl;
        std::cout << "2 - Авторизация" << std::endl;
        std::cout << "3 - Тест хештаблицы(показать содержимое)" << std::endl;
        std::cout << "0 - Выйти из программы" << std::endl;
        std::cin >> choice;
        if (choice == "0")
        {
            break;
        }
        else if (choice == "3")
        {
            chat.test();
            std::cout << std::endl;
            continue;
        }
        std::cout << "Логин: ";
        std::cin >> log;
        std::cout << "Пароль: ";
        std::cin >> pass;
        if (choice == "1")
        {
            chat.reg(log, pass);
        }
        else if (choice == "2")
        {
            bool flag = chat.login(log, pass);
            if (flag == true)
            {
                std::cout << "Авторизация прошла успешно" << std::endl;
            }
            else
            {
                std::cout << "Неверный логин или пароль" << std::endl;
            }
        }
    }
    return 0;
}