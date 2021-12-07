#include "container.hpp"

int main() {

	vector<int> db1 = create_container<int, vector>(10);
	for_each(db1.begin(), db1.end(),
		[](auto& entry)
		{
			cout << entry << " ";
		});
	cout << endl;

	list<int> db2 = create_container<int, list>(10);
	for_each(db2.begin(), db2.end(),
		[](auto& entry)
		{
			cout << entry << " ";
		});
	cout << endl << endl;

	map_functions m;
	m.fill_map("input.txt");
	m.print_map();

	return 0;
}

/*����������� ������� create_container ��������� ���������������� ��������� STL � ����������� ��������� �������
��� ��������.
�������������:
	
������� map<Person, string> (������� -> ���������) ��-��������� ����������� ����� �� ��������, ��������� � ������� ���������� ����������.
������� map<Person, string> ��-��������� ����������� ����� �� ��������� (������������������ �������), ��������� � ������� ���������� ����������.*/