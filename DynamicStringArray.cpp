#include "DynamicStringArray.h"
#include <string>
using namespace std;


//constructors
DynamicStringArray::DynamicStringArray(){
  dynamicArray=nullptr;
  size=0;
}
DynamicStringArray::DynamicStringArray(const DynamicStringArray &oldObj){
  size=oldObj.size;
  if (size>0){
    dynamicArray=new string[size];
    for(int i=0;i<size;i++){
      dynamicArray[i]=oldObj.dynamicArray[i];
    }
  }
  else{
    dynamicArray=nullptr;
  }

}

//functions
int DynamicStringArray::getSize(){
  return size;
}

void DynamicStringArray::addEntry(string newEntry){
  string *newDynamicArray =new string[size +1];
  for(int i=0; i<size; i++){
    newDynamicArray[i]=dynamicArray[i];
  }
  newDynamicArray[size]=newEntry;
  size++;
  delete[] dynamicArray;
  dynamicArray=newDynamicArray;
}

bool DynamicStringArray::deleteEntry(string element){
  int num=-1;
  string *newDynamicArray =nullptr;
  for(int i=0;i<size;i++)
    if (dynamicArray[i]==element)
      num=i;
  if (num == -1)
    return 0;
  if(size>1){
    newDynamicArray=new string[size -1];
  }
  for(int i=0,j=0;i<size;i++){
    if(i!=num){
      newDynamicArray[j++]=dynamicArray[i];
    }
  }
  size--;
  delete[] dynamicArray;
  dynamicArray=newDynamicArray;
  return true;
}

string DynamicStringArray::getEntry(int index){
  if((index<0)||(index>=size))
    return NULL;
  else
    return dynamicArray[index];
}

//operators

DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& rightSide)noexcept{
  if(dynamicArray!=nullptr){
    delete[] dynamicArray;
  }
  if(rightSide.size==0){
    size=0;
    dynamicArray=nullptr;
  }
  else{
    size=rightSide.size;
    dynamicArray=new string[size];
    for(int i=0;i<size;i++){
      dynamicArray[i]=rightSide.dynamicArray[i];
    }
  }
  return *this;
}

//destructor

DynamicStringArray::~DynamicStringArray(){
  if(dynamicArray!=nullptr){
    delete[] dynamicArray;
    dynamicArray=nullptr;
  }  
}