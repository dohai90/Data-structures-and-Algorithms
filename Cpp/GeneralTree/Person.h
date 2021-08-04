#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& personalInfo = "");
    ~Person();

    bool operator==(const Person& that) const;
    bool operator>(const Person& that) const;
    const string& name() const;
    const string& parent() const;
    const string& yob() const;
    const string& yod() const;
    const string& religion() const;
    const string& gender() const;

protected:
    void split(const string& str, char c, vector<string>& splitted_str);

private:
    string m_name;
    string m_parent;
    string m_yob;
    string m_yod;
    string m_religion;
    string m_gender;
};

#endif /* PERSON_H_ */