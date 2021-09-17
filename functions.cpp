//----------------------------------functions.cpp----------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "project.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

//HOW not what//////

Course::Course(std::string a)
{
    course_name = a;
    course_info = "This is a course that is teached by Dr Antony Crolla, the course has 2 assignments that are mandatory to get your final grade";
    addgrades("Steph", 100);
    addgrades("Elias", 99);
    addassignments("Steph", "Submitted");
    addassignments("Elias", "Submitted");
    addassignments("Randy", "Not Submitted yet");
    students = {"Steph", "Elias", "Randy"};
    teacher = "Dr.Antony Crolla";
}
////// for assignments-----------------------------------
std::vector<std::map<std::string, std::string>> Course::getassign() const
{
    return assignments;
}

void Course::addassignments(std::string a, std::string b)
{
    std::map<std::string, std::string> word;
    word.insert(std::pair<std::string, std::string>(a, b));
    assignments.push_back(word);
}

void Course::print_assignments()
{
    for (const std::map<std::string, std::string> &outer : assignments)
    {
        for (const std::pair<std::string, std::string> &inner : outer)
        {
            std::cout << inner.first << " - " << inner.second << std::endl;
        }
    }
}

/////----------------------------------------
/// For grades-------------------------------
std::vector<std::map<std::string, int>> Course::getgrades()
{
    return grades;
}

void Course::addgrades(std::string a, int b)
{
    std::map<std::string, int> word;
    word.insert(std::pair<std::string, int>(a, b));
    grades.push_back(word);
}

void Course::print_grades()
{
    for (const std::map<std::string, int> &outer : grades)
    {
        for (const std::pair<std::string, int> &inner : outer)
        {
            std::cout << inner.first << " - " << inner.second << std::endl;
        }
    }
}

void Course::find_mygrade(std::string name)
{
    for (const std::map<std::string, int> &outer : grades)
    {
        for (const std::pair<std::string, int> &inner : outer)
        {
            if (name == inner.first)
            {
                std::cout << get_course_name() << " - " << inner.second << std::endl;
                break;
            }
        }
    }
}
///------------------------------------
//getter
std::string Course::get_course_info()
{
    return course_info;
}

std::string Course::get_course_name()
{
    return course_name;
}

std::vector<std::string> Course::getstudents() const
{
    return students;
}
std::string Course::geteacher() const
{
    return teacher;
}
//& setters
void Course::addstudents(std::string a)
{
    students.push_back(a);
}
void Course::addteacher(std::string b)
{
    teacher = b;
}

void Course::addcourseinfo(std::string a)
{
    course_info = a;
}
bool Course::find_students(std::string student)
{
    std::vector<std::string>::iterator it;
    it = find(students.begin(), students.end(), student);
    if (it != students.end())
    {
        std::cout << "\nStudent was found \n";
        return true;
    }
    else
        std::cout << "\nStudent is not taking this class \n";
    return false;
}
void Course::print_students()
{
    std::vector<std::string> v;
    v = getstudents();
    for (auto i : v)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

Teacher::Teacher(std::string a)
{
    name = a;
    Course c1("Math");
    c1.addcourseinfo("This course offers introductions to algebra, geometry, trigonometry, precalculus and calculus.");
    Course c3("Statistics");
    c3.addcourseinfo("Statistics is the science of organizing, analyzing, and interpreting large numerical datasets, with a variety of goals. Descriptive statistics such as mean, median, mode and standard deviation summarize the characteristics of a dataset.");
    c1.addteacher(name);
    c3.addteacher(name);
    my_courses.push_back(c1);
    my_courses.push_back(c3);
}

std::string Teacher::get_doctors_name()
{
    return name;
}

void Teacher::print_my_courses()
{
    std::cout << "\nYour courses are: \n\n";
    for (int i = 0; i < my_courses.size(); i++)
    {
        std::cout << my_courses[i].get_course_name() << "\n";
    }
}

void Teacher::create_new_course(std::string crsname)
{
    Course cnew(crsname);
    cnew.addteacher(name);
    my_courses.push_back(cnew);
}

void Teacher::view_course(std::string crsname)
{
    std::cout << "\n\nAbout this course \n\n";
    for (int i = 0; i < my_courses.size(); i++)
    {
        if (my_courses[i].get_course_name() == crsname)
        {
            std::cout << my_courses[i].get_course_info();
            break;
        }
    }
    std::cout << "\n\n";
}

void Teacher::listing_assignments(std::string crsname)
{
    std::cout << "\n";
    for (int i = 0; i < my_courses.size(); i++)
    {
        if (my_courses[i].get_course_name() == crsname)
        {
            my_courses[i].print_assignments();
            break;
        }
    }
    std::cout << "\n";
}

Student::Student(int a, std::string b)
{
    id = a;
    name = b;
    // for every student;
    Course c1("Math");
    Course c2("Computer Science");
    Course c3("Statistics");
    c1.addgrades(name, 100);
    c2.addgrades(name, 99);
    c3.addgrades(name, 91);
    courses.push_back(c1);
    courses.push_back(c2);
    courses.push_back(c3);
}
//
void Student::print_my_courses()
{
    std::cout << "\nYour courses are: \n\n";
    for (int i = 0; i < courses.size(); i++)
    {
        std::cout << courses[i].get_course_name() << "\n";
    }
}
void Student::view_course(std::string crsname)
{
    std::cout << "\n\nAbout this course \n\n";
    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i].get_course_name() == crsname)
        {
            std::cout << courses[i].get_course_info();
            break;
        }
    }
}
void Student::print_my_grades()
{
    std::cout << "\nYour grades are: \n\n";

    for (int i = 0; i < courses.size(); i++)
    {
        courses[i].find_mygrade(name);
    }
}

void Student::add_course(Course crsname)
{
    courses.push_back(crsname);
}

int Student::getid() const
{
    return id;
}
std::string Student::getname() const
{
    return name;
}

void Student::change_name(std::string nname)
{
    name = nname;
}

void Student::print_name() const
{
    std::cout << name << "\n";
}

void Student::unregister_from_course(std::string crsname)
{
    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i].get_course_name() == crsname)
        {
            courses.erase(courses.begin() + i);
        }
    }
}

///////////////////Helper methods///////////////
int ReadInt(int low, int high)
{

    while (true)
    {

        std::cout << "\nEnter number in range " << low << " - " << high << ": ";
        int value;
        std::cin >> value;

        if (low <= value && value <= high)
        {
            return value;
        }
        else if (std::cin.fail())
        {
            std::cout << "\n something went wrong try again\n";
            std::cin.clear();
            std::cin.ignore('\n');
            ReadInt(low, high);
        }
        else
        {
            std::cout << "\n ERROR: invalid number...Try again\n";
            continue;
        }
    }
}

int ShowMenu(std::vector<std::string> choices)
{
    std::cout << "\nMenu:\n";
    for (int ch = 0; ch < (int)choices.size(); ++ch)
    {
        std::cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
    }
    return ReadInt(1, choices.size());
}

////////////////////////////////////////////////
/// Dummy Database
//Global variables

std::vector<std::string> saved_names{"panos", "nikos", "spilios", "kriko", "Dr.Malone"};
std::vector<int> saved_passwords{1, 2, 3, 4, 5};

void append_data(std::string a, int b)
{
    saved_names.push_back(a);
    saved_passwords.push_back(b);
}

std::vector<std::string> allcourses = {"Math", "Computer Science", "Financial_Risk_Analysis", "Data Science", "Neural_Networks", "Math_2", "Finance_101", "Economics", "Marketing", "Negotiations"};
void print_all_courses()
{
    std::cout << "\nAll courses available\n\n";
    for (int i = 0; i < allcourses.size(); i++)
    {
        std::cout << allcourses[i] << "\n";
    }
}

///Logging in and Signing Up///////////////
std::string Logging_in()
{

    std::string name;
    int password;
    std::cout << "\nEnter your name:  ";
    std::cin >> name;
    //name search
    std::vector<std::string>::iterator it;

    it = find(saved_names.begin(), saved_names.end(), name);
    if (it != saved_names.end())
    {
    }
    else
    {
        std::cout << " Name was not found..try again";
        Logging_in();
    }
    std::cout << "Enter your password: ";
    std::cin >> password;
    //for password search
    int index = it - saved_names.begin();
    if (saved_passwords[index] == password)
    {
        std::cout << "\n\nYou have logged in successfully. ";
        std::cout << "\n\nWelcome " << name << "\n\n";
        return name;
    }
    else
    {
        std::cout << "Invalid password..try again \n";
        Logging_in();
    }
}

Student course_menu(Student s, std::string a)
{
    std::vector<std::string> menu2;
    menu2.push_back("Unregister from Course");
    menu2.push_back("Submit Solution");
    menu2.push_back("Go Back");
    while (true)
    {
        int course_options = ShowMenu(menu2);
        if (course_options == 1)
        {
            s.unregister_from_course(a);
            std::cout << "\nyou have unregistered from this course";
            return s;
        }
        else if (course_options == 2)
        {
            std::cout << "\nThis feature is not available yet\n";
        }
        else if (course_options == 3)
        {
            thirdmenu_student(s.getname());
        }
    }
}

Teacher view_course_menu(Teacher t, std::string a)
{
    std::vector<std::string> menu2;
    menu2.push_back("List Assignments");
    menu2.push_back("Create Assignments");
    menu2.push_back("View Assignments");
    while (true)
    {
        int course_options = ShowMenu(menu2);
        if (course_options == 1)
        {
            std::cout << "\nAssignments status:\n";
            t.listing_assignments(a);
            return t;
        }
        else if (course_options == 2)
        {
            std::cout << "\nFeature not available\n";
            return t;
        }
        else if (course_options == 3)
        {
            std::cout << "\nFeature not available yet\n";
            return t;
        }
    }
}

void Signing_Up()
{
    std::string name;
    int password;
    std::cout << "\nEnter your name: ";
    std::cin >> name;
    std::cout << "\nEnter your password: ";
    std::cin >> password;
    append_data(name, password);
    secondmenu();
}

////////////////////////////////////////////////
void secondmenu()
{
    std::vector<std::string> menu2;
    menu2.push_back("Login");
    menu2.push_back("Sign up");
    menu2.push_back("Shutdown");
    while (true)
    {
        int Log_or_Sign = ShowMenu(menu2);
        if (Log_or_Sign == 1)
        {

            std::string name = Logging_in();
            thirdmenu_student(name);
        }
        else if (Log_or_Sign == 2)
        {
            Signing_Up();
        }
        else
        {
            return run();
        }
    }
}

void secondmenu_doc()
{
    std::cout << "\n ---------------- Log in as a Doctor ---------------------\n";
    std::vector<std::string> menu2;
    menu2.push_back("Login");
    menu2.push_back("Sign up");
    menu2.push_back("Shutdown");
    while (true)
    {
        int Log_or_Sign = ShowMenu(menu2);
        if (Log_or_Sign == 1)
        {
            std::string name = Logging_in();
            thirdmenu_doctor(name);
        }
        else if (Log_or_Sign == 2)
        {
            Signing_Up();
        }
        else
        {
            return run();
        }
    }
}

///////////////////////////////////////////////////////////////////////////
void thirdmenu_student(std::string name)
{
    Student s1(101, name);
    std::vector<std::string> menu3;
    menu3.push_back("Register in Course");
    menu3.push_back("List my courses");
    menu3.push_back("View course");
    menu3.push_back("Grades report");
    menu3.push_back("Log out");
    while (true)
    {
        int Choice = ShowMenu(menu3);
        if (Choice == 1)
        {
            print_all_courses();
            std::cout << "\nEnter course that you want to register: ";
            std::string crs;
            std::cin >> crs;
            std::vector<std::string>::iterator it;
            it = find(allcourses.begin(), allcourses.end(), crs);
            if (it != allcourses.end())
            {
                Course x(crs);
                s1.add_course(crs);
            }
            else
            {
                std::cout << "\nThis course does not exist";
            }
        }
        else if (Choice == 2)
        {
            s1.print_my_courses();
        }
        else if (Choice == 3)
        {
            std::string crs;
            std::cout << "\nEnter course name: ";
            std::cin >> crs;
            s1.view_course(crs);
            s1 = course_menu(s1, crs);
        }
        else if (Choice == 4)
        {
            s1.print_my_grades();
        }
        else if (Choice == 5)
        {
            secondmenu();
        }
    }
}

void thirdmenu_doctor(std::string name)
{
    Teacher t1(name);
    std::vector<std::string> menu3;
    menu3.push_back("List courses");
    menu3.push_back("Create course");
    menu3.push_back("View course");
    menu3.push_back("Log out");
    while (true)
    {
        int Choice = ShowMenu(menu3);
        if (Choice == 1)
        {
            t1.print_my_courses();
        }
        else if (Choice == 2)
        {
            std::cout << "\nEnter New Course Name: ";
            std::string new_crs;
            std::cin >> new_crs;
            t1.create_new_course(new_crs);
            allcourses.push_back(new_crs);
            std::cout << "\nCourse was created successfully";
        }
        else if (Choice == 3)
        {
            std::string crs;
            std::cout << "\nEnter course name: ";
            std::cin >> crs;
            t1.view_course(crs);
            t1 = view_course_menu(t1, crs);
        }
        else if (Choice == 4)
        {
            return;
        }
    }
}

void run()
{

    std::vector<std::string> menu1;
    menu1.push_back("Doctor");
    menu1.push_back("Student");

    while (true)
    {
        int D_or_S = ShowMenu(menu1);
        if (D_or_S == 1)
        {
            secondmenu_doc();
        }
        else
        {
            secondmenu();
        }
    }
}