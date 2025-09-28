#include <iostream>
#include <string>

int main()
{
    int W, H;
    std::cin >> W >> H; // Считываем ширину (W) и высоту (H) области (количество окон)
    int N;
    std::cin >> N; // Считываем максимальное количество прыжков
    int x, y;
    std::cin >> x >> y; // Считываем начальную позицию Бэтмена

    // Определяем границы текущей области поиска бомбы
    int left = 0;
    int right = W - 1;
    int top = 0;
    int bottom = H - 1;

    // Основной игровой цикл
    while (true) {
        std::string bomb_dir;
        std::cin >> bomb_dir;
        // Флаги для отслеживания движения по горизонтали и вертикали
        bool move_horizontal = false;
        bool move_vertical = false;

        // Обрабатываем горизонтальное направление (L/R)
        if (bomb_dir.find('L') != std::string::npos) {
            // Бомба находится слева, сужаем правую границу поиска
            right = x - 1;
            move_horizontal = true;
        } else if (bomb_dir.find('R') != std::string::npos) {
            // Бомба находится справа, сужаем левую границу поиска
            left = x + 1;
            move_horizontal = true;
        }

        // Обрабатываем вертикальное направление (U/D)
        if (bomb_dir.find('U') != std::string::npos) {
            // Бомба находится выше, сужаем нижнюю границу поиска
            bottom = y - 1;
            move_vertical = true;
        } else if (bomb_dir.find('D') != std::string::npos) {
            // Бомба находится ниже, сужаем верхнюю границу поиска
            top = y + 1;
            move_vertical = true;
        }

        // Вычисляем следующую позицию Бэтмена
        // Двигаемся по горизонтали
        if (move_horizontal) {
            x = (left + right) / 2;
        }
        
        // Двигаемся по вертикали
        if (move_vertical) {
            y = (top + bottom) / 2;
        }

        // Выводим новые координаты Бэтмена
        std::cout << x << " " << y << std::endl;
    }

    return 0;
}