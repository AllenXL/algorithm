#include <iostream>

using namespace std;

//�ݹ�ᳬʱ
    /*bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *str, *pat;
        bool star = false;
        
        for (str = s, pat = p; *str != '\0'; ++str, ++pat)
        {
            switch(*pat)
            {
                // ����'?',��ô����*str���κ���ĸ����ƥ��
                case '?':
                    break;
                case '*':
                    star = true;
                    // ��ʱ���ԡ�*��
                    s = str, p = pat;
                    do
                    {
                        ++p;
                    }while(*p == '*');
                     // ���'*'֮��pat�ǿյģ�ֱ�ӷ���true
                    if (!*p)
                        return true;
                    // ���¿�ʼƥ��
                    str = s - 1;
                    pat = p - 1;
                    break;
                default:
                    if (*str != *pat)
                    {
                        // ���ǰ��û��'*'����ƥ�䲻�ɹ�
                        if (!star)
                            return false;
                        // ��s����һλ��'*'֮���p���¿�ʼƥ��
                        ++s;
                        str = s - 1;
                        pat = p - 1;
                    }
                    break;
            }
        }
        
        while (*pat == '*')
            ++pat;
        return (!*pat);
    }*/

 bool isMatch(const char *s, const char *p)
 {
	 bool star = false;
	 const char* tmp_s;
	 const char* tmp_p;

	 while (*s)
	 {
		 switch (*p)
		 {
		 case '?':
			 ++s;
			 ++p;
			 break;
		 case '*':
			 star = true;
			 while (*p == '*')
				 ++p;
			 tmp_p = p;
			 tmp_s = s;
			 break;
		 default:
			 if (*p == *s)
			 {
				 ++p;
				 ++s;
			 }
			 else
			 {
				 if(!star)
				 {
					 return false;
				 }
				 else
				 {
					 s = (++tmp_s);
					 p = tmp_p;
				 }
			 }
			 break;
		 }
	 }

	 while (*p == '*')
	 {
		 ++p;
	 }
	 return !(*p);
 }

	int main(void)
	{
		cout << isMatch("abbbc", "a*bc") << endl;
		int aa;
		cin >> aa;
		return 0;
	}


