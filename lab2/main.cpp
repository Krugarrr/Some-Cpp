#include "Manager/CurrencyManager.h"


int main() {
    setlocale(LC_ALL,"Russian");
    CurrencyManager manager;
    manager.start(5);
    return 0;
}
