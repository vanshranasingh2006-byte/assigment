#include <iostream>
#include <fstream>

struct Student {
    int id;
    float gpa;
};

int main() {
    // 1. Open the existing binary file using ifstream
    std::ifstream fin("student_data.bin", std::ios::binary);

    // 2. Create a temporary object to hold each record as we read it
    Student temp_obj; 

    if (!fin) {
        std::cerr << "Error: Could not open the file!\n";
        return 1;
    }

    std::cout << "--- Reading All Records from File ---\n";

    // 3. The loop condition keeps reading one object at a time until the end of the file (EOF)
    while (fin.read((char*)&temp_obj, sizeof(temp_obj))) {
        std::cout << "Student ID: " << temp_obj.id 
                  << " | GPA: " << temp_obj.gpa << "\n";
    }

    // 4. Close the file stream
    fin.close(); 
    return 0;
}
