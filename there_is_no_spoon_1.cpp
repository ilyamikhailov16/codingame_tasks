#include <iostream>
#include <string>
#include <vector>
#include <utility> // Для std::pair

// Функция для поиска соседа справа
std::pair<int, int> findRightNeighbor(int x, int y, int width, const std::vector<std::string>& grid) {
    for (int nx = x + 1; nx < width; ++nx) {
        if (grid[y][nx] == '0') {
            return {nx, y};
        }
    }
    return {-1, -1};
}

// Функция для поиска соседа снизу
std::pair<int, int> findBottomNeighbor(int x, int y, int height, const std::vector<std::string>& grid) {
    for (int ny = y + 1; ny < height; ++ny) {
        if (grid[ny][x] == '0') {
            return {x, ny};
        }
    }
    return {-1, -1};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int width;
    std::cin >> width; std::cin.ignore();
    int height;
    std::cin >> height; std::cin.ignore();

    std::vector<std::string> grid(height);
    for (int i = 0; i < height; ++i) {
        std::getline(std::cin, grid[i]);
    }

    // Проходим по всем клеткам сетки
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Если находим узел, ищем его соседей
            if (grid[y][x] == '0') {
                std::pair<int, int> right = findRightNeighbor(x, y, width, grid);
                std::pair<int, int> bottom = findBottomNeighbor(x, y, height, grid);

                std::cout << x << " " << y << " "
                          << right.first << " " << right.second << " "
                          << bottom.first << " " << bottom.second << std::endl;
            }
        }
    }

    return 0;

}
