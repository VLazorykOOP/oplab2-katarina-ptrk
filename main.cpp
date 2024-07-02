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
        std::cout << "��. ����� ��������� � ��� ������ ������ ������ ���������:" << std::endl;
        move(0, 0, w / 2, h / 2);
    }

    void simulate_physical_entities() {
        std::cout << "Գ�. ����� ��������� � ����� ����� ������ ������ ���������:" << std::endl;
        move(w / 2, h / 2, w, h);
    }

    void move(int x_start, int y_start, int x_end, int y_end) {
        int x = std::rand() % (x_end - x_start) + x_start;
        int y = std::rand() % (y_end - y_start) + y_start;

        std::cout << "��������� �����: (" << x_start << ", " << y_start << ")" << std::endl;
        std::cout << "ʳ����� �����: (" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    int width = 800;  // ������ ������ ������ ���������
    int height = 600; // ������ ������ ������ ���������

    Simulation sim(width, height);
    sim.simulate();

    return 0;
}