#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>

class Simulation {
public:
    Simulation(int width, int height) : w(width), h(height) {
        std::srand(std::time(0));
    }

    void simulate() {
        // Create threads for each type of movement
        std::thread thread1(&Simulation::simulate_legal_entities, this);
        std::thread thread2(&Simulation::simulate_physical_entities, this);

        // Join threads to ensure they complete before the program exits
        thread1.join();
        thread2.join();
    }

private:
    int w, h;

    void simulate_legal_entities() {
        std::cout << "Юр. особи рухаються в ліву верхню чверть області симуляції:" << std::endl;
        move(0, 0, w / 2, h / 2);
    }

    void simulate_physical_entities() {
        std::cout << "Фіз. особи рухаються в нижню праву чверть області симуляції:" << std::endl;
        move(w / 2, h / 2, w, h);
    }

    void move(int x_start, int y_start, int x_end, int y_end) {
        int x = std::rand() % (x_end - x_start) + x_start;
        int y = std::rand() % (y_end - y_start) + y_start;

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