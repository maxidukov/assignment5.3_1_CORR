#include <iostream>
#include <stdexcept>

class smart_array{
   int size{};
   int capacity{};
   int* pnum;
   public:
   smart_array(int num) : capacity(num){
     pnum = new int[num]();
   }
   int& operator[](int ind){
     if(ind<size && ind >= 0){
       return pnum[ind];
     }else{
       throw std::out_of_range("Array index out of bound!");
       //exit(1);
     }
   }
   int get_element(int ind){
     return this->operator[](ind);
     /*auto& self = *this;
     return self[ind];*/
     //return this->[ind] THROWS ERROR!!
     //return (*this)[ind] THROWS ERROR!!
   }
   void add_element(int n){
     if(size == capacity){
       int* pnum_new = new int[capacity*2];
       capacity *= 2;
       int i{};
       for(; i<size; i++){
         pnum_new[i] = pnum[i];
       }
       pnum_new[i+1] = n;
       int* pnum_old = pnum;
       pnum = pnum_new;
       delete[] pnum_old;
     }else{
       pnum[size] = n;
     }
     size++;
   }
   smart_array(const smart_array&) = delete;
   smart_array& operator=(const smart_array&) = delete;
   ~smart_array(){
     delete[] pnum;
   }
};

int main() {
  try {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);
    arr.add_element(14);
    arr.add_element(15);
    std::cout << arr.get_element(1) << std::endl;
  }
  catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
}
