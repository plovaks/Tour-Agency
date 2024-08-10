#include <iostream>
#include <fstream>
#include <string>
#include "Tour.h"
#include "TourList.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    ifstream inputFile("C:/Users/эмо кид/source/repos/Kursovaya/information.txt");

    if (!inputFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }
    
   
    
    TourList tourList;
    Tour newTour;

    string name, country;
    int adults, numberoftours, people;
    double price;
    while (inputFile >> name >> country >> adults >> price >> numberoftours) {
        Tour tour(name, country, adults, price, numberoftours);
        tourList.addTour(tour);
    }
    inputFile.close();
    string nameOfTourForBooking, firsttour, secondtour, infCountry;
    int choice;
    // Добавление всех вводимых данных в конец заданного файла
    ofstream output("C:/Users/эмо кид/source/repos/Kursovaya/information.txt", ios::app);
    do {
        cout << "Меню:" << endl;
        cout << "1. Просмотр всех доступных туров." << endl;
        cout << "2. Сортировка туров по возрастанию цены." << endl;
        cout << "3. Сортировка туров по убыванию цены." << endl;
        cout << "4. Добавление новго тура." << endl;
        cout << "5. Бронирование тура по названию." << endl;
        cout << "6. Сравнение туров по цене." << endl;
        cout << "7. Вывод всех туров страны." << endl;
        cout << "8. Выход." << endl;
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Доступные туры:" << endl;
            tourList.displayTours();
            break;
        case 2:
            tourList.sortAscending();
            tourList.displayTours();
            cout << "Туры отсортированы по возрастанию цены." << endl;
            break;
        case 3:
            tourList.sortDescending();
            tourList.displayTours();
            cout << "Туры отсортированы по убыванию цены." << endl;
            break;
        case 4:
            cout << "Введите название тура латиницей без пробелов: ";
            cin >> newTour.name;
            cout << "Введите страну латиницей без пробелов: ";
            cin >> newTour.country;
            cout << "Введите количество взрослых: ";
            cin >> newTour.numberOfPassengers;
            cout << "Введите цену тура на одного человека: ";
            cin >> newTour.priceOfTour;
            cout << "Введите количество оставшихся мест: ";
            cin >> newTour.numberOfAvailableTickets;
            if (tourList.addTour(newTour)) {
                cout << "Тур успешно добавлен!" << endl;
            }
            else {
                cout << "Ошибка при добавлении тура." << endl;
            }

            if (!output) {
                cerr << "Ошибка записи в файл." << endl;
                return 1;
            }

            output << newTour.name << " " << newTour.country << " " << newTour.numberOfPassengers << " " << newTour.priceOfTour << " " << newTour.numberOfAvailableTickets << "\n";
            output.close();
            tourList.displayTours();
            break;

        case 5:
            cout << "Доступные туры:" << endl;
            tourList.displayTours();
            cout << "Введите название тура, котрый хотите забронировать: "; cin >> nameOfTourForBooking;
            cout << "Введите количество человек, на которых хотите забронировать тур: "; cin >> people;
            tourList.bookTour(nameOfTourForBooking, people);
            break;
        case 6:
            tourList.displayTours();
            cout << "Введите название туров, которые хотите стравнить: " << endl;
            cout << "Введите название первого тура: "; cin >> firsttour;
            cout << "Введите название второго тура: "; cin >> secondtour;
            tourList.compareTwoToursByCosts(firsttour, secondtour);
            cout << "Вы сравнили два тура!" << endl;
            break;
        case 7:
            cout << "Введите название страны, туры которой Вас интересуют: "; cin >> infCountry;
            tourList.informationFromCountry(infCountry);
            break;
        default:
            cout << "Неверная опция. Попробуйте ещё раз." << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}

