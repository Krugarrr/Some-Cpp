#ifndef INC_2LABCPP_CURRENCYMANAGER_H
#define INC_2LABCPP_CURRENCYMANAGER_H

#include "curl/curl.h"
#include "../nlohmann/json.hpp"
#include "../CurrencyObject/Currency.h"
#include "../include/simple_include.h"



class CurrencyManager {
private:
    std::map<std::string, Currency> currency_manager;

public:
    void request();
    void print();
    void start(int interval);
    static void is_changed(Currency currency);
    static size_t write_data(char *ptr, size_t size, size_t nmember, std::string* data);
};


#endif //INC_2LABCPP_CURRENCYMANAGER_H
