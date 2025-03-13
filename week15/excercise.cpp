#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <string>
#include <map>

struct Student {
    std::string name;
    int id;
    int grade;

    auto operator<=>(const Student&) const = default;
};

struct Teacher {
    std::string name;
    int id;

    auto operator<=>(const Teacher&) const = default;
};

struct Subject {
    std::string name;
    Teacher teacher;

    auto operator<=>(const Subject&) const = default;
};

struct TimetableSlot {
    int day;
    int period;

    auto operator<=>(const TimetableSlot&) const = default;
};

using Room = std::string;

struct Class {
    std::string name;
    std::set<Student> students;
    std::map<TimetableSlot, std::tuple<Subject, Room>> timetable;

    auto operator<=>(const Class&) const = default;
};

struct School {
    std::set<Teacher> teachers;
    std::set<Student> students;
    std::set<Room> rooms;
    std::set<Class> classes;

    auto operator<=>(const School&) const = default;
};

bool isStudent(School school){
    for(Student stud : school.students){
        int inClasses = 0;
        for(Class clas : school.classes){
            if(clas.students.contains(stud)){
                inClasses++;
            }
        }
        if(inClasses != 1) return false;
    }
    return true;
}

bool isTimetable(School school){
    std::map<Room, std::set<TimetableSlot>> timeTa;
    for(Room room : school.rooms){
        std::set<TimetableSlot> timetable;
        auto [_, inserted] = timetable.insert(TimetableSlot{1, 1});
        
    }
    return false;
}

bool isTeacher(School school){
    return false;
}

/*
 * 1) Každý student je v právě jedné třídě                  ✓
 * 2) V každé učebně probíhá maximálně jedna výuka současně _
 * 3) Žádný vyučující neučí zaráz více věcí                 _
 */
bool is_valid(School school){
    return isStudent(school);
}

void test_is_valid() {
    // Test 1: Valid school
    {
        School school;
        Teacher teacher{"John Doe", 1};
        school.teachers.insert(teacher);

        Student student{"Alice", 101, 10};
        school.students.insert(student);

        Room room{"Room101"};
        school.rooms.insert(room);

        Subject math{"Math", teacher};
        TimetableSlot slot{1, 1};

        Class class1;
        class1.name = "10A";
        class1.students.insert(student);
        class1.timetable.insert({slot, std::make_tuple(math, room)});

        school.classes.insert(class1);

        assert(is_valid(school) && "Test 1 Failed: Valid school should be valid");
    }

    // Test 2: Student not assigned to any class (invalid)
    {
        School school;
        Teacher teacher{"John Doe", 1};
        school.teachers.insert(teacher);

        Student student{"Alice", 101, 10};
        school.students.insert(student);

        Room room{"Room101"};
        school.rooms.insert(room);

        // Create a class with no students.
        Class class1;
        class1.name = "10A";
        school.classes.insert(class1);

        // The student exists in school.students but is not in any class.
        assert(!is_valid(school) && "Test 2 Failed: Student not assigned to any class should be invalid");
    }

    // Test 3: Student in multiple classes (invalid)
    {
        School school;
        Teacher teacher{"John Doe", 1};
        school.teachers.insert(teacher);

        Student student{"Alice", 101, 10};
        school.students.insert(student);

        Room room1{"Room101"};
        Room room2{"Room102"};
        school.rooms.insert(room1);
        school.rooms.insert(room2);

        Subject math{"Math", teacher};
        Subject english{"English", teacher};

        TimetableSlot slot1{1, 1};
        TimetableSlot slot2{2, 1};

        Class class1;
        class1.name = "10A";
        class1.students.insert(student);
        class1.timetable.insert({slot1, std::make_tuple(math, room1)});

        Class class2;
        class2.name = "10B";
        class2.students.insert(student); // Same student added to another class.
        class2.timetable.insert({slot2, std::make_tuple(english, room2)});

        school.classes.insert(class1);
        school.classes.insert(class2);

        assert(!is_valid(school) && "Test 3 Failed: Student in multiple classes should be invalid");
    }

    // Test 4: Room conflict (same room and slot used by two classes, invalid)
    {
        School school;
        Teacher teacher{"John Doe", 1};
        school.teachers.insert(teacher);

        Student student1{"Alice", 101, 10};
        Student student2{"Bob", 102, 10};
        school.students.insert(student1);
        school.students.insert(student2);

        Room room{"Room101"};
        school.rooms.insert(room);

        Subject math{"Math", teacher};
        Subject english{"English", teacher};

        TimetableSlot slot{1, 1};

        Class class1;
        class1.name = "10A";
        class1.students.insert(student1);
        class1.timetable.insert({slot, std::make_tuple(math, room)});

        Class class2;
        class2.name = "10B";
        class2.students.insert(student2);
        // Conflict: same room and slot as class1.
        class2.timetable.insert({slot, std::make_tuple(english, room)});

        school.classes.insert(class1);
        school.classes.insert(class2);

        assert(!is_valid(school) && "Test 4 Failed: Room conflict should be invalid");
    }

    // Test 5: Teacher conflict (teacher teaching two lessons at the same time, invalid)
    {
        School school;
        Teacher teacher{"John Doe", 1};
        school.teachers.insert(teacher);

        Student student1{"Alice", 101, 10};
        Student student2{"Bob", 102, 10};
        school.students.insert(student1);
        school.students.insert(student2);

        Room room1{"Room101"};
        Room room2{"Room102"};
        school.rooms.insert(room1);
        school.rooms.insert(room2);

        Subject math{"Math", teacher};
        Subject english{"English", teacher};

        TimetableSlot slot{1, 1};

        Class class1;
        class1.name = "10A";
        class1.students.insert(student1);
        class1.timetable.insert({slot, std::make_tuple(math, room1)});

        Class class2;
        class2.name = "10B";
        class2.students.insert(student2);
        // Conflict: same time slot with the same teacher as class1.
        class2.timetable.insert({slot, std::make_tuple(english, room2)});

        school.classes.insert(class1);
        school.classes.insert(class2);

        assert(!is_valid(school) && "Test 5 Failed: Teacher conflict should be invalid");
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    test_is_valid();
    return 0;
}

