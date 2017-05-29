/*
 * If a constructor were to throw an exception which is not caught while in the constructor, but by a higher level handler, 
 * the stack unwinding process will not call the destructor of the “partially” created object.
 */

struct A {
  A() { 
    cout << " A ";
    throw 1; // Note: Constructor didn’t complete normally !
  }
  ~A() { cout << " ~A "; }
};

int main() {
  try {
    A a1;
  } catch (int i) {
    cout << i;
  }
}
