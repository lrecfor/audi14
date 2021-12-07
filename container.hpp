#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <fstream>
#include <string>

using namespace std;

//Создать map<Person, string>(человек->должность) по - 
//умолчанию сортирующий людей по возрасту, заполнить и вывести содержимое контейнера.
//Создать map<Person, string> по - умолчанию сортирующий людей по должности
//(лексикографический порядок), заполнить и вывести содержимое контейнера.

template <typename T, template <typename> class K>
K<T> create_container(int a)
{
	K<T> cont;
	for (int i = 0; i < a; ++i) {
		cont.push_back(std::rand() % 100);
	}
	return cont;
}


class Person {
private:
	string name;
	string surname;
	string position;
	int age;
public:
	Person(string _name = "", string _surname = "", int _age = 0, string _position = "") : name(_name), surname(_surname), age(_age), position(_position) {}
	string get_name() const { return name; }
	string get_surname() const { return surname; }
	string get_position() const { return position; }
	int get_age() const { return age; }
	bool operator< (const Person& op) const {
		return age < op.age || (age == op.age && name.size() < op.name.size() && surname.size() < op.surname.size());
	}
	friend ostream& operator<< (ostream& os, const Person& op) {
		os << op.name << " " << op.surname << " " << op.age;
		return os;
	}
};

struct sort_by_age {
	bool operator()(const Person& first, const Person& second) const
	{
		return first.get_age() < second.get_age();
	}
};

struct sort_by_position {
	bool operator()(const Person& first, const Person& second) const
	{
		return first.get_position() < second.get_position();
	}
};

class map_functions {
private:
	map<Person, string, sort_by_age> _by_age;
	map<Person, string, sort_by_position> _by_position;
public:
	void fill_map(string file)
	{
		int position = 0;
		vector<std::string> tmp;
		ifstream in(file);
		if (!in)
		{
			exit(1);
		}
		while (in)
		{
			string str;
			while (getline(in, str))
			{
				tmp.push_back(str);
				++position;
				if (position == 4)
				{
					_by_age[Person(tmp[0], tmp[1], stoi(tmp[2]), tmp[3])] = tmp[3];
					_by_position[Person(tmp[0], tmp[1], stoi(tmp[2]), tmp[3])] = tmp[3];
					while (position)
					{
						tmp.pop_back();
						--position;
					}
				}

			}
		}
	}

	void print_map()
	{
		std::cout << "sort_by_age\n\n" << std::endl;
		for (const auto& p : _by_age)
		{
			std::cout << p.first << " -> " << p.second << std::endl;
		}
		std::cout << "\n\nsort_by_position\n\n" << std::endl;
		for (const auto& p : _by_position)
		{
			std::cout << p.first << " -> " << p.second << std::endl;
		}
	}
};




