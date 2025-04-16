public class Main {

    static void displayStudent(Student s) {
        s.printStudent();
    }

    public static void main(String[] args) {
        Student s1 = new Student();
        Student s2 = new Student();
        s1.setStudent("Ali", 99, 23, 64, 23);
        s2.setStudent("Shan", 45, 21, 54, 23);

        System.out.println("Student Records are\n");

        displayStudent(s1);
        System.out.println("-----------------------\n");
        displayStudent(s2);
    }
}
