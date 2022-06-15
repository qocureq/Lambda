#include <string>
#include <vector>
#include <random>

class Student {
public:
    explicit Student(std::string name, std::string surname)
    {
        this->name = std::move(name);
        this->surname = std::move(surname);
        this->album = ++ID;
        this->average = generateAverage();
    }

    std::string name;
    std::string surname;
    int album;
    float average;
private:
    inline static int ID = 10000;

    static float generateAverage()
    {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<float> distribution(3, 5);

        return std::round(distribution(generator) * 100) / 100;
    }
};
