import java.util.*;

public class CCC00j2 {
    public static void main(String[] args) {
        int m, n, counter = 0;
        Scanner scanner = new Scanner(System.in);
        m = scanner.nextInt();
        n = scanner.nextInt();
        outerloop: for (int i = m; i <= n; i++) {
            String s = Integer.toString(i);
            if (s.matches(".*[23457].*")) {
                continue;
            }
            if(s.length()%2!=0){
                if(s.charAt(s.length()/2)=='6'||s.charAt(s.length()/2)=='9')continue;
            }
            for (int j = 0; j < s.length() / 2; j++) {
                char a = s.charAt(j);
                char b = s.charAt(s.length() - 1 - j);
                if(b=='6')b='9';
                if(b=='9')b='6';
                if(a!=b)continue outerloop;
            }
            counter++;
            // System.out.println(i);
            

        }
        System.out.println(counter);
    }
}