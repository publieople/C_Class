#include <stdio.h>

// 3 个学生, 各学 4 门课, 计算总平均分以及第 n 个学生的成绩.

// 用指向二维数组的指针作为函数参数, 用函数 avg 计算总平均分, 用函数 search 找出并输出第 i 个学生的成绩.

#define STUDENTS 3
#define COURSES 4
void avg(float (*p)[COURSES], int students, int courses);
void search(float (*p)[COURSES], int studentIndex, int courses);
int main()
{
    float scores[STUDENTS][COURSES] = {{90.5, 80.0, 70.5, 60.0}, {85.5, 75.0, 65.5, 55.0}, {95.0, 85.5, 75.0, 65.5}};

    avg(scores, STUDENTS, COURSES);
    search(scores, 1, COURSES);

    return 0;
}

void avg(float (*p)[COURSES], int students, int courses)
{
    float total = 0;
    for (int i = 0; i < students; i++)
    {
        for (int j = 0; j < courses; j++)
        {
            total += *(*(p + i) + j);
        }
    }
    float average = total / (students * courses);
    printf("总平均分: %.2f\n", average);
}

void search(float (*p)[COURSES], int studentIndex, int courses)
{
    printf("第 %d 个学生的成绩: ", studentIndex);
    for (int j = 0; j < courses; j++)
    {
        printf("%.1f ", *(*(p + studentIndex) + j));
    }
    printf("\n");
}