public class Book {

    String title;
    String author;
    boolean isIssued;

    Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.isIssued = false;
    }

    void issueBook() {
        if (isIssued) {
            System.out.println("Book already Issued\n");
        } else {
            isIssued = true;
            System.out.println("You Issued :" + title);
        }
    }

    void returnBook() {
        if (!isIssued) {
            System.out.println("Book not Issued\n");
        } else {
            isIssued = false;
            System.out.println("You returned" + title);
        }
    }

    boolean isAvailable() {
        return !isIssued;
    }

    void printBook() {
        System.out.println("Title" + title + "Author" + author);
        if (isIssued) {
            System.out.println("Book  Issued\n");
        } else {
            System.out.println("Book available\n");
        }
    }
}
