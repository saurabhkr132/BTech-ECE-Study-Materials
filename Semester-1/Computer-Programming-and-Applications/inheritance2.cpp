<pre><div class="text_to_html">// This program won&#039;t compile.
#include &lt;iostream&gt;
using namespace std;

class base {
  int i, j;
public:
  void set(int a, int b) { i=a; j=b; }
  void show() { cout &lt;&lt; i &lt;&lt; &quot; &quot; &lt;&lt; j &lt;&lt; &quot;\n&quot;;}
};

// Public elements of base are private in derived.
class derived : private base {
  int k;
public:
  derived(int x) { k=x; }
  void showk() { cout &lt;&lt; k &lt;&lt; &quot;\n&quot;; }
};

int main()
{
  derived ob(3);

  ob.set(1, 2); // error, can&#039;t access set()
  ob.show(); // error, can&#039;t access show()

  return 0;
}

</div></pre>