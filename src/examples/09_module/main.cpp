#include "temperature_data.h"
#include<iostream>

int main() 
{
	std::vector<Temperature> out_temps{ 
		Temperature(1, 98.9), Temperature(2, 98.5), Temperature(3, 99),
		Temperature(4, 90.9), Temperature(5, 93.5), Temperature(6, 99.6) };
		
	TemperatureData data;

	data.save_temps(out_temps);

	std::vector<Temperature> in_temps = data.get_temps();

	for (auto temp : in_temps)
	{
		std::cout << temp.get_hour() << " " << temp.get_reading() << "\n";
	}

	return 0;
}