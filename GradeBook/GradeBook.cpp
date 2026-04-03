#include <iostream>
#include <string>
#include <vector> //Use vector for dynamic arrays 
#include <fstream> // File stream 
#include <sstream>

class Student {
private:
	std::string name;
	std::vector<double> grades;

public:
	Student(std::string studentName) : name(studentName) {}

	// Function to add a grade for the student
	void addGrade(double grade) {
		grades.push_back(grade);
	}

	// Function to calculate average grade
	double getAverage() const {
		//Variable
		double sum = 0.0;
		for (double g : grades)
			sum += g;
		return sum / grades.size();
	}

	// Conditional - function to determine letter grade based on average
	char getLetterGrade() const {
		double avg = getAverage();
		if (avg >= 90.0) return 'A';
		else if (avg >= 80.0) return'B';
		else if (avg >= 70.0) return 'C';
		else if (avg >= 60.0) return 'D';
		else return 'F';
	}

	std::string getName() const {
		return name;
	}
};
//Creates a file and saves the students' data in it. 
// The & in the parameter list indicates that we are passing the vector by reference, instead of making a copy.
void saveToFile(const std::vector<Student>& students, const std::string& filename)
{
	std::ofstream file(filename);
	for (const Student& s : students)
	{
		file << s.getName() << "," << s.getAverage()
			<< "," << s.getLetterGrade() << std::endl;
	}
	std::cout << "Data saved to " << filename << std::endl;
}

void loadFromFile(const std::string& filename)
{
	std::ifstream file(filename);
	std::string line;
	std::cout << "\n-- Loaded from file --" << std::endl;
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
}

int main() {

	std::vector< Student > students;
	
	Student alice("Alice");
	double grade1 = 95.0, grade2 = 88.0, grade3 = 92.0, grade4 = 97.0;	

	//Expressions
	double total = grade1 + grade2 + grade3 + grade4;
	double aliceGrades[] = { grade1, grade2, grade3, grade4 };

	//Loop & Array	
	double grades[] = { grade1, grade2, grade3, grade4 };
	for(int i = 0; i < 4; ++i) {
		alice.addGrade(aliceGrades[i]);
	}

	//More students
	Student bob("Bob");
	double grade5 = 78.0, grade6 = 82.0, grade7 = 85.0, grade8 = 80.0;
	double bobGrades[] = { grade5, grade6, grade7, grade8 };
	for(int i = 0; i < 4; ++i) {
		bob.addGrade(bobGrades[i]);
	}
	
	Student charlie("Charlie");
	double grade9 = 65.0, grade10 = 70.0, grade11 = 68.0, grade12 = 72.0;
	double charlieGrades[] = { grade9, grade10, grade11, grade12 };
	for(int i = 0; i < 4; ++i) {
		charlie.addGrade(charlieGrades[i]);
	}

	students.push_back(alice);
	students.push_back(bob);
	students.push_back(charlie);
	
	for (const Student& s : students) {
		std::cout << s.getName() << " | Average: " << s.getAverage() << " | Grade: " << s.getLetterGrade() << std::endl;
	}
	
	//program -> file -> program
	saveToFile(students, "gradebook.csv");
	loadFromFile("gradebook.csv");
}