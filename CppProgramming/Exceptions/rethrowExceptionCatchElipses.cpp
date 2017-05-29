/*
 *Temporary object is created only once, at the ‘throw’ statement in function f(). But its storage duration lasts until the 
 * LAST handler being executed for the exception exits by any means other than a ‘throw;’
 * In this example, it is until the handler in ‘main’ exits.
 */

struct E {
  E() { cout << " E() "; }
  E(const E& rhs) { 
    cout << " E(E&) "; 
  }
};

void f() {
  E  e;
  throw e;
}

void fun() {
  try {
    f();
  } catch (E  e) {
    cout << "fun";
    throw;     // RE-THROW
  }
}

int main() {
  try {
    fun();
  } catch (…) {
    cout << "main";
  }
}
