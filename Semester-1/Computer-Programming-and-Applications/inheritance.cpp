<pre><div class="text_to_html">#include &lt;iostream&gt;

using namespace std;



class base {

  int i, j;

public:

  void set(int a, int b) { i=a; j=b; }

  void show() { cout &lt;&lt; i &lt;&lt; &quot; &quot; &lt;&lt; j &lt;&lt; &quot;\n&quot;; }

};



class derived : public base {

  int k;

public:

  derived(int x) { k=x; }

  void showk() { cout &lt;&lt; k &lt;&lt; &quot;\n&quot;; }

};



int main()

{

  derived ob(3);



  ob.set(1, 2); // access member of base

  ob.show(); // access member of base



  ob.showk(); // uses member of derived class



  return 0;

}
</div></pre>