import javax.swing.JOptionPane;

public class Main {

    public static void main(String[] args) {
        String name = JOptionPane.showInputDialog("ENter your name");
        String contactNumber = JOptionPane.showInputDialog(
            "Enter your contact number"
        );
        String Salary = JOptionPane.showInputDialog("Enter your Salary");

        String output = "Your details are: " + name + contactNumber + Salary;
        JOptionPane.showMessageDialog(null, output);
    }
}
