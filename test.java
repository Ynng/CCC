/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.Scanner;
public class Main
{
    public static Scanner sc;
	public static void main(String[] args) {
	    sc = new Scanner(System.in);
	    
	    String input;
	    getInput(input);
		System.out.println("User Entered: " + input);
	}
	
	public static void getInput(String input){
	    input = sc.nextLine();
	}
	
	
}
