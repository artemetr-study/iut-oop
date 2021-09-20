#pragma once


#include <iostream>
#include <string>

class CComputer {	
private:
	
	static int total_hdd_size_;
	
	int cpu_frequency_ = 1;
	int cores_quantity_ = 1;
	int ram_size_ = 1;
	int hdd_size_ = 1;
	int freeze_hdd_size_ = 0;

public:

	CComputer();
	
	void set_cpu_frequency(int value);
	int get_cpu_frequency();

	void set_cores_quantity(int value);
	int get_cores_quantity();

	void set_ram_size(int value);
	int get_ram_size();

	void set_hdd_size(int value);
	int get_hdd_size();

	void set_freeze_hdd_size(int value);
	int get_freeze_hdd_size();

	void set_hdd_size_params(int freezeSize, int size = 0);

	int get_free_hdd_size();

	bool can_write_file_size(int size);

	std::string get_info();

	/*operations overloading*/
	friend bool operator== (CComputer c1, CComputer c2);
	friend bool operator!= (CComputer c1, CComputer c2);
	friend bool operator> (CComputer c1, CComputer c2);
	friend bool operator>= (CComputer c1, CComputer c2);
	friend bool operator< (CComputer c1, CComputer c2);
	friend bool operator<= (CComputer c1, CComputer c2);

	friend std::ostream& operator<< (std::ostream& out, CComputer cComputer);

	static int get_total_hdd_size();
};