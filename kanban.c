#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <uuid/uuid.h>

struct Task {
    char *task_id;
    char *task_name;
    time_t created_at;
    time_t updated_at;
    char *state;
};

struct Task *tasks = NULL;
int num_tasks = 0;

void create_task(char *name) {
    // Task name should not be empty
    bool is_created = false;

    if (name == NULL) {
        printf("Name cannot be NULL\n");
        return;
    }
    // rest of the function logic

    // Task name should be unique
    for (int i = 0; i < num_tasks; i++) {
        if (strcmp(tasks[i].task_name, name) == 0) {
            printf("Task name should be unique\n");
            return;
        }
    }

    // Task properties
    struct Task task = {
        .task_id = (char *)malloc(37 * sizeof(char)),
        .task_name = (char *)malloc(strlen(name) + 1),
        .created_at = time(NULL),
        .updated_at = 0,
        .state = "todo"
    };
    uuid_t uuid;
    uuid_generate(uuid);
    uuid_unparse(uuid, task.task_id);
    strcpy(task.task_name, name);

    tasks = (struct Task *)realloc(tasks, (num_tasks + 1) * sizeof(struct Task));
    tasks[num_tasks] = task;
    num_tasks++;

    is_created = true;
    if (is_created == false) {
        printf("Task was not created\n");
        return;
    }
    return;
}
int main() {
    create_task("Task 1");
    create_task("Task 2");
    create_task("Task 3");
    return 0;
}


