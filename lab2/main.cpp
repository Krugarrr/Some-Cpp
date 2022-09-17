#include "Manager/CurrencyManager.h"


int main() {
    setlocale(LC_ALL,"Russian");
    CurrencyManager manager;
    manager.start(1, 1);
    return 0;
}
