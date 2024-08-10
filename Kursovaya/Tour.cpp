#include "Tour.h"
using namespace std;
// Класс Tour с информацией о туре
   Tour:: Tour() {
        name = "";
        country = "";
        numberOfPassengers = 0;
        priceOfTour = 0.0;
        numberOfAvailableTickets = 0;
    }
    // Конструктор для инициализации объектов класса с начальными значениями
   Tour:: Tour(string name, string country, int numberOfPassengers, double priceOfTour, int numberOfAvailableTickets) {
        // Присваивание значений аргументов полям класса
        this->name = name;
        this->country = country;
        this->numberOfPassengers = numberOfPassengers;
        this->priceOfTour = priceOfTour;
        this->numberOfAvailableTickets = numberOfAvailableTickets;
    }
    // Отображение полей класса на экран
    void Tour:: displayInfo() {
        cout << "Название тура: " << name << endl;
        cout << "Страна: " << country << endl;
        cout << "Количество взрослых: " << numberOfPassengers << endl;
        cout << "Цена: " << priceOfTour << endl;
        cout << "Количество оставшихся мест: " << numberOfAvailableTickets << endl;
        cout << "------------------------" << endl;
    }
