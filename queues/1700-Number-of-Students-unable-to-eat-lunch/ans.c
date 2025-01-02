// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/

#define MAX_SIZE 1000

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int value) {
    if (q->rear < MAX_SIZE) {
        q->arr[q->rear++] = value;
    }
}

int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->arr[q->front++];
    }
    return -1;
}

int front(Queue* q) {
    if (!isEmpty(q)) {
        return q->arr[q->front];
    }
    return -1;
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    Queue student_choice;
    initQueue(&student_choice);

    for (int i = 0; i < studentsSize; ++i) {
        enqueue(&student_choice, students[i]);
    }

    int rotations = 0, i = 0;
    while (!isEmpty(&student_choice) && rotations < studentsSize) {
        if (front(&student_choice) == sandwiches[i]) {
            dequeue(&student_choice);
            i++;
            rotations = 0;
        } else {
            int choice = dequeue(&student_choice);
            enqueue(&student_choice, choice); 
            rotations++;
        }
    }

    return student_choice.rear - student_choice.front;
}