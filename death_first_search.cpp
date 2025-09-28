#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n; // общее количество узлов
    int l; // количество связей
    int e; // количество выходов
    std::cin >> n >> l >> e; std::cin.ignore();

    // Храним все связи в векторе пар, чтобы легко их перебирать каждый ход.
    std::vector<std::pair<int, int>> links;
    for (int i = 0; i < l; i++) {
        int n1;
        int n2;
        std::cin >> n1 >> n2; std::cin.ignore();
        links.push_back({n1, n2});
    }

    // Используем вектор bool для быстрой проверки, является ли узел выходом.
    std::vector<bool> is_gateway(n, false);
    for (int i = 0; i < e; i++) {
        int ei; // индекс выхода
        std::cin >> ei; std::cin.ignore();
        is_gateway[ei] = true;
    }

    // Игровой цикл
    while (1) {
        int si; // Индекс узла, на котором в данный момент находится агент Bobnet
        std::cin >> si; std::cin.ignore();

        int node_to_cut1;
        int node_to_cut2;
        bool immediate_threat_found = false;

        // Первый проход: ищем самую опасную связь - от агента к выходу.
        for (std::pair<int, int> link : links) {
            // Проверяем, соединяет ли эта связь текущую позицию агента с выходом.
            if ((link.first == si && is_gateway[link.second]) || (link.second == si && is_gateway[link.first])) {
                node_to_cut1 = link.first;
                node_to_cut2 = link.second;
                immediate_threat_found = true;
                break; // Нашли самую важную цель, дальше можно не искать.
            }
        }

        // Если прямой угрозы нет, то ищем любую связь, ведущую к любому выходу.
        if (!immediate_threat_found) {
            for (std::pair<int, int> link : links) {
                 // Проверяем, соединен ли хотя бы один узел в этой связи с выходом.
                if (is_gateway[link.first] || is_gateway[link.second]) {
                    node_to_cut1 = link.first;
                    node_to_cut2 = link.second;
                    break; // Нашли первую попавшуюся связь с выходом, этого достаточно.
                }
            }
        }

        std::cout << node_to_cut1 << " " << node_to_cut2 << std::endl;
    }
}