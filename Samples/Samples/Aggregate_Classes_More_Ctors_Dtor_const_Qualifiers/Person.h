#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

const int DEFAULT_AGE = 0;

const char DEFAULT_GENDER = '-';

const char GENDER_MALE = 'M';
const char GENDER_FEMALE = 'F';

class Person{

  friend std::ostream& operator<<(std::ostream& os, const Person& person);
  friend std::istream& operator>>(std::istream& is, Person& person);

  public:
    Person();
    Person(const char* name, int age=DEFAULT_AGE, char gender=DEFAULT_GENDER);
    Person(const Person& other);
   
    ~Person();

    Person& operator=(const Person& rhs);  

    Person& operator+(int years); 
    Person& operator+(const char *name_suffix); 

    const char* GetName() const;
    void SetName(const char* name);
    int GetAge() const;
    void SetAge(int age);
    char GetGender() const;
    void SetGender(char gender);

    static int GetCount();   

  private:
    bool ParameterValidation() const;
    char m_name[255];
    int m_age;
    /*const*/ char m_gender;
    
    static int s_count;
};

#endif //PERSON_H_

