#include <bits/stdc++.h>
using namespace std;
#define pi 3.14;

class student 
{
    private:
        int stu_id ;
        string name ;
    public:

        student(int id, string name)
        {
            stu_id=id;
            this->name=name;
        }

        friend void get_info(student s);
        
};

void get_info(student s)
{
    cout <<  "the student id is: " << s.stu_id;
    cout << "\n the name is : " << s.name;
}

int main()
{
    student s(12519292,"Vanssh");
    get_info(s);

    cout << pi;

}