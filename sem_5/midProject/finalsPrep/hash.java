import java.util.HashMap;
import java.util.Scanner;

public class HashTest {

    private HashMap<String, String> phonebook;

    public HashTest() {
        phonebook = new HashMap<>();
    }

    public void enterNumber(String name, String number) {
        phonebook.put(name, number);
    }

    public String checkNum(String name) {
        return phonebook.get(name);
    }

    public static void main(String[] args) {
        HashTest hT = new HashTest();

        hT.enterNumber("ALISHAN", "ONEPLUS USER");
        hT.enterNumber("Fazila Roshan", "SAMSUNG USER");

        System.out.println("ALi Shans number is: " + hT.checkNum("ALISHAN"));
        System.out.println("Fazi number is: " + hT.checkNum("Fazila Roshan"));
        System.out.println("Fazi number is: " + hT.checkNum("Fazila")); //return null
    }
}
