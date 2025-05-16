import javax.swing.JOptionPane;

public class Main {

    public static void main(String[] args) {
        String name = JOptionPane.showInputDialog("Enter Your Name");
        JOptionPane.showMessageDialog(null, "HELLO" + name);

        int age = Integer.parseInt(
            JOptionPane.showInputDialog("Enter Your Age")
        );
        JOptionPane.showMessageDialog(null, "Your age is" + age);
    }
}
