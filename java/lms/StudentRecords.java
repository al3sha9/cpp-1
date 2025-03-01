class Student {
    String name;
    int[] marks;

    void setData(String name, int[] marks) {
        this.name = name;
        this.marks = marks;
    }

    void show() {
        System.out.print("Name: " + name + " | Marks: ");
        for (int i = 0; i < marks.length; i++) {
            System.out.print(marks[i] + " ");
        }
        System.out.println();
    }
}

public class StudentRecords {
    public static void main(String[] args) {
        Student[] students = new Student[3];

        students[0] = new Student();
        students[0].setData("Ali", new int[]{85, 90, 78});

        students[1] = new Student();
        students[1].setData("Shan", new int[]{88, 76, 92});

        students[2] = new Student();
        students[2].setData("Khan", new int[]{90, 85, 88});

        showRecords(students);
    }

    static void showRecords(Student[] students) {
        System.out.println("Student Records:");
        for (int i = 0; i < students.length; i++) {
            students[i].show();
        }
    }
}

