#include<iostream>
#include<stack>
using namespace std;
int
main ()
{
  stack < string > back_stack;
  stack < string > fwd_stack;
  string temp;
  string crnt;
  while (temp != "exit")
    {
      cout << "[1] Visit URL   [2] Back  [3]  Forward" << endl;
      cin >> temp;
      if (temp == "1")
	{
	  cout << "Enter URL: ";
	  cin >> temp;
	  back_stack.push (temp);
	  crnt = back_stack.top();
	}
      else if (temp == "2")
	{
        fwd_stack.push (back_stack.top ());
        back_stack.pop ();
	    if (back_stack.empty ())
        {
            break;
        }
	    cout << "Going back...\n";
        crnt = back_stack.top ();
	}
      else if (temp == "3")
	{
	  if (!fwd_stack.empty ())
	    {
	        cout<<"Going Forward...\n";
	        back_stack.push(fwd_stack.top());
	        crnt = fwd_stack.top();
	        fwd_stack.pop();
	    }else{
	        break;
	    }
	}

      cout << "Current URL:" << crnt << endl;
    }
  return 0;
}
