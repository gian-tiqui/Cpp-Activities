/*
Laboratory Activity # 04:

Create a Student Information System with the following menu:

1. Enroll a Student
2. View Enrolled Students
3. View My Enrolled Subjects
4. Record Student's Grade
5. Exit

Sample Outputs:

1. If User selected "Enroll a Student",

Step 1:
Please enter the student's details,
Student ID	:
Last Name	:
First Name	:
Middle Name	:
Birthday	:
Course		:
Section		:
Year Level	:
Semester	:

Step 2: Print the Subjects Equivalent of that Curriculum
Step 3: Ask the user how many subjects would he enroll
Step 4: Ask the subject codes of each subject to be enrolled.
Step 5: Make a confirmation that he enrolled the following subjects

2. If User selected "View Enrolled Students",

Just print all the enrolled students

3. If User selected "View My Enrolled Subjects"

Step 1: Ask for the User's Student ID
Step 2: Show the User's Enrolled Subjects and their Grade and General Average

4. If User selected "Record Student's Grade",

Step 1: Ask for the Student ID
Step 2: Show Student Details
Step 3: Ask the user how many subjects will be subject to encoding of grades
Step 4: Ask for the subject code and grade of the student for each subject
Step 5: Make a confirmation that he successfully recorded the grades for the following subject

Conditions:
If no recorded grade yet, just save it to the enrolled subject.
If there is recorded grade, make sure to ask confirmation whether to overwrite or not.

Other Requirements:

1. Create a EnrolledSubject Class and a Student Class.
struct Date {
	int year, month, day;
};

EnrolledSubject Class
Attributes:
Subject subjectInfo;
float subjectGrade;

Methods:
EnrolledSubject.recordGrade()

Student Class
Attributes:
string studentId, lastName, firstName, middleName, course, section;
int yearLevel, semester;
Date birthday;
EnrolledSubject subjects; - can be array or vector

Note: Determine what methods would you need to make this program possible.

2. Make sure only valid data are stored in each object.
*/
#include <iostream>
#include <string>
#include <vector>

#define MAX_SUBJECT 			10
#define MAX_YEAR_LEVEL_COUNT 	5
#define MAX_TERM_COUNT			3

#define MAX_YEAR_VALUE			2022
#define MIN_YEAR_VALUE			1800

using namespace std;

/* GLOBAL VARIABLES: NATIVE DATA-TYPES */
string SEMESTERS[MAX_TERM_COUNT] = { "1st", "2nd", "Short" },
YEAR_LEVELS[MAX_YEAR_LEVEL_COUNT] = { "1st", "2nd", "3rd", "4th", "5th" }; 

/* ENUMERATIONS: For Comprehensive indexing of a specific semester or term */
enum SEMESTER_VALUES
{
	FIRST_SEMESTER = 0,
	SECOND_SEMESTER = 1,
	SHORT_TERM = 2
};

enum YEAR_LEVEL_VALUES
{
	FIRST_YEAR = 0,
	SECOND_YEAR = 1,
	THIRD_YEAR = 2,
	FOURTH_YEAR = 3,
	FIFTH_YEAR = 4
};

/* FUNCTION DECLARATIONS */
void populateCurriculums();

void printWithWhitespace(string text, unsigned int num);
//Add Function Declarations here for each new function you develop after this line

void enrollAStudent();

void viewEnrolledStudents();

void viewMyEnrolledSubjects();

void recordStudentGrade();

bool isValidMonth(int birthMonth);

bool isValidDayOfBirth(int birthMonth, int birthDay, int birthYear);

/* CLASS OBJECT STRUCTURES */
class Subject
{
public:
	string subjectCode, description;
	int lectureUnits = 0, laboratoryUnits = 0;
	int requiredYearLevel;
	bool addToTotalUnits;

	Subject();
	//Class constructor
	Subject(string pSubjCode, string pDesc, int pLecUnits = 0, int pLabUnits = 0, bool pAddUnits = true, int pReqYrLvl = -1)
	{
		subjectCode = pSubjCode;
		description = pDesc;
		lectureUnits = pLecUnits;
		laboratoryUnits = pLabUnits;
		addToTotalUnits = pAddUnits;
		requiredYearLevel = pReqYrLvl;
	};

	//returns the total units for this subject
	int totalUnits()
	{
		return (lectureUnits + laboratoryUnits);
	};

private:
	Subject* prerequisite;

};

class Term {
public:
	int year, semester;

	//Class Constructor
	Term(int pYear, int pSemester)
	{
		year = pYear;
		semester = pSemester;
	};

	//used to add a subject to the collection of subjects available in this term
	void addSubject(string pSubjCode, string pDesc, int pLecUnits, int pLabUnits = 0, bool pAddUnits = true, int pReqYrLvl = -1)
	{
		Subject thisSubj(pSubjCode, pDesc, pLecUnits, pLabUnits, pAddUnits, pReqYrLvl);
		subjects.push_back(thisSubj);
	};

	// Used to get a specific subject in this term given a subject code
	Subject getSubject(string pSubjCode)
	{
		Subject thisSubj("", "", 0, 0, 0);
		for (int i = 0; i < totalSubjects(); i++)
			if ((subjects[i].subjectCode).compare(pSubjCode) == 0)
				thisSubj = subjects[i];

		return thisSubj;
	};

	// Used to print all the subjects available in this term
	void printTerm()
	{
		cout << "Year: \t" << YEAR_LEVELS[year] << " Year, \tSemester: \t" << SEMESTERS[semester] << " Term" << endl;
		printWithWhitespace("Code", 10);
		printWithWhitespace("Description", 50);
		printWithWhitespace("Units", 10);
		cout << endl;
		for (int i = 0; i < totalSubjects(); i++)
		{
			printWithWhitespace(subjects[i].subjectCode, 10);
			printWithWhitespace(subjects[i].description, 50);
			printWithWhitespace(to_string(subjects[i].totalUnits()), 10);
			cout << endl;
		}
	};

	//returns the total subjects available for this term
	int totalSubjects()
	{
		return subjects.size();
	};

private:
	//Collection of Subjects
	vector<Subject> subjects;
};

class Curriculum
{
public:
	string courseName, acronym;

	//Class Constructor
	Curriculum(string pCourse, string pAcronym)
	{
		courseName = pCourse;
		acronym = pAcronym;
	};

	//Return a pointer towards the retrieved element after adding to collection of terms
	Term* addTerm(int pYear, int pSemester)
	{
		int termCount = totalTerms();
		Term thisTerm(pYear, pSemester);
		terms.push_back(thisTerm);
		return &terms[termCount];
	};

	//Return a copy of the element if found in the collection of terms
	Term getTerm(int pYear, int pSemester)
	{
		Term thisTerm(-1, -1);
		for (int i = 0; i < totalTerms(); i++)
			if (terms[i].year == pYear && terms[i].semester == pSemester)
				thisTerm = terms[i];

		return thisTerm;
	}

	// Used to print all subjects per term inside this curriculum
	void printCurriculum()
	{
		cout << "Course: " << courseName << "(" << acronym << ")" << endl;

		for (int i = 0; i < totalTerms(); i++)
		{
			terms[i].printTerm();
			cout << endl;
		}
	};

	// Used to print subjects in a specified term, based on given year and semester parameters
	void printTerm(int pYear, int pSemester)
	{
		for (int i = 0; i < totalTerms(); i++)
			if (terms[i].year == pYear && terms[i].semester == pSemester)
			{
				terms[i].printTerm();
				cout << endl;
			}
	};

	//returns the total terms available for this curriculum
	int totalTerms()
	{
		return terms.size();
	};

private:
	//Collection of Terms
	vector<Term> terms;
};

struct Date
{
	int year, month, day;
};

//Add the Class Object Structures you will develop after this line
class EnrolledSubject {
	/*
		Create attributes for the following
		subjectDetails - Subject Object
		finalGrade - This is where you will save the grade for a specific subject

		Create methods for the following:
		1. recordSubjectGrade(float grade){};
		2. getSubjectGrade(){};

	*/
public:
	//public members after this line
	Subject* subjectDetails;

	EnrolledSubject(Subject thisSubj) {
		subjectDetails = new Subject(thisSubj.subjectCode, thisSubj.description, thisSubj.lectureUnits, thisSubj.laboratoryUnits, thisSubj.addToTotalUnits, thisSubj.requiredYearLevel);
		finalGrade = 0;
	};

	bool recordSubjectGrade(float grade) {
		//grade should be from 65 to 100 ONLY
		if (grade >= 65 && grade <= 100) {
			finalGrade = grade;
			return true;
		}
		else return false;
	};

	float getSubjectGrade() {
		return finalGrade;
	};

private:
	//private members after this line
	float finalGrade;
};

class Student 
{
public:
	//public members after this line
	string studentId, lastName, firstName, middleName, course, section;
	int yearLevel, semester;

	Student(string pStudId, string pLastName, string pFirstName, string pMiddleName, string pCourse, string pSection) {
		studentId = pStudId;
		lastName = pLastName;
		firstName = pFirstName;
		middleName = pMiddleName;
		course = pCourse;
		section = pSection;
	};

	void addEnrolledSubject(Subject thisSubject) {
		EnrolledSubject thisEnrolledSubj(thisSubject);
		enrolledSubjects.push_back(thisEnrolledSubj);
	};

	bool recordEnrolledSubjectGrade(string subjectCode, float grade) {
		//declare a pointer EnrolledSubject and get the reference to the specific subject using getEnrolledSubject
		EnrolledSubject* thisEnrolledSubj = getEnrolledSubject(subjectCode);
		if (thisEnrolledSubj) {
			if (thisEnrolledSubj->recordSubjectGrade(grade)) return true;
			else return false;
		}
		else return false;
	};

	void printEnrolledSubjects(bool withGrade = false) {
		printWithWhitespace("Code", 10);
		printWithWhitespace("Description", 50);
		printWithWhitespace("Units", 10);
		if (withGrade)
			printWithWhitespace("Grade", 10);

		cout << endl;

		for (unsigned int i = 0; i < getTotalSubjects(); i++) {
			printWithWhitespace(enrolledSubjects[i].subjectDetails->subjectCode, 10);
			printWithWhitespace(enrolledSubjects[i].subjectDetails->description, 50);
			cout << enrolledSubjects[i].subjectDetails->totalUnits();
			printWithWhitespace("", 9);
			if (withGrade) {
				cout << enrolledSubjects[i].getSubjectGrade();
			}
			cout << endl;
		}
	};

	unsigned int getTotalSubjects() {
		return enrolledSubjects.size();
	};

	bool setYearLevel(int pYearLevel) {
		if (pYearLevel >= 0 && pYearLevel <= MAX_YEAR_LEVEL_COUNT - 1) {
			yearLevel = pYearLevel;
			return true;
		}
		else return false;
	};

	bool setSemester(int pSemester) {
		if (pSemester >= 0 && pSemester <= MAX_TERM_COUNT - 1) {
			semester = pSemester;
			return true;
		}
		else return false;
	};

	bool setBirthday(int pYear, int pBirthMonth, int pDay) {
		if (pYear >= MIN_YEAR_VALUE && pYear <= MAX_YEAR_VALUE)
			birthday.year = pYear;
		else
			return false;

		if (isValidMonth(pBirthMonth))
			birthday.month = pBirthMonth;
		else
			return false;

		if (isValidDayOfBirth(pBirthMonth, pDay, pYear))
			birthday.day = pDay;
		else
			return false;

		return true;
	};

private:
	//private members after this line
	Date birthday;
	vector<EnrolledSubject> enrolledSubjects;

	EnrolledSubject* getEnrolledSubject(string subjectCode) {
		//return a reference to the element of the specific enrolled subject;
		EnrolledSubject* thisEnrolledSubj = nullptr;
		for (unsigned int i = 0; i < getTotalSubjects(); i++) {
			if (enrolledSubjects[i].subjectDetails->subjectCode.compare(subjectCode) == 0)
				thisEnrolledSubj = &enrolledSubjects[i];
		}

		return thisEnrolledSubj;
	};
};

/*
	Notes:
	You might need a function to return a pointer towards a student in your collection of students,
	in order to save his/her grade given a specific student id
*/

//Arrays or Vectors - Global Variables
vector<Curriculum> curriculums;

vector<Student> students;
//Add your arrays or vectors after this line

int validateID(string ID);

int main()
{
again:
	int choice;
	
	cout << "ACT - Student Enrollment System" << endl;
	cout << endl;
	cout << "1. Enroll a Student" << endl;
	cout << "2. View Enrolled Students" << endl;
	cout << "3. View My Enrolled Subjects" << endl;
	cout << "4. Record Student's Grade" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter the number of your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		enrollAStudent();
		break;
	case 2:
		viewEnrolledStudents();
		break;
	case 3:
		viewMyEnrolledSubjects();
		break;
	case 4:
		recordStudentGrade();
		break;
	case 5:
		goto exit;
	default:
		cout << "Invalid input." << endl;
		goto again;
	}

exit:

	return 0;
}

/* FUNCTION DEFINITIONS */
void populateCurriculums()
{
	/* ACT Curriculum */
	Curriculum ACT("Associate in Computer Technology", "ACT");

	//cout << "Adding Associate in Computer Technology...." << endl;
	//Save a pointer towards the newly add element within the collection of terms in the curriculum object

	Term* ACT11 = ACT.addTerm(FIRST_YEAR, FIRST_SEMESTER);

	//add subjects to the collection of subjects available in the term object within the curriculum object

	ACT11->addSubject("GE1", "Understanding the Self", 3, 0, true, -1);
	ACT11->addSubject("GE2", "Readings in Philippine History", 3, 0, true, -1);
	ACT11->addSubject("GELec1", "Environmental Science", 3, 0, true, -1);
	ACT11->addSubject("GE4", "Mathematics in the Modern World", 3, 0, true, -1);
	ACT11->addSubject("VED2", "Values Education 2: Character Formation 1", 3, 0, true, -1);
	ACT11->addSubject("ITC11", "Introduction to Computing", 2, 1, true, -1);
	ACT11->addSubject("FOP12", "Fundamentals of Programming", 2, 1, true, -1);
	ACT11->addSubject("WTS21", "Web Technologies 1", 2, 1, true, -1);
	ACT11->addSubject("ProDev1", "Professional Development 1", 1, 0, true, -1);
	ACT11->addSubject("PE1", "Physical Education 1", 2, 0, true, -1);
	ACT11->addSubject("NSTP1", "National Service Training Program 1", 3, 0, false, -1);

	//Save a pointer towards the newly add element within the collection of terms in the curriculum object

	Term* ACT12 = ACT.addTerm(FIRST_YEAR, SECOND_SEMESTER);
	ACT12->addSubject("GE5", "Purposive Communication", 3, 0, true, -1);
	ACT12->addSubject("GE6", "Art Appreciation", 3, 0, true, -1);
	ACT12->addSubject("GE7", "Science, Technology and Society", 3, 0, true, -1);
	ACT12->addSubject("GE8", "Ethics", 3, 0, true, -1);
	ACT12->addSubject("Fil1", "Kontekstwalisadong Komunikasyon sa Filipino", 3, 0, true, -1);
	ACT12->addSubject("IMP23", "Intermediate Programming", 2, 1, true, -1);
	ACT12->addSubject("MMD21", "Multimedia Design", 2, 1, true, -1);
	ACT12->addSubject("OS22", "Operating Systems", 3, 0, true, -1);
	ACT12->addSubject("ProDev2", "Professional Development 2", 1, 0, true, -1);
	ACT12->addSubject("PE2", "Physical Education 2", 2, 0, true, -1);
	ACT12->addSubject("NSTP2", "National Service Training Program 2", 3, 0, false, -1);

	//Save a pointer towards the newly add element within the collection of terms in the curriculum object

	Term* ACT13 = ACT.addTerm(FIRST_YEAR, SHORT_TERM);
	ACT13->addSubject("Eng1", "Technical Writing", 3, 0, true, -1);
	ACT13->addSubject("GE3", "Contemporary World", 3, 0, true, -1);
	ACT13->addSubject("NAC22", "Networking and Communication 1", 3, 0, true, -1);

	//Save a pointer towards the newly add element within the collection of terms in the curriculum object

	Term* ACT21 = ACT.addTerm(SECOND_YEAR, FIRST_SEMESTER);
	ACT21->addSubject("Entrep1", "Entrepreneurial Mind", 3, 0, true, -1);
	ACT21->addSubject("VED1", "Values Education 1: Euthenics", 3, 0, true, -1);
	ACT21->addSubject("DSA21", "Data Structures and Algorithms", 2, 1, true, -1);
	ACT21->addSubject("Eng2", "Speech Communication", 3, 0, true, -1);
	ACT21->addSubject("IM24", "Information Management", 2, 1, true, -1);
	ACT21->addSubject("CAD43", "Computer Architecture and Organization", 2, 1, true, -1);
	ACT21->addSubject("GElec2", "Gender and Society", 3, 0, true, -1);
	ACT21->addSubject("ProDev3", "Professional Development 3", 3, 0, true, -1);
	ACT21->addSubject("SPI42", "Social and Professional Issues", 3, 0, true, -1);
	ACT21->addSubject("PE3", "Physical Education 3", 3, 0, true, -1);

	//Save a pointer towards the newly add element within the collection of terms in the curriculum object

	Term* ACT22 = ACT.addTerm(SECOND_YEAR, SECOND_SEMESTER);
	ACT22->addSubject("Riz", "Rizal's Life and Works", 3, 0, true, -1);
	ACT22->addSubject("SAD21", "System Analysis and Design", 3, 0, true, -1);
	ACT22->addSubject("OOP23", "Object-Oriented Programming", 2, 1, true, -1);
	ACT22->addSubject("ADE31", "Application Development and Emerging Technology", 2, 1, true, SECOND_YEAR);
	ACT22->addSubject("WTS22", "Web Technologies 2", 2, 1, true, -1);
	ACT22->addSubject("ICT102", "Business Software and Tools (W/ LMS)", 2, 1, true, -1);
	ACT22->addSubject("HCI31", "Human Computer Interaction", 2, 1, true, SECOND_YEAR);
	ACT22->addSubject("ProDev4", "Professional Development 4", 1, 0, true, -1);
	ACT22->addSubject("Entrep2", "Entrepreneurial Management", 3, 0, true, -1);
	ACT22->addSubject("PE4", "Physical Education 4", 2, 0, true, -1);

	curriculums.push_back(ACT);
}

void printWithWhitespace(string text, unsigned int num)
{
	cout << text;
	if (text.size() < num)
		for (int i = 0; i < num - text.size(); i++)
			cout << " ";
}

//Add Function Definitions for your user-defined functions after this line

void enrollAStudent()
{
	char choice;
	Date studentBirth;
	string sstudentId, slastName, sfirstName, smiddleName, scourse, ssection, key, subjectCode;
	int syearLevel, ssemester, amount = 0;

	cout << "Please enter the student's details:" << endl;
	cout << "Student ID          : ";
	getline(cin >> ws, sstudentId);
	cout << "Last Name           : ";
	getline(cin, slastName);
	cout << "First Name          : ";
	getline(cin, sfirstName);
	cout << "Middle Name         : ";
	getline(cin, smiddleName);
	cout << "Enter birth details :" << endl;
	cout << "1. January" << endl;
	cout << "2. February" << endl;
	cout << "3. March" << endl;
	cout << "4. April" << endl;
	cout << "5. May" << endl;
	cout << "6. June" << endl;
	cout << "7. July" << endl;
	cout << "8. August" << endl;
	cout << "9. September" << endl;
	cout << "10. October" << endl;
	cout << "11. November" << endl;
	cout << "12. December" << endl;
	cout << "Birth Month         : ";
	cin >> studentBirth.month;
	cout << "Birth Day           : ";
	cin >> studentBirth.day;
	cout << "Birth Year          : ";
	cin >> studentBirth.year;
	cout << "Course              : ";
	getline(cin >> ws, scourse);
	cout << "Section             : ";
	getline(cin, ssection);
	cout << "Year Level          : ";
	cin >> syearLevel;
	cout << "Semester            : ";
	cin >> ssemester;
	Student thisStudent(sstudentId, slastName, sfirstName, smiddleName, scourse, ssection);
	if (!thisStudent.setBirthday(studentBirth.year, studentBirth.month, studentBirth.day))
		cout << "Invalid birthday." << endl;
	if (!thisStudent.setYearLevel(syearLevel))
		cout << "Invalid year level provided." << endl;
	if (!thisStudent.setSemester(ssemester))
		cout << "Invalid semester." << endl;
	populateCurriculums();
	cout << "These are the subjects available for the term: " << endl;
	Term thisTerm = curriculums[0].getTerm(syearLevel - 1, ssemester - 1);
	thisTerm.printTerm();

againm:

	cout << "How many subjects do you want to enroll? : ";
	cin >> amount;

	if (amount > thisTerm.totalSubjects())
	{
		cout << "You cannot enroll more than "<<thisTerm.totalSubjects()<<" subjects." << endl;
		goto againm;
	}
	else
	{
		for (int x = 1; x <= amount; x++)
		{
			cout << "Enter subject code: ";
			cin >> subjectCode;
			Subject thisSubj = thisTerm.getSubject(subjectCode);
			cout << "You selected " << thisSubj.description << " with " << thisSubj.laboratoryUnits << " Laboratory Units and ";
			cout << thisSubj.lectureUnits << " Lecture Units." << endl;
			thisStudent.addEnrolledSubject(thisSubj);	
		}
	}

	cout << "These are your enrolled subjects: " << endl;
	thisStudent.printEnrolledSubjects();
	

	cout << "Enroll this student? Enter 'Y' or 'N': ";
	cin >> choice;

	if (choice == 'Y' || choice == 'y')
	{
		students.push_back(thisStudent);
		cout << "Student is enrolled." << endl;
		cout << "Enter any key to exit: ";
		cin >> key;
		main();
	}
	else
		main();
}

void viewEnrolledStudents()
{
	string button;
	if (students.size() < 1)
		cout << "No students are enrolled." << endl;
	else
	{
		printWithWhitespace("Student ID", 15);
		printWithWhitespace("Last Name", 15);
		printWithWhitespace("First Name", 15);
		printWithWhitespace("Middle Name", 15);
		printWithWhitespace("Course", 10);
		printWithWhitespace("Section", 10);
		printWithWhitespace("Year Level", 12);
		printWithWhitespace("Semester", 10);
		cout << endl;
		for (int y = 0; y < students.size(); y++)
		{
			printWithWhitespace(students[y].studentId, 15);
			printWithWhitespace(students[y].lastName, 15);
			printWithWhitespace(students[y].firstName, 15);
			printWithWhitespace(students[y].middleName, 15);
			printWithWhitespace(students[y].course, 10);
			printWithWhitespace(students[y].section, 10);
			printWithWhitespace(to_string(students[y].yearLevel), 12);
			printWithWhitespace(to_string(students[y].semester), 10);
			cout << endl;
		}
	}

	cout << "Enter any key to exit: ";
	cin >> button;
	main();
}

void viewMyEnrolledSubjects()
{
	int options;
	string studentID, key;
	int index;

	cout << "Enter the student ID: ";
	cin >> studentID;

	index = validateID(studentID);

	if (index > -1)
	{
		//students[index].printDetails();
		printWithWhitespace("Student ID", 15);
		printWithWhitespace("Last Name", 15);
		printWithWhitespace("First Name", 15);
		printWithWhitespace("Middle Name", 15);
		printWithWhitespace("Course", 10);
		printWithWhitespace("Section", 10);
		printWithWhitespace("Year Level", 12);
		printWithWhitespace("Semester", 10);
		cout << endl;
		printWithWhitespace(students[index].studentId, 15);
		printWithWhitespace(students[index].lastName, 15);
		printWithWhitespace(students[index].firstName, 15);
		printWithWhitespace(students[index].middleName, 15);
		printWithWhitespace(students[index].course, 10);
		printWithWhitespace(students[index].section, 10);
		printWithWhitespace(to_string(students[index].yearLevel), 12);
		printWithWhitespace(to_string(students[index].semester), 10);
		cout << endl;

		cout << "1. View enrolled subjects with grades" << endl;
		cout << "2. View enrolled subjects" << endl;
	againn:
		cout << "Please choose from the options above: ";
		cin >> options;

		if (options == 1)
		{
			students[index].printEnrolledSubjects(true);
		}
		else if (options == 2)
		{
			students[index].printEnrolledSubjects(false);
		}
		else
		{
			cout << "Please choose again." << endl;
			goto againn;
		}
	}

	else
	{
		cout << "Student is not found." << endl;
	}


	cout << "Enter any key to exit: ";
	cin >> key;
	main();
}

void recordStudentGrade()
{
	char another;
	int options;
	string studentID, key, subjectCode;
	int index, grade;
	cout << "Enter the student ID: ";
	cin >> studentID;

	index = validateID(studentID);

	if (index > -1)
	{
		//students[index].printDetails();
		printWithWhitespace("Student ID", 15);
		printWithWhitespace("Last Name", 15);
		printWithWhitespace("First Name", 15);
		printWithWhitespace("Middle Name", 15);
		printWithWhitespace("Course", 10);
		printWithWhitespace("Section", 10);
		printWithWhitespace("Year Level", 12);
		printWithWhitespace("Semester", 10);
		cout << endl;
		printWithWhitespace(students[index].studentId, 15);
		printWithWhitespace(students[index].lastName, 15);
		printWithWhitespace(students[index].firstName, 15);
		printWithWhitespace(students[index].middleName, 15);
		printWithWhitespace(students[index].course, 10);
		printWithWhitespace(students[index].section, 10);
		printWithWhitespace(to_string(students[index].yearLevel), 12);
		printWithWhitespace(to_string(students[index].semester), 10);
		cout << endl;

	back:


		Term thisTerm = curriculums[0].getTerm(students[index].yearLevel - 1, students[index].semester - 1);

	againm:

		cout << "Enter subject code: ";
		cin >> subjectCode;
		Subject thisSubj = thisTerm.getSubject(subjectCode);
		cout << "You selected " << thisSubj.description << " with " << thisSubj.laboratoryUnits << " Laboratory Units and ";
		cout << thisSubj.lectureUnits << " Lecture Units." << endl;
		cout << "Insert final grade: ";
		cin >> grade;
		

		if (!students[index].recordEnrolledSubjectGrade(subjectCode, grade))
		{
			cout << "Invalid Grade Provided." << endl;
			goto againm;
		}
		else
		{
			cout << "Grade added." << endl;
		}
		cout << "Add another grade? Enter 'Y' or 'N': ";
		cin >> another;
		if (another == 'Y' || another == 'y')
			goto back;
		else
			goto exit;
	}

	else
	{
		cout << "Student is not found." << endl;
	}

exit: 

	cout << "Enter any key to exit: ";
	cin >> key;
	main();
}

int validateID(string ID)
{
	for (int x = 0; x < students.size(); x++)
	{
		if (students[x].studentId == ID)
			return x;
	}
	return -1;
}

//Add Function Definitions for your user-defined functions after this line
bool isValidMonth(int birthMonth) {
	//month is within 1 to 12
	return (birthMonth >= 1 && birthMonth <= 12);
}

bool isValidDayOfBirth(int birthMonth, int birthDay, int birthYear) {
	bool 	isValid = false,
		isLeapYear = (birthYear % 4 == 0);//If year is divisble by 4 it is a leap year
	int limit = 0;
	/*
		//31 Days
		1 - January		(31 days)
		3 - March		(31 days)
		5 - May			(31 days)
		7 - July		(31 days)
		8 - August		(31 days)
		10 - October	(31 days)
		12 - December	(31 days)

		//30 Days
		4 - April		(30 days)
		6 - June		(30 days)
		9 - September	(30 days)
		11 - November	(30 days)

		//28 or 29 Days - February
		2 - February	(28 days, if Leap Year 29 days)
	*/

	if (birthDay < 1) return isValid;
	//conditions
	switch (birthMonth) {
		//31 Days
	case 1:	case 3:		case 5:	case 7:
	case 8:	case 10:	case 12:
		limit = 31;
		break;
		//30 Days
	case 4:	case 6:		case 9:	case 11:
		limit = 30;
		break;
		//28 or 29 Days - February
	case 2:
		/*
			Ternary Operators
			variable = (condition) ? trueValue : falseValue;

			if(condition)
				variable = trueValue;
			else
				variable = falseValue;

			!isLeapYear - isLeapYear != true
		*/
		limit = (!isLeapYear) ? 28 : 29;
		break;
	}

	isValid = (birthDay <= limit);

	if (!isValid)
		cout << "You have exceeded maximum days for selected month. Only " << limit << " days exists." << endl;

	return isValid;
}
