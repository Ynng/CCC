public class Temp {
    public static void main(String[] args) {
        Temp temp = new Temp();
        System.out.println(temp.a(2));
    }

    private int a(int i) {
        return b(i) + 1;
    }

    private int b(int i) {
        return i * 2;
    }
}