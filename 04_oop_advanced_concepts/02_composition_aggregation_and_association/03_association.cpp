/*
 * In object-oriented programming, association is the relationship between the unrelated objects of the
 * classes. Objects lifespan are not directly tied to each other like in composition and aggregation. To
 * clearly understand the concept of the association we'll take an example of student and techer class.
 * Example:
 * The teacher has a relationship with his students, but it's not a part-of relationship as in composition.
 * A teacher can add many students to a class, and a student can be registered in many courses. Neither of
 * the objects (teacher and student) lifespan is tied to the other as any student can leave the class of
 * specific teacher and similarly any teacher can change the course which he's currently teaching. 
*/
#include <iostream>
#include <vector>

class Teacher;

class Student{
private:
    std::string Std_name;
    std::vector<Teacher*> tr;
    void addTeacher(Teacher* teach);
    
public:
    Student(std::string name): Std_name(name) {}
    
    std::string getName() const {return Std_name;}
    
    friend std::ostream& operator<<(std::ostream& out, const Student& s);
    
    // Making Teacher friend to this class to access addTeacher function
    friend class Teacher;
};

class Teacher{
private:
    std::string tr_name;
    std::vector<Student*> stdnt;
    
public:
    Teacher(std::string name): tr_name(name) {}
    
    void addStudent(Student* s){
        // Teacher will add this student to course
        stdnt.push_back(s);
        
        // Student will also add this teacher for connection
        s->addTeacher(this);
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Teacher& t){
        size_t len = t.stdnt.size();
        if(len == 0){
            out << t.tr_name << " is not teaching any class";
            return out;
        }
        
        out << t.tr_name << " is teaching: ";
        for(size_t i{0}; i < len; ++i)
            out << t.stdnt[i]->getName() << " ";
        
        return out;
    }
    
    std::string getName() const {return tr_name;}
};

void Student::addTeacher(Teacher* t){
    tr.push_back(t);
}

std::ostream& operator<<(std::ostream& out, const Student& s){
    int length = s.tr.size();
	if (length == 0) {
		out << s.getName() << " is not registered in any course";
		return out;
	}
 
	out << s.Std_name << " is taught by: ";
	for (int count = 0; count < length; ++count)
		out << s.tr[count]->getName() << ' ';
 
	return out;
}


int main(){
	// Creating a Students outside the scope of the Teacher
	Student *s1 = new Student("John");
	Student *s2 = new Student("Stacy");
	Student *s3 = new Student("Sarah");
 
	Teacher *t1 = new Teacher("Henry");
	Teacher *t2 = new Teacher("Neil");
  	Teacher *t3 = new Teacher("Steve");

	t1->addStudent(s1);
	t2->addStudent(s1);
	t1->addStudent(s3);
 
	std::cout << *t1 << std::endl;
	std::cout << *t2 << std::endl;
  	std::cout << *t3 << std::endl;
	std::cout << *s1 << std::endl;
	std::cout << *s2 << std::endl;
	std::cout << *s3 << std::endl;
	
	delete s1, s2, s3, t1, t2, t3;


    return 0;
}
