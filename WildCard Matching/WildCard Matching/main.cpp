#include <iostream>

using namespace std;

//递归会超时
    /*bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *str, *pat;
        bool star = false;
        
        for (str = s, pat = p; *str != '\0'; ++str, ++pat)
        {
            switch(*pat)
            {
                // 遇到'?',那么不管*str是任何字母都能匹配
                case '?':
                    break;
                case '*':
                    star = true;
                    // 暂时忽略‘*’
                    s = str, p = pat;
                    do
                    {
                        ++p;
                    }while(*p == '*');
                     // 如果'*'之后，pat是空的，直接返回true
                    if (!*p)
                        return true;
                    // 重新开始匹配
                    str = s - 1;
                    pat = p - 1;
                    break;
                default:
                    if (*str != *pat)
                    {
                        // 如果前面没有'*'，则匹配不成功
                        if (!star)
                            return false;
                        // 从s的下一位和'*'之后的p重新开始匹配
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


