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
    MyFastPerson() = default;
    const std::string getName() {
        return name;
    }
    void setName(std::string&& name) {
        this->name = std::move(name);
    }
    void setName(std::string &name) {
        this->name = name;
    }
    int getId() {
        return this->id;
    }
    void setId(int id) {
        this->id = id;
    }
    void setGpa(double gpa) {
        this->gpa = gpa;
    }
    double getGpa() {
        return gpa;
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
    size_t m_size = 0; // size of heap allocation
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


    MySlowPerson() = default;

    const std::string getName() {
        return name;
    }
    void setName(std::string&& name) {
        this->name = std::move(name);
    }
    void setName(std::string &name) {
        this->name = name;
    }
    int getId() {
        return this->id;
    }
    void setId(int id) {
        this->id = id;
    }
    void setGpa(double gpa) {
        this->gpa = gpa;
    }
    double getGpa() {
        return gpa;
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
    std::cout << "Sort by ID:\n";
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << x << '\n'; });
    std::cout << '\n';
    std::cout << "Sort by Name:\n";
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1.getName() < x2.getName(); });
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << x << '\n'; });
    std::cout << '\n';
    std::cout << "Sort by GPA:\n";
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1.getGpa() < x2.getGpa(); });
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << x << '\n'; });
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
    std::cout << "Sort by ID:\n";
    std::for_each(personPtrs.begin(), personPtrs.end(),
                  [](auto &x) { std::cout << *x << '\n'; });
    std::cout << '\n';
    std::cout << "Sort by Name:\n";
    sort(personPtrs.begin(), personPtrs.end(),
         [](auto &x1, auto &x2) { return x1->getName() < x2->getName(); });
    std::for_each(personPtrs.begin(), personPtrs.end(),
                  [](auto &x) { std::cout << *x << '\n'; });
    std::cout << '\n';
    std::cout << "Sort by GPA:\n";
    sort(personPtrs.begin(), personPtrs.end(),
         [](auto &x1, auto &x2) { return x1->getGpa() < x2->getGpa(); });
    std::for_each(personPtrs.begin(), personPtrs.end(),
                  [](auto &x) { std::cout << *x << '\n'; });
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
    std::cout << "Sort by ID:\n";
    std::for_each(personRefs.begin(), personRefs.end(),
                  [](auto &x) { std::cout << x << '\n'; });
    std::cout << '\n';
    std::cout << "Sort by Name:\n";
    sort(personRefs.begin(), personRefs.end(), [](auto &x1, auto &x2) {
      return x1.get().getName() < x2.get().getName();
    });
    std::for_each(personRefs.begin(), personRefs.end(),
                  [](auto &x) { std::cout << x << '\n'; });
    std::cout << '\n';
    std::cout << "Sort by GPA:\n";
    sort(personRefs.begin(), personRefs.end(), [](auto &x1, auto &x2) {
      return x1.get().getGpa() < x2.get().getGpa();
    });
    std::for_each(personRefs.begin(), personRefs.end(),
                  [](auto &x) { std::cout << x << '\n'; });
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
  void sortPersonUniquePtrs(std::vector<std::unique_ptr<MyPerson>> &persons) const {
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1->getId() < x2->getId(); });
    std::cout << "Sort by ID:\n";
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << *x << '\n'; });
    std::cout << '\n';
    std::cout << "Sort by Name:\n";
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1->getName() < x2->getName(); });
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << *x << '\n'; });
    std::cout << '\n';
    std::cout << "Sort by GPA:\n";
    sort(persons.begin(), persons.end(),
         [](auto &x1, auto &x2) { return x1->getGpa() < x2->getGpa(); });
    std::for_each(persons.begin(), persons.end(),
                  [](auto &x) { std::cout << *x << '\n'; });
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
    std::cout << "Sort by ID:\n";
    std::for_each(personSharedPtrs.begin(), personSharedPtrs.end(),
                  [](auto &x) { std::cout << *x << '\n'; });
    std::cout << '\n';
    std::cout << "Sort by Name:\n";
    sort(personSharedPtrs.begin(), personSharedPtrs.end(),
         [](auto &x1, auto &x2) { return x1->getName() < x2->getName(); });
    std::for_each(personSharedPtrs.begin(), personSharedPtrs.end(),
                  [](auto &x) { std::cout << *x << '\n'; });
    std::cout << '\n';
    std::cout << "Sort by GPA:\n";
    sort(personSharedPtrs.begin(), personSharedPtrs.end(),
         [](auto &x1, auto &x2) { return x1->getGpa() < x2->getGpa(); });
    std::for_each(personSharedPtrs.begin(), personSharedPtrs.end(),
                  [](auto &x) { std::cout << *x << '\n'; });
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
    std::cout << "Before Transform:\n";
    std::for_each(ints.begin(), ints.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::transform(ints.begin(), ints.end(), ints.begin(),
                   [](auto &x) { return x * 100; });
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "After Transform:\n";
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
    std::cout << "Before Transform:\n";
    std::for_each(ints.begin(), ints.end(),
                  [](auto &x) { std::cout << x << ' '; });
    std::transform(ints.begin(), ints.end(), ints.begin(),
                   [](auto &x) { return x * 100; });
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "After Transform:\n";
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
    std::cout << "CSV: Id = " << a << ", Name = " << b << ", GPA = " << c << '\n';
  }

  /**
   * 10 POINTS
   *
   * Demonstrate Move Semantics
   */
  void demoMoveSemantics() {
    MyFastPerson mfp;
    mfp.setName("Colin");
    std::cout << "Before the move, mfp1's name = " << mfp.getName() << '\n';
    MyFastPerson mfp2(std::move(mfp));
    std::cout << "After the move, mfp1's name = " << mfp.getName() << ", mfp2's name = " << mfp2.getName() << '\n';
    std::cout << '\n';
    //Another Case
    std::string a="string";
    std::cout << "Before the move, string is: " <<a<<'\n';
    std::string b(std::move(a));
    std::cout << "After the move, string is: "<<a<< '\n';
  }

  /**
   * 10 POINTS
   *
   * Demonstrate Value Semantics
   */
  void demoValueSemantics() {
    MySlowPerson msp;
    msp.setName("Daniel");
    std::cout << "Before, msp1's name = " << msp.getName() << '\n';
    MySlowPerson msp2(msp);
    std::cout << "After copy constructor, msp1's name = " << msp.getName() << ", mp2's name = " << msp2.getName() << '\n';
    //Another case
    std::cout << '\n';
    std::string s("string");
    std::cout << "Before, s= " <<s<< '\n';
    std::string s2(s);
    std::cout << "After copy constructor s = " << s <<", s2 = " << s2 << '\n';
  }

  /*
   * Demonstrate the use of the methods in this class
   */
  static void demo() {
    auto bar = [](){std::cout << "================================================================================\n";};
    bar();
    std::cout << "New FinalReview2020 object on stack\n";
    FinalReview2020 f;
    bar();
    std::cout << "Creation of Objects\n";
    f.createObject();
    bar();
    std::cout << "Sort Integers\n";
    f.sortInteger();
    bar();
    std::cout << "Sort Strings\n";
    f.sortString();
    bar();
    std::cout << "Sort persons directly\n";
    {
      std::vector<MyPerson> persons;
      persons.emplace_back(1, "b", 3);
      persons.emplace_back(2, "a", 2);
      persons.emplace_back(3, "c", 1);
      f.sortPersons(persons);
    }
    bar();
    std::cout << "Sort persons by their ptrs.\n";
    {
      std::vector<MyPerson *> persons;
      persons.emplace_back(new MyPerson(1, "b", 3));
      persons.emplace_back(new MyPerson(2, "a", 2));
      persons.emplace_back(new MyPerson(3, "c", 1));
      f.sortPersonPtrs(persons);
      std::for_each(persons.begin(), persons.end(), [](auto &x) { delete x; });
    }
    bar();
    std::cout << "Sort persons by reference wrappers.\n";
    {
      std::vector<MyPerson> persons;
      persons.emplace_back(1, "b", 3);
      persons.emplace_back(2, "a", 2);
      persons.emplace_back(3, "c", 1);
      std::vector<std::reference_wrapper<MyPerson>> _persons(persons.begin(),
                                                             persons.end());
      f.sortPersonRefs(_persons);
    }
    bar();
    std::cout << "Sort persons by unique_ptrs.\n";
    {
      std::vector<std::unique_ptr<MyPerson>> persons;
      persons.emplace_back(std::move(new MyPerson(1, "b", 3)));
      persons.emplace_back(std::move(new MyPerson(2, "a", 2)));
      persons.emplace_back(std::move(new MyPerson(3, "c", 1)));
      f.sortPersonUniquePtrs(persons);
    }
    bar();
    std::cout << "Sort persons by shared_ptrs.\n";
    {
      std::vector<std::shared_ptr<MyPerson>> persons;
      persons.emplace_back(std::make_shared<MyPerson>(1, "b", 3));
      persons.emplace_back(std::make_shared<MyPerson>(2, "a", 2));
      persons.emplace_back(std::make_shared<MyPerson>(3, "c", 1));
      f.sortPersonSharedPtrs(persons);
    }
    bar();
    std::cout << "Transform integers\n";
    f.transformInteger();
    bar();
    std::cout << "Transform doubles\n";
    f.transformDouble();
    bar();
    std::cout << "Parse strings\n";
    f.parseString();
    bar();
    std::cout << "Demonstrate move schematics.\n";
    f.demoMoveSemantics();
    bar();
    std::cout << "Demonstrate value schematics.\n";
    f.demoValueSemantics();
    bar();
  }
};

} /* namespace dgp */
} /* namespace org */

#endif /* FINALREVIEW2020_H_ */

int main() {
  org::dgp::FinalReview2020::demo();
  return 0;
}
//================================================================================
//New FinalReview2020 object on stack
//================================================================================
//Creation of Objects
//{ "id": 0, "name": "default"}
//{ "id": 1, "name": "Jinning 1"}
//{ "id": 0, "name": "default"}
//{ "id": 2, "name": "Jinning 2"}
//{ "id": 0, "name": "default"}
//{ "id": 3, "name": "Jinning 3"}
//{ "id": 0, "name": "default"}
//{ "id": 4, "name": "Jinning 4"}
//================================================================================
//Sort Integers
//597 1377 1443 1592 1902 2188 2342 2717 2776 3198 3962 5418 5602 5836 5980 6217 6222 6284 6305 6691 6717 6788 7370 7382 7423 7441 7572 8028 8281 8582 8873 9237 9274 10220 10266 10357 10466 10989 11091 11533 11818 12349 12734 12735 12777 12911 13778 13851 14649 15749 15755 16018 16529 17568 17681 18010 18015 18164 18557 19112 19205 19245 19307 19722 19880 20699 20742 21247 21999 22155 23144 23195 23265 23358 23484 23583 25897 26073 26218 26470 26484 26856 27122 27400 28202 28424 29022 29149 29258 29375 29597 30168 30657 31136 31156 31333 31465 31792 32041 32735
//================================================================================
//Sort Strings
//a aadl aar agq asjb avdz awoa budd bv c c campb cbvpg ce cksz cnub cpf dis dr e elifi er etft fb fx gew gm h h heui hf i iqst j jgm jgyjb jp jt kaou kdf kjfmk l lmxue lq m md mo n ntu nyjg o omjhv on otisi owbyb owl ox p pn ptpwr ptq pycd q q qggww qi qk qtsa r r rkxc rr rvofj s s s sbt sdm spwjy tmrf tplz tquz uars utynr v vce violu wkt wl wypw xr xsmfe xwtvs yb yfgo yh yhj znjpy zrihz zwn
//================================================================================
//Sort persons directly
//Sort by ID:
//#1 b, having a GPA of 3
//#2 a, having a GPA of 2
//#3 c, having a GPA of 1

//Sort by Name:
//#2 a, having a GPA of 2
//#1 b, having a GPA of 3
//#3 c, having a GPA of 1

//Sort by GPA:
//#3 c, having a GPA of 1
//#2 a, having a GPA of 2
//#1 b, having a GPA of 3
//
//================================================================================
//Sort persons by their ptrs.
//Sort by ID:
//#1 b, having a GPA of 3
//#2 a, having a GPA of 2
//#3 c, having a GPA of 1
//
//Sort by Name:
//#2 a, having a GPA of 2
//#1 b, having a GPA of 3
//#3 c, having a GPA of 1
//
//Sort by GPA:
//#3 c, having a GPA of 1
//#2 a, having a GPA of 2
//#1 b, having a GPA of 3
//
//================================================================================
//Sort persons by reference wrappers.
//Sort by ID:
//#1 b, having a GPA of 3
//#2 a, having a GPA of 2
//#3 c, having a GPA of 1
//
//Sort by Name:
//#2 a, having a GPA of 2
//#1 b, having a GPA of 3
//#3 c, having a GPA of 1
//
//Sort by GPA:
//#3 c, having a GPA of 1
//#2 a, having a GPA of 2
//#1 b, having a GPA of 3
//
//================================================================================
//Sort persons by unique_ptrs.
//Sort by ID:
//#1 b, having a GPA of 3
//#2 a, having a GPA of 2
//#3 c, having a GPA of 1
//
//Sort by Name:
//#2 a, having a GPA of 2
//#1 b, having a GPA of 3
//#3 c, having a GPA of 1
//
//Sort by GPA:
//#3 c, having a GPA of 1
//#2 a, having a GPA of 2
//#1 b, having a GPA of 3
//
//================================================================================
//Sort persons by shared_ptrs.
//Sort by ID:
//#1 b, having a GPA of 3
//#2 a, having a GPA of 2
//#3 c, having a GPA of 1
//
//Sort by Name:
//#2 a, having a GPA of 2
//#1 b, having a GPA of 3
//#3 c, having a GPA of 1
//
//Sort by GPA:
//#3 c, having a GPA of 1
//#2 a, having a GPA of 2
//#1 b, having a GPA of 3
//
//================================================================================
//Transform integers
//Before Transform:
//0 5 6 0 5 5 6 5 8 8 1 4 1 7 0 5 5 6 8 2 1 9 9 2 9 9 3 4 3 8 4 4 0 3 1 8 1 9 3 5 0 0 1 4 1 8 2 5 6 9 6 8 1 8 1 8 8 5 3 9 6 0 2 5 3 7 5 5 3 7 1 8 1 2 7 3 6 0 1 2 6 2 7 0 5 4 4 6 4 2 8 9 4 0 8 5 7 5 2 0
//
//After Transform:
//0 500 600 0 500 500 600 500 800 800 100 400 100 700 0 500 500 600 800 200 100 900 900 200 900 900 300 400 300 800 400 400 0 300 100 800 100 900 300 500 0 0 100 400 100 800 200 500 600 900 600 800 100 800 100 800 800 500 300 900 600 0 200 500 300 700 500 500 300 700 100 800 100 200 700 300 600 0 100 200 600 200 700 0 500 400 400 600 400 200 800 900 400 0 800 500 700 500 200 0
//================================================================================
//Transform doubles
//Before Transform:
//0.648518 0.533006 0.776269 0.912503 0.73748 0.566881 0.649312 0.738395 0.817225 0.977752 0.499924 0.83755 0.865535 0.898984 0.227058 0.115207 0.860469 0.815027 0.622211 0.96292 0.829218 0.539232 0.0600909 0.311655 0.313089 0.944212 0.933348 0.453017 0.529893 0.599933 0.362377 0.0336924 0.0143437 0.976684 0.212439 0.130558 0.018952 0.368328 0.947996 0.81164 0.455336 0.192877 0.356487 0.0898465 0.65801 0.826075 0.672689 0.675832 0.751854 0.624378 0.134159 0.435133 0.903989 0.293832 0.500229 0.95761 0.241951 0.260781 0.564684 0.143712 0.719199 0.200812 0.193854 0.215003 0.708731 0.382 0.921812 0.0544755 0.6068 0.979247 0.632679 0.283456 0.227699 0.0150151 0.362774 0.980956 0.270577 0.0839259 0.752922 0.451735 0.639851 0.516129 0.182104 0.949736 0.900449 0.136845 0.114566 0.762535 0.648946 0.277779 0.690573 0.563646 0.0822169 0.196539 0.0927152 0.438398 0.544359 0.560778 0.719077 0.490127
//
//After Transform:
//64.8518 53.3006 77.6269 91.2503 73.748 56.6881 64.9312 73.8395 81.7225 97.7752 49.9924 83.755 86.5535 89.8984 22.7058 11.5207 86.0469 81.5027 62.2211 96.292 82.9218 53.9232 6.00909 31.1655 31.3089 94.4212 93.3348 45.3017 52.9893 59.9933 36.2377 3.36924 1.43437 97.6684 21.2439 13.0558 1.8952 36.8328 94.7996 81.164 45.5336 19.2877 35.6487 8.98465 65.801 82.6075 67.2689 67.5832 75.1854 62.4378 13.4159 43.5133 90.3989 29.3832 50.0229 95.761 24.1951 26.0781 56.4684 14.3712 71.9199 20.0812 19.3854 21.5003 70.8731 38.2 92.1812 5.44755 60.68 97.9247 63.2679 28.3456 22.7699 1.50151 36.2774 98.0956 27.0577 8.39259 75.2922 45.1735 63.9851 51.6129 18.2104 94.9736 90.0449 13.6845 11.4566 76.2535 64.8946 27.7779 69.0573 56.3646 8.22169 19.6539 9.27152 43.8398 54.4359 56.0778 71.9077 49.0127
//================================================================================
//Parse strings
//CSV: Id = 1, Name = Dan, GPA = 4
//================================================================================
//================================================================================
//Demonstrate move schematics.
//Before the move, mfp1's name = Colin
//After the move, mfp1's name = , mfp2's name = Colin
//
//Before the move, string is: string
//After the move, string is:
//================================================================================
//Demonstrate value schematics.
//Before, msp1's name = Daniel
//After copy constructor, msp1's name = Daniel, mp2's name = Daniel
//
//Before, s= string
//After copy constructor s = string, s2 = string
//================================================================================
//
//Process returned 0 (0x0)   execution time : 0.298 s
//Press any key to continue.
