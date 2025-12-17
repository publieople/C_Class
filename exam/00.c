#include <stdio.h>

// 利用二维数组实现
// 输入若干名学生的学号和成绩，计算并输出最高分, 最低分及平均分及对应的学号
// 输出按照从低到高排序
#define MAX_STUDENTS 100

typedef struct {
    int id;
    float score;
} Student;

int main() {
    Student students[MAX_STUDENTS];
    int n, i;
    float max_score = -1.0, min_score = 101.0, total_score = 0.0;
    int max_id = -1, min_id = -1;

    printf("请输入学生人数: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("请输入第 %d 个学生的学号和成绩: ", i + 1);
        scanf("%d %f", &students[i].id, &students[i].score);
        total_score += students[i].score;

        if (students[i].score > max_score) {
            max_score = students[i].score;
            max_id = students[i].id;
        }
        if (students[i].score < min_score) {
            min_score = students[i].score;
            min_id = students[i].id;
        }
    }

    // 排序
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].score > students[j + 1].score) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("最高分: %.2f, 学号: %d\n", max_score, max_id);
    printf("最低分: %.2f, 学号: %d\n", min_score, min_id);
    printf("平均分: %.2f\n", total_score / n);
    printf("排序后的成绩单:\n");
    for (i = 0; i < n; i++) {
        printf("学号: %d, 成绩: %.2f\n", students[i].id, students[i].score);
    }

    return 0;
}