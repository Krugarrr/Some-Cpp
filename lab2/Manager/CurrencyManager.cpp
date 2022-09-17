#include "CurrencyManager.h"
#include "../utility/Colours.cpp"

using json = nlohmann::json;


//callback функция для записи данных при их приёме с помощью опции CURLOPT_WRITEFUNCTION.
size_t CurrencyManager::write_data(char *ptr, size_t size, size_t nmember, std::string* data) {
    //string* data - это параметр опции CURLOPT_WRITEDATA, в который производится запись - наш буфер.
    if (data) {
        data->append(ptr, size * nmember);
        return size * nmember;
    }
    else {
        throw std::logic_error("Error: empty data"); // будет ошибка
    }
}

inline void CurrencyManager::request () {
    CURL* curl_handle = curl_easy_init();
    std::string content;
    json request;

    if(curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js"); // задаем  url адрес
        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, FALSE);

        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data); //Две опции, чтобы хранить данные
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &content);       // в отдельном буффере

        CURLcode res = curl_easy_perform(curl_handle); // выполняем запрос
        if (res != CURLE_OK) {
            std::cerr << curl_easy_strerror(res) << std::endl; //поиск ошибок
        }

        request = json::parse(content);
        for (auto& valute : request["Valute"].items()) {
            currency_manager[valute.key()].add_currency((valute.value()["Value"]));
        }
        curl_easy_cleanup(curl_handle); // закрываем дескриптор curl
    }
    else {
        throw std::runtime_error("Error: something went wrong during initialise curl handle");
    }
}

void CurrencyManager::print() {
    ColourInit();
    time_t time_ = time(nullptr);
    std::string time = asctime(localtime(&time_));

    Colour(hConsole, BRIGHTWhite);
    std::cout << "\nRequest time: " << time;

    Colour(hConsole, BRIGHTCyan);
    std::cout << "___________________________________________________________" << std::endl
    << "___________________________________________________________" << std::endl;
    std::cout << std::setprecision(5);
    for (auto& currency : currency_manager) {
        Colour(hConsole, BRIGHTCyan);
        std::cout <<  "||  ";
        is_changed(currency.second);
        std::cout << currency.first << ": ";
        std::cout << currency.second.getValue();
        Colour(hConsole, BRIGHTCyan);
        std::cout << "\t || \t";

        is_changed(currency.second);
        std::cout << "  AVG: " << currency.second.calc_average();
        Colour(hConsole, BRIGHTCyan);
        std::cout <<  "\t || \t";
        is_changed(currency.second);
        std::cout << "MED: " << currency.second.calc_median();
        Colour(hConsole, BRIGHTCyan);
        std::cout <<  "\t||" << std::endl;
    }
    std::cout << "___________________________________________________________" << std::endl
              << "___________________________________________________________\n" << std::endl ;
}

void CurrencyManager::start(int request_count, int interval) {
    while (request_count > 0) {
        request();
        print();
        request_count--;
        sleep(interval);
    }
}

void CurrencyManager::is_changed(Currency currency) {
    if (currency.rise()) {
        Colour(hConsole, BRIGHTGreen);
    }
    else if (currency.fall()) {
        Colour(hConsole, Red);
    }
    else {
        Colour(hConsole, Yellow);
    }
}