/*
 *If a code in the constructor were to throw an exception which is caught while in the constructor, the stack unwinding process will call 
 * the destructor of the object (as usual).
 */

struct A {
  A() { 
    cout << " A ";
   try {
    throw 1;
   } catch (int i) {
     cout << i; 
   }
  }
  ~A() { cout << " ~A "; }
};

int main() {
  try {
    A a1;
  } catch (int i) {
    cout << “ main “;
  }
}
