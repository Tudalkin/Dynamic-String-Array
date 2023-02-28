
#include <string>
#include <iostream>
using namespace std;

class DynamicStringArray{
  private:
    string *dynamicArray;
    int size;
  public:

    //constructors
    DynamicStringArray();
    DynamicStringArray(const DynamicStringArray &oldObj);

    //functions
    int getSize();
    void addEntry(string newEntry);
    bool deleteEntry(string element);
    string getEntry(int index);
    
    //operator
    DynamicStringArray& operator = (const DynamicStringArray& rightSide)noexcept;

    //destructor
    ~DynamicStringArray();

};