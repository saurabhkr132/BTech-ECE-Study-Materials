<pre><div class="text_to_html">#include &lt;iostream&gt;
using namespace std;

class base {
protected:
  int i, j; // private to base, but accessible by derived
public:
  void set(int a, int b) { i=a; j=b; }
  void show() { cout &lt;&lt; i &lt;&lt; &quot; &quot; &lt;&lt; j &lt;&lt; &quot;\n&quot;; }
};

class derived : public base {
  int k;
public:
  // derived may access base&#039;s i and j
  void setk() { k=i*j; }

  void showk() { cout &lt;&lt; k &lt;&lt; &quot;\n&quot;; }
};

int main()
{
  derived ob;

  ob.set(2, 3); // OK, known to derived
  ob.show(); // OK, known to derived

  ob.setk();
  ob.showk();

  return 0;
}

</div></pre>