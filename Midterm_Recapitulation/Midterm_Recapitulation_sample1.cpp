#include <iostream>

using namespace std;


/*
 * Write your own C-string manipulation functions - note: these do not handle NULL pointer cases
 */
void strcpy(char * dst, const char * src){
  while (*dst++ = *src++);
}

int strcmp(const char * s1, const char * s2){
  while (*s1 == *s2++){
    if (!*s1++){
      return 0;
    }
  }
  return *s1 - *--s2;
}

int strlen(const char* str){
  const char * s = str;
  for( ; *s; ++s); 
  return s - str;
}


/*
 * Write your own array manipulation functions - note: these do not handle NULL pointer cases
 */
void intcpy(int* dst, const int* src, int size)
{
  while (--size>=0){
    *dst++ = *src++;
  }
}

int intcmp(const int * arr1, const int * arr2, int size){
  while (--size>=0){
    int res = *arr1++ - *arr2++;
    if (res){
      return res; 
    }
  }
  return 0;
}

void intprint(std::ostream& os, const int* arr, int size)
{
 while (--size>=0){
   os << *arr++;
 }
}


/*
 * Write your own Class
 */
const int STR_MAX = 255, ID_LEN = 5, NUM_GRADES = 10;
const double INVALID_GPA = -1.0; const int INVALID_REGISTRATION = -1;
const char* DEFAULT_NAME = "none"; const int DEFAULT_ID[] = {0,0,0,0,0};

class Student {

  friend ostream& operator<<(ostream& os, const Student& st); 

  public:
    Student();
    Student(int registration, const char *name=DEFAULT_NAME, const int *id=DEFAULT_ID, double gpa=INVALID_GPA);
    Student(const Student &other_st);
    int GetRegistration() const;
    void SetName(const char* name);
    const char* GetName() const;
    void SetId(const int* id);
    const int* GetId() const;
    void PrintId(ostream& os) const;
    void SetGrade(const double grade, const int grade_idx);
    double GetGrade(const int grade_idx) const;
    void CalculateGPA();
    double GetGPA() const;
    void Print() const;

  private:
    /*const*/ int m_registration;
    char m_name[STR_MAX];
    int m_id[ID_LEN];
    double m_grades[NUM_GRADES];
    double m_gpa;
};

Student::Student()
  : m_registration(INVALID_REGISTRATION),
    m_gpa(INVALID_GPA)
{
  SetName(DEFAULT_NAME);
  SetId(DEFAULT_ID);
}

Student::Student(int registration, const char *name, const int *id, double gpa) 
  : m_registration(registration),
    m_gpa(gpa)
{
  SetName(name);
  SetId(id);
}

Student::Student(const Student &other) 
  : m_registration(other.m_registration),
    m_gpa(other.m_gpa)
{
  SetName(other.m_name);
  SetId(other.m_id);
  double *m_grades_Pt = m_grades;
  const double* other_grades_Pt = other.m_grades;
  for (int i=0; i<NUM_GRADES; ++i){
    *m_grades_Pt = *other_grades_Pt;
    ++m_grades_Pt;
    ++other_grades_Pt;
  }
}


int Student::GetRegistration() const{
 return m_registration;
}

void Student::SetName(const char* name){
  strcpy(m_name,name);
}

const char* Student::GetName() const{
  return m_name;
}

void Student::SetId(const int* id){
  intcpy(m_id, id, ID_LEN);
}

const int* Student::GetId() const{
  return m_id;
}

void Student::PrintId(ostream& os) const{
  intprint(os, m_id, ID_LEN);
}

void Student::SetGrade(const double grade, const int grade_idx){
  double *m_grades_Pt = m_grades;
  for (int i=0; i<grade_idx; ++i){
    ++m_grades_Pt;
  }
  *m_grades_Pt = grade;
}

double Student::GetGrade(const int grade_idx) const{
  const double *m_grades_Pt = m_grades;
  for (int i=0; i<grade_idx; ++i){
    ++m_grades_Pt;
  }
  return *m_grades_Pt;
}

void Student::CalculateGPA(){
  m_gpa = 0;
  double *m_grades_Pt = m_grades;
  for (int i=0; i<NUM_GRADES; ++i){
    m_gpa += *m_grades_Pt;
    ++m_grades_Pt;
  }
  m_gpa /= NUM_GRADES;
}

double Student::GetGPA() const{
  return m_gpa;
}

ostream& operator<<(ostream& os, const Student& st){
  os << st.m_name << " ";
  st.PrintId(os);
  os << " {";
  const double *m_grades_Pt = st.m_grades;
  for (int i=0; i<NUM_GRADES; ++i){
    os << " " << *m_grades_Pt;
    ++m_grades_Pt;
  }
  os << " } " << st.m_gpa;
  return os;
}


/*
 * Write your own Aggregate Class
 */
const int COURSE_INVALID_ENTRY=-1, COURSE_MAX_STUDENTS=135; 
const char* COURSE_DEFAULT_NAME = "none";

class Course {

 friend ostream& operator<<(ostream& os, const Course& crs); 

 public:

  Course();
  Course(int catalog_number, const char* name=COURSE_DEFAULT_NAME, bool offered=false);
  Course(const Course& other_crs);
  int GetCatalogNumber() const;
  void SetName(const char* name);
  const char* GetName() const;
  Student* operator[](const char* name);
  Student& operator[](int index);
  bool operator+(const Student& st);

 private:

  const int m_catalog_number;
  char m_name[STR_MAX];
  Student m_students[COURSE_MAX_STUDENTS];
  bool m_offered; 
};

Course::Course()
  : m_catalog_number(COURSE_INVALID_ENTRY)
{
  SetName(COURSE_DEFAULT_NAME);
  m_offered = false;
}

Course::Course(int catalog_number, const char* name, bool offered)
  : m_catalog_number(catalog_number)
{
  SetName(name);
  m_offered = offered;
}

Course::Course(const Course& other)
  : m_catalog_number(other.m_catalog_number)
{
  SetName(other.m_name);
  Student *m_students_Pt = m_students;
  const Student *other_students_Pt = other.m_students;
  for (int i=0; i<COURSE_MAX_STUDENTS; ++i){
    *m_students_Pt = *other_students_Pt;
    ++m_students_Pt;
    ++other_students_Pt;
  } 
  m_offered = other.m_offered;
}

void Course::SetName(const char* name){
  strcpy(m_name,name);
}

const char* Course::GetName() const{
  return m_name;
}

Student* Course::operator[](const char* name){
  Student *m_students_Pt = m_students;
  for (int i=0; i<COURSE_MAX_STUDENTS; ++i){
    if ( !strcmp(m_students_Pt->GetName(), name) ){
      return m_students_Pt;    
    }
    ++m_students_Pt;
  }
  return NULL;
}

Student& Course::operator[](int index){
  return m_students[index];
}

bool Course::operator+(const Student& st){
  Student* empty_student_Pt = this->operator[]("none");
  if (empty_student_Pt && 
      st.GetRegistration()!=INVALID_REGISTRATION && 
      intcmp(st.GetId(), DEFAULT_ID, ID_LEN)){
    *empty_student_Pt = st;
    return true;
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, const Course& crs){
  const Student *m_students_Pt = crs.m_students;
  for (int i=0; i<COURSE_MAX_STUDENTS; ++i){
    if ( !strcmp(m_students_Pt->GetName(), "none") ||
	 m_students_Pt->GetRegistration()==INVALID_REGISTRATION ||
 	 !intcmp(m_students_Pt->GetId(), DEFAULT_ID, ID_LEN) ){
      // invalid / uninitialized / wrongly formatted student
    }
    else{
      os << i << "-th Student: " << *m_students_Pt << endl;
    } 

    ++m_students_Pt;
  }
  return os;
}


int main(){

  // Create class Course object
  Course cs202(202, "CS-202", true);
  cout << "CS-202 Students (1):" << endl;
  cout << cs202 << endl;  //Should print out nothing (no valid Student objects found in the m_students array of the calling Course object cs202)

  // Create class Student object
  int myId[] = {3,1,4,1,5};
  Student me(314159265, "Christos Papachristos", myId); //INVALID_GPA
   
  // Use operator+ on Course object to "add" a Student object if an "empy" position (an invalid object) is found in the m_students array
  bool addToCourseFlag = cs202 + me;  
  if (addToCourseFlag){  //Check if succeded (true/false)
    cout << "SUCCESS" << endl;  
  }
  cout << "CS-202 Students (2):" << endl;
  cout << cs202 << endl;  //Should print out the just-added (valid) Student in the m_students array of the calling Course object cs202
  
  // Use operator[] on Course object to "find" a Student object by name (should return a non-NULL pointer since the object should have been successfully added before)
  // Then perform some functions on that object (Note: it was returned by-Address, so it will modify the actual object within the m_students array of the cs202 Course object)
  Student* christos_Pt = cs202["Christos Papachristos"];
  if (christos_Pt){
    christos_Pt->SetGrade(10,0);
    christos_Pt->SetGrade(9,1);
    christos_Pt->SetGrade(7,2);
    christos_Pt->SetGrade(8,3);
    christos_Pt->SetGrade(10,4);
    christos_Pt->SetGrade(6,5);
    christos_Pt->SetGrade(8,6);
    christos_Pt->SetGrade(9,7);
    christos_Pt->SetGrade(8,8);
    christos_Pt->SetGrade(6,9);
    christos_Pt->CalculateGPA();
  }
  cout << "CS-202 Students (3):" << endl; 
  cout << cs202 << endl;  //Should print out the just-modified data of the (valid) Student in the m_students array of the calling Course object cs202

  return 0;
}
