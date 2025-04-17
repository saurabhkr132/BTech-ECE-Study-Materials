<pre><div class="text_to_html">// An example of multiple base classes.

#include &lt;iostream&gt;
using namespace std;

class base1 {
protected:
  int x;
public:
  void showx() { cout &lt;&lt; x &lt;&lt; &quot;\n&quot;; }
};

class base2 {
protected:
  int y;
public:
  void showy() {cout &lt;&lt; y &lt;&lt; &quot;\n&quot;;}
};

// Inherit multiple base classes.
class derived: public base1, public base2 {
public:
  void set(int i, int j) { x=i; y=j; }
};

int main()
{
  derived ob;

  ob.set(10, 20); // provided by derived
  ob.showx(); // from base1
  ob.showy(); // from base2

  return 0;
}


</div></pre>