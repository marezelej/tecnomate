#include &lt;iostream&gt;
using namespace std;
bool puede(int vel,int l)
{
    int suma=0;
    while(vel&gt;0)
    {
        for(int i=0;i&lt;vel;i++)
        {
            if(l==suma){
                return true; 
            }
            suma+=vel;
        }
        vel--;
        if(suma==l){
            return true; 
        }
    }
    return false;
}
using namespace std;

int main() {
	int n,v;
	int i;
	bool can;
	cin&gt;&gt;n&gt;&gt;v;
    while(n!=0 &amp;&amp; v!=0)
    {
        i=1;
        can=false;
        while(i&lt;=v &amp;&amp; !can)
        {
            can=puede(i,n);
            i++;
        }
        if(i&lt;=v || can) 
        {
            cout&lt;&lt;&quot;possivel&quot;&lt;&lt;endl;
        }
        else 
        {
            cout&lt;&lt;&quot;impossivel&quot;&lt;&lt;endl;
        }
        cin&gt;&gt;n&gt;&gt;v;
    }
    return 0;
}

