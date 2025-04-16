import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Library lib = new Library();
        lib.addbook(new Book("Book number 1", "Ali"));
        lib.addbook(new Book("Book number 2", "Shan"));
        lib.addbook(new Book("Book number 3", "Khan"));

        while (true) {
            System.out.println("\n--- Library Menu ---");
            System.out.println("1. Show available books");
            System.out.println("2. Issue a book");
            System.out.println("3. Return a book");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            if (choice == 1) {
                lib.printAvailableBooks();
            } else if (choice == 2) {
                System.out.print("Enter title of book to issue: ");
                String title = sc.nextLine();
                lib.issueBook(title);
            } else if (choice == 3) {
                System.out.print("Enter title of book to return: ");
                String title = sc.nextLine();
                lib.returnBook(title);
            } else if (choice == 4) {
                System.out.println("Exiting...");
                break;
            } else {
                System.out.println("Invalid choice.");
            }
        }
        sc.close();
    }
}
