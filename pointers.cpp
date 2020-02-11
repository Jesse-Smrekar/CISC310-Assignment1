// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#define MAX_INT 2147483647

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
	bool repeat = 1;
	std::string nums = ".1234567890";
	std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string tempString;
	std::string id, firstName, lastName, assignments;  

    double average = 0;
	
	Student student;

		// ------------------- GET USER ID INPUT -------------------- // 
	while( repeat ){
		repeat = 0;

		std::cout << "Please enter the student's id number: ";
		std::cin >> id;
		
		if( id.length() > 9){

			repeat = 1;
			std::cout << "Sorry, I cannot understand your answer\n";
		}

		for(int i=0; i<id.length(); i++){
			
			if( nums.find(id.at(i)) == -1){
				repeat = 1;
				printf("Sorry, I cannot understand your answer\n");
			}	
		}
		
		if(repeat) continue;

		else student.id = std::stoi(id);
	}


		// -------------- GET USER FIRST NAME INPUT ------------------ //
	repeat = 1;		

	while( repeat ){
		
		repeat = 0;		

		std::cout << "Please enter the student's first name: ";
		std::cin >> firstName;

		if( firstName.length() > 128){

			repeat = 1;
			std::cout << "Sorry, I cannot understand your answer\n";
			continue;
		}

		for(int i=0; i<firstName.length(); i++){
			
			if( alpha.find(firstName.at(i)) == -1){
				repeat = 1;
				printf("Sorry, I cannot understand your answer\n");
				continue;
			}	
		}

		student.f_name = (char*)firstName.c_str();
	}


		// -------------- GET USER LAST NAME INPUT ------------------ //
	repeat = 1;		

	while( repeat ){
		repeat = 0;

		std::cout << "Please enter the student's last name: ";
		std::cin >> lastName;

		if( lastName.length() > 128){

			repeat = 1;
			std::cout << "Sorry, I cannot understand your answer\n";
			continue;
		}

		for(int i=0; i<lastName.length(); i++){
			
			if( alpha.find(lastName.at(i)) == -1){
				repeat = 1;
				printf("Sorry, I cannot understand your answer\n");
				continue;
			}	
		}

		student.l_name = (char*)lastName.c_str();
	}


		// -------------- GET USER ASSIGNMENT INPUT ------------------ //
	repeat = 1;		

	while( repeat ){
		repeat = 0;

		std::cout << "Please enter how many assignments were graded: ";
		std::cin >> assignments;

		if( assignments.length() > 13){
			repeat = 1;
			std::cout << "Sorry, I cannot understand your answer\n";
			continue;
		}

		for(int i=0; i<assignments.length(); i++){
			
			if( nums.find(assignments.at(i)) == -1){
				repeat = 1;
				printf("Sorry, I cannot understand your answer\n");
				break;
			}	
		}

		if( std::stol(id) > MAX_INT ){
			repeat = 1;
			std::cout << "Sorry, I cannot understand your answer\n";
			continue;
		}
	
		if(!repeat) student.n_assignments = std::stoi(assignments);
	}

	
	std::string scores[student.n_assignments];

//initialize student.grades array
	student.grades = (double*)malloc( student.n_assignments * sizeof(double) );

	std::cout << "\n";
		// -------------- GET USER SCORES INPUT ------------------ //
	for( int i=0; i<student.n_assignments; i++){
		
		repeat = 1;
		while(repeat){
		
			repeat = 0;

			std::cout << "Please enter grade for assignment " << i << " : ";
			std::cin >> scores[i];

			for(int j=0; j<scores[i].length(); j++){
			
				if( nums.find(scores[i].at(j)) == -1 ){
					repeat = 1;
					printf("Sorry, I cannot understand your answer\n");
					break;
				}	
				
			}

			if( std::stoi(scores[i]) >= 1000 ){
				repeat = 1;
				printf("Sorry, I cannot understand your answer\n");
			}
		}
	}

	for(int i=0; i< student.n_assignments; i++){

		student.grades[i] = std::stod(scores[i]);

	}

// Do calculations
	calculateStudentAverage( &student, &average);

//Print Results
	std::cout << "\nStudent: " << student.f_name << " " << student.l_name << " [" << student.id << "]\n";
	std::cout << "  Average grade: " << average << "\n";
    return 0;
}

void calculateStudentAverage(void *object, double *avg)
{
	Student *newStudent = (Student*)object;

	for(int i=0; i< newStudent->n_assignments; i++){

		*avg = *avg + newStudent->grades[i];

	}

	*avg = *avg / newStudent->n_assignments;


}
