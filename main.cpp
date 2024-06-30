#include <iostream>
#include <cstdlib>
#include <ctime>

class Simulation {
public:
    Simulation(int width, int height) : w(width), h(height) {
        std::srand(std::time(0));
    }

    void simulate() {
        // Юр. особи (ліва верхня чверть)
        std::cout << "Юр. особи рухаються в ліву верхню чверть області симуляції:" << std::endl;
        move(0, 0, w / 2, h / 2);

        // Фіз. особи (нижня права чверть)
        std::cout << "Фіз. особи рухаються в нижню праву чверть області симуляції:" << std::endl;
        move(w / 2, h / 2, w, h);
    }

private:
    int w, h;

    void move(int x_start, int y_start, int x_end, int y_end) {
        int x = rand() % (x_end - x_start) + x_start;
        int y = rand() % (y_end - y_start) + y_start;

        std::cout << "Початкова точка: (" << x_start << ", " << y_start << ")" << std::endl;
        std::cout << "Кінцева точка: (" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    int width = 800;  // Введіть ширину області симуляції
    int height = 600; // Введіть висоту області симуляції

    Simulation sim(width, height);
    sim.simulate();

    return 0;
}
