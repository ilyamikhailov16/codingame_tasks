#include <iostream>
#include <string>
#include <vector>

int main()
{
    int W, H;
    std::cin >> W >> H; // ширина и высота здания
    int N;
    std::cin >> N; // максимальное число прыжков
    int x, y;
    std::cin >> x >> y; // начальная позиция

    // Сохраняем предыдущую позицию
    int prev_x = x, prev_y = y;
    
    // Области поиска по осям
    std::vector<int> xs, ys;
    
    // Инициализируем возможные позиции
    for (int i = 0; i < W; i++) {
        xs.push_back(i);
    }
    for (int i = 0; i < H; i++) {
        ys.push_back(i);
    }
    
    while (true) {
        std::string info;
        std::cin >> info;
        
        // Сужаем область на основе информации
        if (xs.size() != 1) {
            // Деление по оси X
            if (info == "UNKNOWN") {
                // Первый ход - ничего не делаем
            } else if (info == "SAME") {
                // Расстояние одинаковое - оставляем точки с одинаковым расстоянием
                std::vector<int> new_xs;
                for (int i : xs) {
                    if (std::abs(prev_x - i) == std::abs(x - i)) {
                        new_xs.push_back(i);
                    }
                }
                xs = new_xs;
            } else if (info == "WARMER") {
                // Стали ближе - оставляем точки, к которым новая позиция ближе
                std::vector<int> new_xs;
                for (int i : xs) {
                    if (std::abs(prev_x - i) > std::abs(x - i)) {
                        new_xs.push_back(i);
                    }
                }
                xs = new_xs;
            } else { // COLDER
                // Стали дальше - оставляем точки, к которым старая позиция была ближе
                std::vector<int> new_xs;
                for (int i : xs) {
                    if (std::abs(prev_x - i) < std::abs(x - i)) {
                        new_xs.push_back(i);
                    }
                }
                xs = new_xs;
            }
        } else {
            // Деление по оси Y
            if (info == "UNKNOWN") {
                // Первый ход - ничего не делаем
            } else if (info == "SAME") {
                std::vector<int> new_ys;
                for (int i : ys) {
                    if (std::abs(prev_y - i) == std::abs(y - i)) {
                        new_ys.push_back(i);
                    }
                }
                ys = new_ys;
            } else if (info == "WARMER") {
                std::vector<int> new_ys;
                for (int i : ys) {
                    if (std::abs(prev_y - i) > std::abs(y - i)) {
                        new_ys.push_back(i);
                    }
                }
                ys = new_ys;
            } else { // COLDER
                std::vector<int> new_ys;
                for (int i : ys) {
                    if (std::abs(prev_y - i) < std::abs(y - i)) {
                        new_ys.push_back(i);
                    }
                }
                ys = new_ys;
            }
        }
        
        // Проверяем, не нашли ли мы уже цель
        if (xs.size() == 1 && ys.size() == 1) {
            x = xs[0];
            y = ys[0];
            std::cout << x << " " << y << std::endl;
        }
        
        // Сохраняем текущую позицию как предыдущую
        prev_x = x;
        prev_y = y;
        
        // Выбираем следующую позицию
        if (xs.size() != 1) {
            // Обновляем x
            // Формула для оптимального разбиения области пополам
            if (prev_x == 0 || prev_x == W - 1) {
                x = (xs[0] + xs.back()) / 2;
            } else {
                x = xs[0] + xs.back() - prev_x;
            }
            
            // Избегаем неподвижных точек
            if (x == prev_x) {
                x += 1;
            }
            // Ограничение, чтобы не выйти за границы
            x = std::max(0, std::min(W - 1, x));
        } else {
            // Обновляем y
            if (prev_y == 0 || prev_y == H - 1) {
                y = (ys[0] + ys.back()) / 2;
            } else {
                y = ys[0] + ys.back() - prev_y;
            }
            // Избегаем неподвижных точек
            if (y == prev_y) {
                y += 1;
            }
            // Ограничение, чтобы не выйти за границы
            y = std::max(0, std::min(H - 1, y));
        }
        
        std::cout << x << " " << y << std::endl;
    }
    
    return 0;
}