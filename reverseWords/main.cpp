#include <iostream>
#include <string>

using namespace std;

void reverseWords(string &s) {
        if (s.size() == 0)
        {
            s=string("");
            return;
        }

        int begin_pos = s.size() - 1;
        int end_pos = s.size() - 1;
        string res="";
        bool is_start = false;

        while(begin_pos >= 0)
        {
            //cout << begin_pos << " " << end_pos<<endl;

            if (s[begin_pos] == ' ' && !is_start)
            {
                begin_pos--;
                continue;
            }

            if (s[begin_pos] != ' ' && !is_start)
            {
                end_pos = begin_pos;

                is_start = true;
            }

            if (s[begin_pos] == ' ' && is_start)
            {

                for(int i=begin_pos+1; i <= end_pos; ++i)
                {
                    res.append(s.substr(i,1));
                }
                res.append(" ");
                end_pos = begin_pos;
                is_start = false;
            }

            begin_pos--;
        }

        if (is_start)
        {
            for(int i=begin_pos+1; i <= end_pos; ++i)
            {
                res.append(s.substr(i,1));
            }
        }
       s=res;

       if (res[res.size()-1] == ' ')
        {

            res.erase(res.size()-1);
        }
       return;
    }

int main()
{
    cout << "Hello world!" << endl;
    string str="abc def  ";
    //cout << "str: " <<str<<"size: " << str.size() <<endl;

    reverseWords(str);
    cout << str <<endl;
    cout << str.size() << endl;

    return 0;
}
