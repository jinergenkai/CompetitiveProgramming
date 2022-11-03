import java.io.*;
import java.util.*;
import java.lang.*;

public class Test extends PrintWriter {
    Test() { super(System.out); }
    static Scanner sc = new Scanner(System.in);
    final static String inputFile = "src/test.txt";

    public static void main(String[] $) {
        Test o = new Test();

        boolean ok = true;
        try {
            File f = new File(inputFile);
            sc = new Scanner(f);
        } catch (Exception e) {
            sc = new Scanner(System.in);
            ok = false;
        }
        if (ok) {
            try {
                File f = new File(inputFile);
                sc = new Scanner(f);
            } catch (Exception e) {
            }
        }

        o.main();
        o.flush();
    }
    void main() {
        int t = 1;
        t = sc.nextInt();
        while(t-- > 0) {
            testcase();
        }
    }
    void testcase() {
        int n = sc.nextInt();
        int k = sc.nextInt();
        String s = sc.next();

        int res = 0;
        int[][] a = new int[k+1][30];
        for (int i = 0; i < k; i++) {
            for (int j = i; j < n; j += k) {
                a[i][s.charAt(j)-'a']++;
            }
        }
        for (int i = 0, j = k-1; i <= j; i++, j--) {
            int maxl = 0, maxr = 0;
            int max = 1000111000;
            for (int l = 0; l < 26; l++) {
                max = Math.min(max, n/k*2 - a[i][l] - a[j][l]);
            }
            res += max;
            if (i == j) res -= max/2;
        }
        println(res);
    }
}