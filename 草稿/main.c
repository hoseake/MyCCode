#include <stdio.h>
struct jobs
{
    char job1[] = "student";
    char job2[] = "teacher";
};
struct info
{
    char name[] = "Peter";
    int age = 20;
    struct jobs job;
};
int main()
{
    printf("%s",&jobs->job1);
}
