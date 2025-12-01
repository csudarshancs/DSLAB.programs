import SEE.*;
import java.util.*;

public class Final {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of students: ");
        int n = sc.nextInt();

        Externals[] students = new Externals[n];

        for (int i = 0; i < n; i++) {
            students[i] = new Externals();
            System.out.println("\nEnter Details for Student " + (i + 1) + "");
            students[i].inputStudentDetails();
            students[i].inputInternalMarks();
            students[i].inputSEEmarks();
            students[i].calculateFinalMarks();
        }

        System.out.println("\n========== FINAL RESULTS ==========");
        for (int i = 0; i < n; i++) {
            students[i].displayFinalMarks();
        }
    }
}
