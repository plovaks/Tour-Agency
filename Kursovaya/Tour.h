#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Tour {
public:
	string name, country;
	int numberOfPassengers;
	double priceOfTour;// Цена за тур указана на 1 человека
	int numberOfAvailableTickets;
	Tour();
	Tour(string name, string country, int numberOfPassengers, double priceOfTour, int numberOfAvailableTickets);
	void displayInfo();
};