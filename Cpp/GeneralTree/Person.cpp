#include "Person.h"

Person::Person(const string& personalInfo) {
    vector<string> splitted_str;
    split(personalInfo, ' ', splitted_str);
    if(splitted_str.size() == 6) {
        m_name = splitted_str.at(0);
        m_parent = splitted_str.at(1);
        m_yob = splitted_str.at(2);
        m_yod = splitted_str.at(3);
        m_religion = splitted_str.at(4);
        m_gender = splitted_str.at(5);
    }
}

Person::~Person() {}

bool Person::operator==(const Person& that) const {
    return m_name == that.m_name && m_parent == that.m_parent && m_yob == that.m_yob && m_yod == that.m_yod && m_religion == that.m_religion && m_gender == that.m_gender;
}

bool Person::operator>(const Person& that) const {
    if((m_gender == "M" && that.m_gender == "M" || m_gender == "F" && that.m_gender == "F") && (stoi(m_yob) < stoi(that.m_yob))) return true;
    else if(m_gender == "M" && that.m_gender == "F") return true;
    return false;
}

void Person::split(const string& str, char c, vector<string>& splitted_str) {
    size_t i = 0;
    size_t j = str.find(c);
    if(!splitted_str.empty()) splitted_str.clear();

    while(j != string::npos) {
        splitted_str.push_back(str.substr(i, j - i));
        i = ++j;
        j = str.find(c, i);
    }
    if(j == string::npos)
        splitted_str.push_back(str.substr(i));
}

const string& Person::name() const {
    return m_name;
}

const string& Person::parent() const {
    return m_parent;
}

const string& Person::yob() const {
    return m_yob;
}

const string& Person::yod() const {
    return m_yod;
}

const string& Person::religion() const {
    return m_religion;
}

const string& Person::gender() const {
    return m_gender;
}