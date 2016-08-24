#include <iostream>

using namespace std;

void reverse(char *str)
{
    char *end = str;
    char tmp;
    if(str)
    {
        while(*end)
        ++end;
        
        --end;
        
        while(str<end)
        {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}
int main()
{
   char test[7] = {'a','b','c','d','e','f','g'};
   cout << test << endl;
   
   reverse(test);
   cout << test << endl; 
   
   return 0;
}

