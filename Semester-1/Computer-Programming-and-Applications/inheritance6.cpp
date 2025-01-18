<pre><div class="text_to_html">#include &lt;iostream&gt;
using namespace std;

class base {
protected:
  int i, j; // private to base, but accessible by derived
public:
  void setij(int a, int b) { i=a; j=b; }
  void showij() { cout &lt;&lt; i &lt;&lt; &quot; &quot; &lt;&lt; j &lt;&lt; &quot;\n&quot;; }
};

// Inherit base as protected.
class derived : protected base{
  int k;
public:
  // derived may access base&#039;s i and j and setij().
  void setk() { setij(10, 12); k = i*j; }

  // may access showij() here
  void showall() { cout &lt;&lt; k &lt;&lt; &quot; &quot;; showij(); }
};

int main()
{
  derived ob;

//  ob.setij(2, 3); // illegal, setij() is
//                     protected member of derived

  ob.setk(); // OK, public member of derived
  ob.showall(); // OK, public member of derived

// ob.showij(); // illegal, showij() is protected
//                 member of derived

  return 0;
}


</div></pre>