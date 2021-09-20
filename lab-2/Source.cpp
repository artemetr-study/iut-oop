#include <iostream>
#include "CComputer.h"

void main()
{
	CComputer a;
	a.set_cores_quantity(2);
	a.set_cpu_frequency(2);
	a.set_hdd_size(256);
	a.set_ram_size(16);
	a.set_freeze_hdd_size(12);
	std::cout << a << std::endl;

	CComputer b;
	b.set_cores_quantity(4);
	b.set_cpu_frequency(24);
	b.set_hdd_size(252);
	b.set_ram_size(11);
	a.set_freeze_hdd_size(10);
	std::cout << b << std::endl;

	std::cout << (a > b) << std::endl;
	std::cout << CComputer::get_total_hdd_size() << std::endl;
	system("pause");
}