public class Student {

    String name;
    int id;
    int[] marks = new int[3];

    void setStudent(String n, int id, int s1, int s2, int s3) {
        name = n;
        id = id;
        marks[0] = s1;
        marks[1] = s2;
        marks[2] = s3;
    }

    void printStudent() {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("Math: " + marks[0]);
        System.out.println("English: " + marks[1]);
        System.out.println("Science: " + marks[2]);
    }
}
