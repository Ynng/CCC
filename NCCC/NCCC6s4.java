import java.util.*;

public class NCCC6s4 {
    static int a, b, c, d, q, temp;
    static int[] queries, dp;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        dp = new int[1000000005];
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        q = scanner.nextInt();
        queries = new int[q + 5];
        for (int i = 0; i < q; i++) {
            queries[i] = scanner.nextInt();
        }
        for (int i = 0; i < q; i++) {
            System.out.println(recursion(queries[i]) + "\n");
        }
        return;
    }

    static public int recursion(int x) {
        if (x <= 0) {
            return 1;
        } else {
            if (dp[x] != -1) {
                return dp[x];
            } else {
                temp = recursion(x / a - b) + recursion(x / c - d);
                dp[x] = temp;
                return temp;
            }
        }
    }
}