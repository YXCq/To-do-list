#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>

class ToDoList : public QWidget {
    Q_OBJECT

public:
    ToDoList(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        taskInput = new QLineEdit(this);
        layout->addWidget(taskInput);

        taskList = new QListWidget(this);
        layout->addWidget(taskList);

        addButton = new QPushButton("Add Task", this);
        connect(addButton, &QPushButton::clicked, this, &ToDoList::addTask);
        layout->addWidget(addButton);

        setLayout(layout);
    }

private slots:
    void addTask() {
        QString task = taskInput->text();
        if (!task.isEmpty()) {
            taskList->addItem(task);
            taskInput->clear();
        }
    }

private:
    QLineEdit *taskInput;
    QListWidget *taskList;
    QPushButton *addButton;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ToDoList toDoList;
    toDoList.setWindowTitle("To-Do List");
    toDoList.show();

    return app.exec();
}