#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int sueldo;
    int id;
}Employee;

int employee_getSueldo(Employee* this,int* sueldo);

int main()
{
    Employee* e1 = (Employee*)malloc(sizeof(Employee));
    e1->id = 1;
    e1->sueldo= 15000;
    printf("%d",employee_getSueldo(e1, 15000) );
    return 0;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this != NULL && sueldo != NULL)
    {
        if(*sueldo == this->sueldo)
        {
            return *sueldo;
        }else{
            return 0;
        }
    }
}
