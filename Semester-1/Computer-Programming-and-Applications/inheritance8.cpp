<pre><div class="text_to_html">#include &lt;iostream&gt;
using namespace std;

class base {
public:
  base() { cout &lt;&lt; &quot;Constructing base\n&quot;; }
  ~base() { cout &lt;&lt; &quot;Destructing base\n&quot;; }
};

class derived: public base {
public:
  derived() { cout &lt;&lt; &quot;Constructing derived\n&quot;; }
  ~derived() { cout &lt;&lt; &quot;Destructing derived\n&quot;; }
};

int main()
{
  derived ob;

  // do nothing but construct and destruct ob

  return 0;
}

</div></pre>