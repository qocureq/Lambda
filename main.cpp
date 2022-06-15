#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>

#include "student.cpp"


int randomNumber(int len)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, len);

    return distribution(generator);
}

int main() {
    int l;

    std::vector<std::string> names{"Adam", "Tomasz", "Piotr", "Marcin", "Jakub", "Grzegorz", "Michal", "Krzysztof", "Robert", "Wojciech", "Mariusz"};
    std::vector<std::string> surnames{"Pudzianowski", "Wlodarczyk", "Kowalczyk", "Zyla", "Malysz", "Lewandowski", "Blaszczykowski", "Kubica", "Wozniak", "Nowak"};

    std::vector<Student> students;
    students.reserve(30);
    for (int i = 0; i < 30; ++i)
        {
            students.emplace_back(names[randomNumber(std::make_signed_t<int>(names.size()-1))], surnames[randomNumber(std::make_signed_t<int>(surnames.size() -1))]);
        }


    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if(a.surname == b.surname)
        {
            if(a.name == b.name)
                return a.album < b.album;
            return a.name < b.name;
        }
        return a.surname < b.surname;
    });

    std::cout << "\n[Sortowanie alfabetyczne]\n"; l = 1;
    for (auto& student : students) {
        std::cout << std::right << std::setw(2) << l++ << ". "
                  << std::left << std::setw(20) << student.surname
                  << std::left << std::setw(15) << student.name
                  << std::right << std::setw(5) << student.album
                  << std::right << std::setw(10) << std::fixed << std::setprecision(2) << student.average << "\n";
    }

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.album < b.album;
    });

    std::cout << "\n[Sortowanie wg numeru albumu]\n"; l =1;
    for (auto& student : students) {
        std::cout << std::right << std::setw(2) << l++ << ". "
                  << std::left << std::setw(20) << student.surname
                  << std::left << std::setw(15) << student.name
                  << std::right << std::setw(5) << student.album
                  << std::right << std::setw(10) << std::fixed << std::setprecision(2) << student.average << "\n";
    }

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if(a.average == b.average)
            return a.album < b.album;
        return a.average > b.average;
    });

    std::cout << "\n[Sortowanie wg średniej]\n"; l = 1;
    for (auto& student : students) {
        std::cout << std::right << std::setw(2) << l++ << ". "
        << std::left << std::setw(20) << student.surname
        << std::left << std::setw(15) << student.name
        << std::right << std::setw(5) << student.album
        << std::right << std::setw(10) << std::fixed << std::setprecision(2) << student.average << "\n";
    }
}