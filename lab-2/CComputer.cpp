#include "CComputer.h"

int CComputer::total_hdd_size_;

CComputer::CComputer()
{
	CComputer::total_hdd_size_ += 1;
}

void CComputer::set_cpu_frequency(int value) {
	if (value < 1) {
		throw "Incorrect CPU frequency value!";
	}
	this->cpu_frequency_ = value;
}

int CComputer::get_cpu_frequency() {
	return this->cpu_frequency_;
}

void CComputer::set_cores_quantity(int value) {
	if (value < 1) {
		throw "Incorrect CPU cores quantity value!";
	}
	this->cores_quantity_ = value;
}

int CComputer::get_cores_quantity() {
	return this->cpu_frequency_;
}

void CComputer::set_ram_size(int value) {
	if (value < 1) {
		throw "Incorrect RAM capacity value!";
	}
	this->ram_size_ = value;
}

int CComputer::get_ram_size() {
	return this->ram_size_;
}

void CComputer::set_hdd_size(int value) {
	if (value < 1) {
		throw "Incorrect HDD capacity value!";
	}
	
	CComputer::total_hdd_size_ += (value - this->hdd_size_);
	
	this->hdd_size_ = value;
}

int CComputer::get_hdd_size() {
	return this->hdd_size_;
}

void CComputer::set_freeze_hdd_size(int value) {
	if (value < 0 || value > this->get_hdd_size()) {
		throw "Incorrect freeze HDD capacity value!";
	}
	this->freeze_hdd_size_ = value;
}

int CComputer::get_freeze_hdd_size() {
	return this->freeze_hdd_size_;
}

void CComputer::set_hdd_size_params(int freezeSize, int size) {
	if (size > 0) {
		this->set_hdd_size(size);
	}

	if (freezeSize < 0 || freezeSize > this->get_hdd_size()) {
		throw "Incorrect freeze HDD capacity value!";
	}
	this->set_freeze_hdd_size(freezeSize);
}

int CComputer::get_free_hdd_size() {
	return this->get_hdd_size() - this->get_freeze_hdd_size();
}

bool CComputer::can_write_file_size(int size) {
	if (size < 1) {
		throw "Incorrect file size!";
	}

	return this->get_free_hdd_size() >= size;
}

std::string CComputer::get_info() {
	std::string info;

	info.append("Computer parameters:\n");
	
	info.append(" * CPU frequency - ");
	info.append(std::to_string(this->get_cpu_frequency()));
	info.append("Hz;\n");

	info.append(" * CPU cores - ");
	info.append(std::to_string(this->get_cores_quantity()));
	info.append(";\n");

	info.append(" * RAM size - ");
	info.append(std::to_string(this->get_ram_size()));
	info.append(";\n");

	info.append(" * HDD size - ");
	info.append(std::to_string(this->get_hdd_size()));
	info.append(";\n");


	info.append(" * HDD freeze size - ");
	info.append(std::to_string(this->get_free_hdd_size()));
	info.append(".\n");

	return info;
}

int CComputer::get_total_hdd_size()
{
	return CComputer::total_hdd_size_;
}

bool operator==(CComputer c1, CComputer c2) {
	return c1.get_cores_quantity() == c2.get_cores_quantity();
}

bool operator!=(CComputer c1, CComputer c2) {
	return c1.get_cores_quantity() != c2.get_cores_quantity();
}

bool operator>(CComputer c1, CComputer c2) {
	return c1.get_cores_quantity() > c2.get_cores_quantity();
}

bool operator>=(CComputer c1, CComputer c2) {
	return c1.get_cores_quantity() >= c2.get_cores_quantity();
}

bool operator<(CComputer c1, CComputer c2) {
	return c1.get_cores_quantity() < c2.get_cores_quantity();
}

bool operator<=(CComputer c1, CComputer c2) {
	return c1.get_cores_quantity() <= c2.get_cores_quantity();
}

std::ostream& operator<<(std::ostream& out, CComputer cComputer) {
	out << cComputer.get_info();
	return out;
}
