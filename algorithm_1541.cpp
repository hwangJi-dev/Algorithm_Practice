#include <iostream>
#include <string>

using namespace std;
string String;
 

int result_min(void)

{
     int result = 0;
     string temp = "";
     bool minus = false;
     
     for (int i = 0; i <= String.size(); i++)
     {
         if (String[i] == '+' || String[i] == '-' || String[i] == '\0')
         {
             if (minus)
             result -= stoi(temp);
             
             else
             result += stoi(temp);
             temp = ""; 
             
             if (String[i] == '-')
             minus = true;
             
             continue;     
        }
        
        temp += String[i];    
    }
    return result;

}

 

int main(void)
{
    cin >> String;
    cout << result_min() << endl;
    
    return 0;

}
