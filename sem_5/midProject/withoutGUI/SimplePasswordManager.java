import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.io.*;
import java.security.SecureRandom;
import java.util.Base64;
import java.util.Scanner;

class PasswordEntry {
    private String website;
    private String encryptedPassword;

    public PasswordEntry(String website, String encryptedPassword) {
        this.website = website;
        this.encryptedPassword = encryptedPassword;
    }

    public String getWebsite() {
        return website;
    }

    public String getEncryptedPassword() {
        return encryptedPassword;
    }
}

class MnemonicGenerator {
    private static final String[] WORD_LIST = {
        "apple", "book", "cat", "dog", "elephant",
        "fish", "garden", "house", "ice", "jungle",
        "king", "lion", "moon", "nest", "ocean",
        "pencil", "queen", "river", "sun", "tree",
        "umbrella", "violet", "water", "xray", "yellow",
        "zebra", "bird", "cloud", "door", "eagle"
    };

    private SecureRandom random;

    public MnemonicGenerator() {
        this.random = new SecureRandom();
    }

    public String generatePhrase() {
        StringBuilder phrase = new StringBuilder();
        boolean[] used = new boolean[WORD_LIST.length];
        int wordsAdded = 0;

        while (wordsAdded < 12) {
            int index = random.nextInt(WORD_LIST.length);
            if (!used[index]) {
                if (wordsAdded > 0) {
                    phrase.append(" ");
                }
                phrase.append(WORD_LIST[index]);
                used[index] = true;
                wordsAdded++;
            }
        }

        return phrase.toString();
    }
}

class PasswordStrengthChecker {
    public String checkStrength(String password) {
        int score = 0;
        StringBuilder feedback = new StringBuilder();

        if (password.length() < 8) {
            feedback.append("Password is too short (minimum 8 characters)\n");
        } else {
            score += 2;
        }

        if (password.matches(".*\\d.*")) {
            score += 2;
        } else {
            feedback.append("Add numbers for stronger password\n");
        }

        if (password.matches(".*[A-Z].*")) {
            score += 2;
        } else {
            feedback.append("Add uppercase letters for stronger password\n");
        }

        if (password.matches(".*[a-z].*")) {
            score += 2;
        } else {
            feedback.append("Add lowercase letters for stronger password\n");
        }

        if (password.matches(".*[!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>/?].*")) {
            score += 2;
        } else {
            feedback.append("Add special characters for stronger password\n");
        }

        String strength;
        if (score >= 8) {
            strength = "Strong";
        } else if (score >= 6) {
            strength = "Medium";
        } else {
            strength = "Weak";
        }

        return strength + (feedback.length() > 0 ? "\nSuggestions:\n" + feedback.toString() : "");
    }
}

class FileHandler {
    private static final String FILE_NAME = "passwords.txt";

    public void savePassword(PasswordEntry entry) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_NAME, true))) {
            writer.write(entry.getWebsite() + ":" + entry.getEncryptedPassword());
            writer.newLine();
        }
    }

    public PasswordEntry findPassword(String website) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(":");
                if (parts.length == 2 && parts[0].equals(website)) {
                    return new PasswordEntry(parts[0], parts[1]);
                }
            }
        }
        return null;
    }
}

public class SimplePasswordManager {
    private SecretKey secretKey;
    private String masterPassword;
    private FileHandler fileHandler;
    private Scanner scanner;
    private MnemonicGenerator mnemonicGenerator;
    private PasswordStrengthChecker strengthChecker;

    public SimplePasswordManager() throws Exception {
        KeyGenerator keyGen = KeyGenerator.getInstance("AES");
        keyGen.init(128);
        this.secretKey = keyGen.generateKey();
        this.fileHandler = new FileHandler();
        this.scanner = new Scanner(System.in);
        this.mnemonicGenerator = new MnemonicGenerator();
        this.strengthChecker = new PasswordStrengthChecker();
    }

    public void start() {
        try {
            System.out.print("Set your master password: ");
            masterPassword = scanner.nextLine();
            showMenu();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    private void showMenu() throws Exception {
        while (true) {
            System.out.println("\n1. Save password");
            System.out.println("2. Retrieve password");
            System.out.println("3. Generate OTP");
            System.out.println("4. Generate Mnemonic Phrase");
            System.out.println("5. Check Password Strength");
            System.out.println("6. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    savePassword();
                    break;
                case 2:
                    retrievePassword();
                    break;
                case 3:
                    generateOTP();
                    break;
                case 4:
                    generateMnemonicPhrase();
                    break;
                case 5:
                    checkPasswordStrength();
                    break;
                case 6:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }
    }

    private void generateMnemonicPhrase() {
        String phrase = mnemonicGenerator.generatePhrase();
        System.out.println("Generated Mnemonic Phrase:");
        System.out.println(phrase);
        System.out.println("\nPlease store this phrase safely. It can be used as a backup for your passwords.");
    }

    private void checkPasswordStrength() {
        System.out.print("Enter password to check: ");
        String password = scanner.nextLine();
        String result = strengthChecker.checkStrength(password);
        System.out.println("\nPassword Strength Analysis:");
        System.out.println(result);
    }

    private void savePassword() throws Exception {
        System.out.print("Website: ");
        String website = scanner.nextLine();
        System.out.print("Password: ");
        String password = scanner.nextLine();

        Cipher encryptCipher = Cipher.getInstance("AES");
        encryptCipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = encryptCipher.doFinal(password.getBytes());
        String encoded = Base64.getEncoder().encodeToString(encryptedBytes);

        PasswordEntry entry = new PasswordEntry(website, encoded);
        fileHandler.savePassword(entry);
        System.out.println("Password saved!");
    }

    private void retrievePassword() throws Exception {
        System.out.print("Website: ");
        String website = scanner.nextLine();

        PasswordEntry entry = fileHandler.findPassword(website);
        if (entry != null) {
            System.out.print("Master password: ");
            if (scanner.nextLine().equals(masterPassword)) {
                Cipher decryptCipher = Cipher.getInstance("AES");
                decryptCipher.init(Cipher.DECRYPT_MODE, secretKey);
                byte[] decryptedBytes = decryptCipher.doFinal(Base64.getDecoder().decode(entry.getEncryptedPassword()));
                System.out.println("Password: " + new String(decryptedBytes));
            } else {
                System.out.println("Wrong master password!");
            }
        } else {
            System.out.println("No password found.");
        }
    }

    private void generateOTP() {
        int otp = 100000 + new SecureRandom().nextInt(900000);
        System.out.println("Generated OTP: " + otp);
    }

    public static void main(String[] args) {
        try {
            SimplePasswordManager manager = new SimplePasswordManager();
            manager.start();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
