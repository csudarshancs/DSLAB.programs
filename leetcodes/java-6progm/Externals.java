package SEE;

import CIE.Internals;
import java.util.Scanner; 

public class Externals extends Internals {
    protected int[] seeMarks = new int[5];
    protected double[] finalMarks = new double[5];

    public Externals() {
        for (int i = 0; i < 5; i++) {
            seeMarks[i] = 0;
            finalMarks[i] = 0.0;
        }
    }

    public void inputSEEmarks() {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter SEE Marks (out of 100) for 5 subjects:");
        for (int i = 0; i < 5; i++) {
            System.out.print("Subject " + (i + 1) + ": ");
            seeMarks[i] = s.nextInt();
        }
    }

    public void calculateFinalMarks() {
        for (int i = 0; i < 5; i++) {
            finalMarks[i] = internalMarks[i] + (seeMarks[i] / 2.0);
        }
    }

    public void displayFinalMarks() {
        displayStudentDetails();
        System.out.println("Final Marks in 5 Subjects:");
        for (int i = 0; i < 5; i++) {
            System.out.println("Subject " + (i + 1) + ": " + finalMarks[i]);
        }
    }
}
