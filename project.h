#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

//Declaration
//What NOT how
//declare not initialise
class Course
{
private:
    std::string course_info;
    std::string course_name;
    std::vector<std::string> students;
    std::vector<std::map<std::string, std::string>> assignments;
    std::vector<std::map<std::string, int>> grades;
    std::string teacher;

public:
    Course(std::string a);
    std::vector<std::map<std::string, std::string>> getassign() const;
    void addassignments(std::string a, std::string b);
    void print_assignments();
    std::vector<std::map<std::string, int>> getgrades();
    void addgrades(std::string a, int b);
    void print_grades();
    void find_mygrade(std::string name);
    std::string get_course_info();
    void addcourseinfo(std::string a);
    std::string get_course_name();
    std::vector<std::string> getstudents() const;
    std::string geteacher() const;
    void addstudents(std::string a);
    void addteacher(std::string b);
    bool find_students(std::string student);
    void print_students();
};
class Student
{
private:
    int id;
    std::string name;
    std::vector<Course> courses;

public:
    Student(int a, std::string b);
    void print_my_courses();
    void view_course(std::string crsname);
    void print_my_grades();
    void add_course(Course crsname);
    int getid() const;
    std::string getname() const;
    void change_name(std::string nname);
    void print_name() const;
    void unregister_from_course(std::string crsname);
};
class Teacher
{
private:
    std::string name;
    std::vector<Course> my_courses;

public:
    Teacher(std::string a);
    std::string get_doctors_name();
    void print_my_courses();
    void create_new_course(std::string crsname);
    void view_course(std::string crsname);
    void listing_assignments(std::string crsname);
};

int ReadInt(int low, int high);
int ShowMenu(std::vector<std::string> choices);
std::string Logging_in();
void secondmenu();
void secondmenu_doc();
void thirdmenu_student(std::string name);
void thirdmenu_doctor(std::string name);
void print_all_courses();
void run();
void append_data(std::string a, int b);

#endif // PROJECT_H_INCLUDED
