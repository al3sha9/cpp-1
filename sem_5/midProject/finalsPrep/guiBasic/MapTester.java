import java.util.HashMap;

public class MapTester {

    // HashMap to store phone book entries
    private HashMap<String, String> phoneBook;

    // Constructor
    public MapTester() {
        phoneBook = new HashMap<>();
    }

    // Method to enter a name and number into the phone book
    public void enterNumber(String name, String number) {
        phoneBook.put(name, number);
    }

    // Method to look up a number by name
    public String lookupNumber(String name) {
        return phoneBook.get(name);
    }

    // Optional: main method to test the class
    public static void main(String[] args) {
        MapTester tester = new MapTester();

        tester.enterNumber("Alice", "123-456-7890");
        tester.enterNumber("Bob", "987-654-3210");

        System.out.println("Alice's number: " + tester.lookupNumber("Alice"));
        System.out.println("Bob's number: " + tester.lookupNumber("Bob"));
        System.out.println("Eve's number: " + tester.lookupNumber("Eve")); // should return null
    }
}
