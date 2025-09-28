#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    // Если торговых дней меньше двух, убыток невозможен
    if (n < 2) {
        std::cout << 0 << std::endl;;
        return 0;
    }

    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    // Пиковая цена, за которую мы могли бы купить до текущего дня
    int peak_price = prices[0];
    // Максимальный убыток (инициализируем нулём, так как это наилучший сценарий)
    int max_loss = 0;

    for (int i = 1; i < n; ++i) {
        // Вычисляем потенциальный убыток при продаже сегодня
        int current_loss = prices[i] - peak_price;
        
        // Обновляем максимальный убыток (ищем минимальное из отрицательных чисел)
        max_loss = std::min(max_loss, current_loss);
        
        // Обновляем пиковую цену, если текущая цена выше
        peak_price = std::max(peak_price, prices[i]);
    }

    std::cout << max_loss << std::endl;

    return 0;

}
