#include <iostream>
using namespace std;
template <typename T>class vector{
T *arr;
int Capacity;
int Current;
//constructor
public:
vector(){
    arr=new T[1];
    Capacity=1;
    Current=0;
}
//preventing from memory leak
~vector(){
    //The delete operator deallocates memory and calls the destructor for a single object created with new
    //The delete [] operator deallocates memory and calls destructors for an array of objects created with new [].
    delete [] arr;
}
//adding element from last
void push_back(T data){
    if(Current==Capacity){
       T* temp=new T[2*Capacity];
       for(int i=0;i<Capacity;i++){
        temp[i]=arr[i];
       }
       delete [] arr;
       Capacity=Capacity*2;
       arr=temp;
      
    }
     //inserting element
       arr[Current]=Current;
       Current++;
}
void pop_back(){
    Current --;
}
int size(){
    return Current;
}
int capacity(){
    return Capacity;
}
void print(){
    for(int i=1;i<=Current;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void pushAtIndex(T data,int index){
     if (index == capacity)
            push(data);
        else
            arr[index] = data;
}
int getIndexOf(T data){
    int ik=-1;
    for(int i=1;i<=Current;i++){
        if(arr[i]==data){
           ik=i-1;
           break;
        }
    }
    return ik;
}
};
int main(){
vector<int>v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);
v.push_back(6);
v.push_back(7);
v.push_back(8);
cout<<v.getIndexOf(5)<<endl;
cout<<v.getIndexOf(88)<<endl;
v.pop_back();
v.print();
cout<<v.capacity()<<endl;
cout<<v.size()<<endl;
return 0;
}