import java.io.*;
import java.util.*;
import java.lang.*;
public class Test extends PrintWriter { Test() { super(System.out); }static Scanner sc = new Scanner(System.in);final static String inputFile = "src/test.txt";public static void main(String[] $) {Test o = new Test();boolean ok = true;try {File f = new File(inputFile);sc = new Scanner(f);} catch (Exception e) {sc = new Scanner(System.in);ok = false;}if (ok) {try {File f = new File(inputFile);sc = new Scanner(f);} catch (Exception e) {}}o.main();o.flush();}
    void main() {
        int t = 1;
        t = sc.nextInt();
        while(t-- > 0) {
            testcase();
        }
    }
    void testcase() {

    }
}