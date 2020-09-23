#include <cassert>
#include <stdexcept>

// TODO: Define "Student" class
class Student {
 public:
  // constructor
  //Student() = default; // will instruct the compiler to create default constructor
  Student(std::string _name, int _grade, float _GPA);
  // accessors
  std::string name() const;
  int grade() const;
  float GPA() const;
  // mutators
  void name(std::string _name);
  void grade(int _grade);
  void GPA(float _GPA);

 private:
    std::string name_;// name
    int grade_;// grade
    float GPA_;// GPA
};
Student::Student(std::string _name, int _grade, float _GPA)
{
    name(_name);
    grade(_grade);
    GPA(_GPA);
}
void Student::name(std::string _name){
    name_ = _name;
}
void Student::grade(int _grade){
    if((_grade>=0) && (_grade<12))
        grade_ = _grade;
    else
        throw 255;
    
}
void Student::GPA(float _GPA){
    if((_GPA>=0.0) && (_GPA<=4.0))
        GPA_ = _GPA;
    else
        throw 255;    
}

std::string Student::name() const{
    return Student::name_;
}
int Student::grade() const{
    return Student::grade_;
}
float Student::GPA() const{
    return Student::GPA_;
}
// TODO: Test
int main() {
    //Student st2; //need to instruct to create default
    Student st1("Nishin", 8, 3.34);
    st1.GPA(2.5);
    st1.grade(9);
    assert(st1.name() == "Nishin");
    assert(st1.grade() == 9);
    assert(st1.GPA() == 2.5);

    bool caught{false};
    try{
        Student("ABCD", -1, 2.2);
    }
    catch(...){
        caught = true;
    }
    assert(caught);
}