/*
 * FinalReview2020.h
 *
 *  Created on: Nov 21, 2019
 *      Author: dpeters
 */

#ifndef FINALREVIEW2020_H_
#define FINALREVIEW2020_H_

#include <algorithm>
#include <cstring>
#include <ctime>
#include <functional> // std::reference_wrapper
#include <iostream>
#include <memory>
#include <sstream> // std::stringstream
#include <string>  // std::string
#include <vector>

namespace org {
namespace dgp {

/**
 * 100 TOTAL POINTS:
 *
 * Complete the implementation of this class
 * 1. Implement inner class MyFastPerson
 * 2. Implement inner class MySlowPerson
 * 3. Implement all class FinalReview2020 methods.
 */
class FinalReview2020 {
private:
  int id;
  std::string name;

  class MyPerson {
  private:
    int id;
    std::string name;
    double gpa;

  public:
    MyPerson() : id(1), name("Dan"), gpa(4.0) {}
    MyPerson(int _id, std::string _name, double _gpa)
        : id(_id), name(_name), gpa(_gpa) {}
    int getId() const { return id; }
    void setId(int id) { this->id = id; }
    const std::string &getName() const { return name; }
    void setName(const std::string &name) { this->name = name; }
    double getGpa() const { return gpa; }
    void setGpa(double gpa) { this->gpa = gpa; }

    const std::string toString() const {
      std::stringstream ss;

      ss << "#" << this->getId();
      ss << " " << this->getName();
      ss << ", having a GPA of " << this->getGpa();

      return ss.str();
    }
  };

  /**
   * inner class MyTimer class
   */
  class MyTimer {
  public:
    MyTimer() : m_start(std::clock()) {}

    ~MyTimer() {}

    operator double() const

    {
      return (std::clock() - m_start) / static_cast<double>(CLOCKS_PER_SEC);
    }

    double getTime() const {
      return (std::clock() - m_start) / static_cast<double>(CLOCKS_PER_SEC);
    }

    void reset() { m_start = std::clock(); }

  private:
    std::clock_t m_start;
  };

  /**
   * inner MyFastPerson class
   *
   * Complete the implementation
   * Include Move semantics for optimal performance
   *
   */
  class MyFastPerson {
  private:
    int id;
    std::string name;
    double gpa;

    size_t m_size; // size of heap allocation
    char *m_ptr;   // heap allocation optimized by move semantics

  public:
    /**
     * MyFastPerson with Move Semantics Implementation
     */
    MyFastPerson(MyFastPerson &&other)
        : id(other.id), name(std::move(other.name)), gpa(other.gpa),
          m_size(other.m_size), m_ptr(other.m_ptr) {
      other.m_ptr = nullptr;
      other.m_size = 0;
    }

  }; // end MyFastPerson class

  /**
   * inner MySlowPerson class
   *
   * Complete the implementation
   * Design with Value semantics for nominal performance
   */
  class MySlowPerson {
  private:
    int id;
    std::string name;
    double gpa;
    size_t m_size; // size of heap allocation
    char *m_ptr;   // heap allocation optimized by move semantics

  public:
    /**
     * MySlowPerson with Value Semantics Implementation
     */
    MySlowPerson(MySlowPerson &other)
        : id(other.id), name(other.name), gpa(other.gpa), m_size(other.m_size) {
      m_ptr = new char[m_size];
      std::memcpy(m_ptr, other.m_ptr, m_size);
    }

  }; // end MyPerson class

public:
  FinalReview2020() : id(0), name("default") {}
  FinalReview2020(int id, std::string name) : id(id), name(name) {}
  virtual ~FinalReview2020() {}

  int getId() const { return id; }
  void setId(int id) { this->id = id; }
  const std::string &getName() const { return name; }
  void setName(const std::string &name) { this->name = name; }
  /**
   * 3 POINTS
   *
   * Implement a Java style toString() method
   * which will return the current state of the object
   * in the form of a std::string
   */
  virtual const std::string toString() const {
    return "{ \"id\": " + std::to_string(id) + ", \"name\": \"" + name + "\"}";
  }

  /**
   * 5 POINTS
   *
   * The overloaded output operator method, i.e. operator<<()
   * has been granted access to all FinalReview2019 private members
   * because of the following 'friend' designation in class FinalReview2019.
   *
   * Overload the FinalReview2019 output operator
   * so output of the object is output of it's state.
   * NOTE: The overloaded output operator implementation
   * should call toString().
   */
  friend std::ostream &operator<<(std::ostream &out, FinalReview2020 &obj) {
    out << obj.toString();
    return out;
  }

  /**
   * 5 POINTS
   *
   * The overloaded output operator method, i.e. operator<<()
   * has been granted access to all FinalReview2019 private members
   * because of the following 'friend' designation in class FinalReview2019.
   *
   * Overload the MyPerson output operator
   * so output of the object is output of it's state.
   * NOTE: The overloaded output operator implementation
   * should call toString().
   */
  friend std::ostream &operator<<(std::ostream &out, MyPerson &obj) {
    out << obj.toString();
    return out;
  }

  /**
   * 16 POINTS
   *
   * instantiate FinalReview2019 objects:
   * 	1. on stack using default constructor;
   * 	2. on stack using parameterized constructor;
   * 	3. on heap using default constructor (free heap allocation after use);
   * 	4. on heap using parameterized constructor (free heap allocation after
   * use);
   * 	5. on heap (managed by std::unique_ptr<>) using default constructor;
   * 	6. on heap (managed by std::unique_ptr<>) using parameterized
   * constructor;
   * 	7. on heap (managed by std::shared_ptr<>) using default constructor;
   * 	8. on heap (managed by std::shared_ptr<>) using parameterized
   * constructor;
   *
   * 	Overload the output operator ( i.e. operator<<() ) and
   * 	implement toString() to return object state as a string.
   * 	demonstrate it's use by outputting the state of each created object.
   */
  void createObject() const {
    FinalReview2020 f1, f2(1, "Jinning 1"),
        *f3 = new FinalReview2020(), *f4 = new FinalReview2020(2, "Jinning 2");
    auto f5 = std::make_unique<FinalReview2020>(),
         f6 = std::make_unique<FinalReview2020>(3, "Jinning 3");
    auto f7 = std::make_shared<FinalReview2020>(),
         f8 = std::make_shared<FinalReview2020>(4, "Jinning 4");
    std::cout << f1 << '\n'
              << f2 << '\n'
              << *f3 << '\n'
              << *f4 << '\n'
              << *f5 << '\n'
              << *f6 << '\n'
              << *f7 << '\n'
              << *f8 << '\n';
    delete f3;
    delete f4;
  }

  /**
   * 3 POINTS
   *
   * demonstrate the use sort on a set of ints
   * and output the sorted result to the Console.
   */
  void sortInteger() const {
    std::array<int, 100> ints;
    std::srand(std::time(nullptr));
    std::for_each(ints.begin(), ints.end(), [](auto &x) { x = rand(); });
    std::sort(ints.begin(), ints.end());
    std::for_each(ints.begin(), ints.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::cout << '\n';
  }

  /**
   * 3 POINTS
   *
   * demonstrate the use sort on a set of strings
   * and output the sorted result to the Console.
   */
  void sortString() const {
    std::array<std::string, 100> strings;
    std::srand(std::time(nullptr));
    std::for_each(strings.begin(), strings.end(), [](auto &x) {
      int l = (rand() % 5) + 1;
      for (int i = 0; i < l; i++) {
        x += static_cast<char>(rand() % 26 + 'a');
      }
    });
    std::sort(strings.begin(), strings.end());
    std::for_each(strings.begin(), strings.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::cout << '\n';
  }

  /**
   * 6 POINTS
   *
   * demonstrate the use sort on a list of 3 MyPerson objects:
   * 	1. Sort MyPerson objects by ID
   * 	2. Sort MyPerson objects by Name
   * 	3. Sort MyPerson objects by GPA
   *
   * 	Overload the output operator ( i.e. operator<<() ) and
   * 	demonstrate it's use using it to perform all Console output.
   * You may use Lambda.
   *
   *
   */
  void sortPersons(std::vector<MyPerson> persons) const {
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1.getId() < x2.getId(); });
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::cout << '\n';
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1.getName() < x2.getName(); });
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::cout << '\n';
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1.getGpa() < x2.getGpa(); });
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::cout << '\n';
  }

  /**
   * 6 POINTS
   *
   * demonstrate the use sort on a list of 3 Pointers to MyPerson objects:
   * 	1. Sort MyPerson objects by ID
   * 	2. Sort MyPerson objects by Name
   * 	3. Sort MyPerson objects by GPA
   *
   * 	Overload the output operator ( i.e. operator<<() ) and
   * 	demonstrate it's use using it to perform all Console output.
   * You may use Lambda.
   *
   */
  void sortPersonPtrs(std::vector<MyPerson *> personPtrs) const {
    sort(personPtrs.begin(), personPtrs.end(),
         [](auto &x1, auto &x2) { return x1->getId() < x2->getId(); });
    std::for_each(personPtrs.begin(), personPtrs.end(),
                  [](auto &x) { std::cout << *x << ' '; });
    std::cout << '\n';
    sort(personPtrs.begin(), personPtrs.end(),
         [](auto &x1, auto &x2) { return x1->getName() < x2->getName(); });
    std::for_each(personPtrs.begin(), personPtrs.end(),
                  [](auto &x) { std::cout << *x << ' '; });
    std::cout << '\n';
    sort(personPtrs.begin(), personPtrs.end(),
         [](auto &x1, auto &x2) { return x1->getGpa() < x2->getGpa(); });
    std::for_each(personPtrs.begin(), personPtrs.end(),
                  [](auto &x) { std::cout << *x << ' '; });
    std::cout << '\n';
  }

  /**
   * 6 POINTS
   *
   * demonstrate the use sort on a list of 3 References to MyPerson objects:
   * 	1. Sort MyPerson objects by ID
   * 	2. Sort MyPerson objects by Name
   * 	3. Sort MyPerson objects by GPA
   * You may use Lambda.
   */
  void sortPersonRefs(
      std::vector<std::reference_wrapper<MyPerson>> personRefs) const {
    sort(personRefs.begin(), personRefs.end(), [](auto &x1, auto &x2) {
      return x1.get().getId() < x2.get().getId();
    });
    std::for_each(personRefs.begin(), personRefs.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::cout << '\n';
    sort(personRefs.begin(), personRefs.end(), [](auto &x1, auto &x2) {
      return x1.get().getName() < x2.get().getName();
    });
    std::for_each(personRefs.begin(), personRefs.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::cout << '\n';
    sort(personRefs.begin(), personRefs.end(), [](auto &x1, auto &x2) {
      return x1.get().getGpa() < x2.get().getGpa();
    });
    std::for_each(personRefs.begin(), personRefs.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::cout << '\n';
  }

  /**
   * 6 POINTS
   *
   * demonstrate the use sort on a list of 3 heap allocated MyPerson objects.
   * Use std::unique_ptr<> to manage each heap allocated MyPerson object.
   * You may use Lambda.
   *
   * 	1. Sort MyPerson objects by ID
   * 	2. Sort MyPerson objects by Name
   * 	3. Sort MyPerson objects by GPA
   *
   */
  void
  sortPersonUniquePtrs(std::vector<std::unique_ptr<MyPerson>> &persons) const {
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1->getId() < x2->getId(); });
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << *x << ' '; });
    std::cout << '\n';
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1->getName() < x2->getName(); });
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << *x << ' '; });
    std::cout << '\n';
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1->getGpa() < x2->getGpa(); });
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << *x << ' '; });
    std::cout << '\n';
  }

  /**
   * 6 POINTS
   *
   * demonstrate the use sort on a list of 3 heap allocated MyPerson objects.
   * Use std::shared_ptr<> to manage each heap allocated MyPerson object.
   * You may use Lambda.
   *
   * 	1. Sort MyPerson objects by ID
   * 	2. Sort MyPerson objects by Name
   * 	3. Sort MyPerson objects by GPA
   *
   */
  void sortPersonSharedPtrs(
      std::vector<std::shared_ptr<MyPerson>> personSharedPtrs) const {
    sort(personSharedPtrs.begin(), personSharedPtrs.end(),
         [](auto &x1, auto &x2) { return x1->getId() < x2->getId(); });
    std::for_each(personSharedPtrs.begin(), personSharedPtrs.end(),
                  [](auto &x) { std::cout << *x << ' '; });
    std::cout << '\n';
    sort(personSharedPtrs.begin(), personSharedPtrs.end(),
         [](auto &x1, auto &x2) { return x1->getName() < x2->getName(); });
    std::for_each(personSharedPtrs.begin(), personSharedPtrs.end(),
                  [](auto &x) { std::cout << *x << ' '; });
    std::cout << '\n';
    sort(personSharedPtrs.begin(), personSharedPtrs.end(),
         [](auto &x1, auto &x2) { return x1->getGpa() < x2->getGpa(); });
    std::for_each(personSharedPtrs.begin(), personSharedPtrs.end(),
                  [](auto &x) { std::cout << *x << ' '; });
    std::cout << '\n';
  }

  /**
   * 5 POINTS
   *
   * demonstrate the use of Transform on a set of integer values.
   * Use Lambda to scale each integer by 100.
   */
  void transformInteger() const {
    std::array<int, 100> ints;
    std::srand(std::time(nullptr));
    std::for_each(ints.begin(), ints.end(), [](auto &x) { x = rand() % 10; });
    std::transform(ints.begin(), ints.end(), ints.begin(),
                   [](auto &x) { return x * 100; });
    std::for_each(ints.begin(), ints.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::cout << '\n';
  }

  /**
   * 5 POINTS
   *
   * demonstrate the use of Transform on a set of double values.
   * Use Lambda to scale each integer by 100.
   */
  void transformDouble() const {
    std::array<double, 100> ints;
    std::srand(std::time(nullptr));
    std::for_each(ints.begin(), ints.end(),
                  [](auto &x) { x = 1.0 * rand() / RAND_MAX; });
    std::transform(ints.begin(), ints.end(), ints.begin(),
                   [](auto &x) { return x * 100; });
    std::for_each(ints.begin(), ints.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::cout << '\n';
  }

  /**
   * 5 POINTS
   *
   * demonstrate the parsing of a std::string containing 3 CSV tokens.
   * 	1. Show parsing and conversion of an integer value.
   * 	2. Show parsing and conversion of an string value.
   * 	3. Show parsing and conversion of an double value.
   *
   * 	Parse each token and convert it to its appropriate data type.
   *
   * 	NOTE: no file i/o, use a literal string as your CSV data,
   * 	"1,Dan,4.0"
   *
   */
  void parseString(std::string input = "1,Dan,4.0") const {
    std::istringstream i(input);
    std::string s;
    std::getline(i, s, ',');
    int a = std::stoi(s);
    std::getline(i, s, ',');
    std::string b = s;
    std::getline(i, s, ',');
    double c = std::stod(s);
    std::cout << "CSV: A = " << a << ", B = " << b << ", C = " << c << '\n';
  }

  /**
   * 10 POINTS
   *
   * Demonstrate Move Semantics
   */
  void demoMoveSemantics() {
    std::string a = "string";
    std::string b(std::move(a));
    std::cout << "After the move, string is: " << a << '\n';
  }

  /**
   * 10 POINTS
   *
   * Demonstrate Value Semantics
   */
  void demoValueSemantics() {
    std::string a = "string";
    std::string b(a);
    std::cout << "After copy constructor, string is: " << a << '\n';
  }

  /*
   * Demonstrate the use of the methods in this class
   */
  static void demo() {
    FinalReview2020 f;
    f.createObject();
    f.sortInteger();
    f.sortString();
    {
      std::vector<MyPerson> persons;
      persons.emplace_back(1, "b", 3);
      persons.emplace_back(2, "a", 2);
      persons.emplace_back(3, "c", 1);
      f.sortPersons(persons);
    }
    {
      std::vector<MyPerson *> persons;
      persons.emplace_back(new MyPerson(1, "b", 3));
      persons.emplace_back(new MyPerson(2, "a", 2));
      persons.emplace_back(new MyPerson(3, "c", 1));
      f.sortPersonPtrs(persons);
      std::for_each(persons.begin(), persons.end(), [](auto &x) { delete x; });
    }
    {
      std::vector<MyPerson> persons;
      persons.emplace_back(1, "b", 3);
      persons.emplace_back(2, "a", 2);
      persons.emplace_back(3, "c", 1);
      std::vector<std::reference_wrapper<MyPerson>> _persons(persons.begin(),
                                                             persons.end());
      f.sortPersonRefs(_persons);
    }
    {
      std::vector<std::unique_ptr<MyPerson>> persons;
      persons.emplace_back(std::move(new MyPerson(1, "b", 3)));
      persons.emplace_back(std::move(new MyPerson(2, "a", 2)));
      persons.emplace_back(std::move(new MyPerson(3, "c", 1)));
      f.sortPersonUniquePtrs(persons);
    }
    {
      std::vector<std::shared_ptr<MyPerson>> persons;
      persons.emplace_back(std::make_shared<MyPerson>(1, "b", 3));
      persons.emplace_back(std::make_shared<MyPerson>(2, "a", 2));
      persons.emplace_back(std::make_shared<MyPerson>(3, "c", 1));
      f.sortPersonSharedPtrs(persons);
    }
    f.transformInteger();
    f.transformDouble();
    f.parseString();
    f.demoMoveSemantics();
    f.demoValueSemantics();
  }
};

} /* namespace dgp */
} /* namespace org */

#endif /* FINALREVIEW2020_H_ */

int main() {
  org::dgp::FinalReview2020::demo();
  return 0;
}