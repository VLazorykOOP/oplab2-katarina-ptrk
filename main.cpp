#include <iostream>
#include <cstdlib>
#include <ctime>

class Simulation {
public:
    Simulation(int width, int height) : w(width), h(height) {
        std::srand(std::time(0));
    }

    void simulate() {
        // ��. ����� (��� ������ ������)
        std::cout << "��. ����� ��������� � ��� ������ ������ ������ ���������:" << std::endl;
        move(0, 0, w / 2, h / 2);

        // Գ�. ����� (����� ����� ������)
        std::cout << "Գ�. ����� ��������� � ����� ����� ������ ������ ���������:" << std::endl;
        move(w / 2, h / 2, w, h);
    }

private:
    int w, h;

    void move(int x_start, int y_start, int x_end, int y_end) {
        int x = rand() % (x_end - x_start) + x_start;
        int y = rand() % (y_end - y_start) + y_start;

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
