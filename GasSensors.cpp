#include "GasSensors.h"

//��� �gpt ����� ����� ���� csv �� ���� ����� ��
/*�����: �� ������ ���� �� ����� ������ ��� ?
? CO? > 2000 PPM ? ����� ��� �����.
? CO > 100 PPM ? ����� ���� ������ �� �����, ������ ������� �� ���.
? NH? > 10 PPM ? ����� ��� �� ����� ���.
? NO? > 3 PPM ? ������ ������ ����� ���.
? �� �� ���� ���� � - 50 % ��� ���� ? ����� ������ �����.
? �� �� ����� ������� ��� ����� / ���� ? ���� ���� �����.*/
//��� ���� ��� sensors.csv �� ����� ��� :
//CO, CO2, H2S, CH4
//120, 800, 20, 4000
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//
//std::vector<float> readCSV(const std::string& filename) {
//    std::vector<float> values;
//    std::ifstream file(filename);
//    std::string line;
//
//    if (!file) {
//        std::cerr << "�����: �� ���� ����� �� ����� " << filename << std::endl;
//        return values;
//    }
//
//    std::getline(file, line); // ����� �� �����
//    std::getline(file, line); // ����� �������
//
//    std::stringstream ss(line);
//    std::string value;
//
//    while (std::getline(ss, value, ',')) {
//        values.push_back(std::stof(value)); // ���� �������
//    }
//
//    file.close();
//    return values;
//}
//
//int main() {
//    std::string filename = "sensors.csv";
//    std::vector<float> data = readCSV(filename);
//
//    if (!data.empty()) {
//        std::cout << "����� ������ ������ CSV:\n";
//        std::cout << "CO: " << data[0] << " PPM\n";
//        std::cout << "CO2: " << data[1] << " PPM\n";
//        std::cout << "H2S: " << data[2] << " PPM\n";
//        std::cout << "CH4: " << data[3] << " PPM\n";
//    }
//
//    return 0;
//}
