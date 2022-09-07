/** Programmer: Justin Reini */
package code;
import java.util.Date;
import java.util.Scanner;
public class Points {
	public static void main(String[] args) {
		Date date= new Date();  /* create the date */
		System.out.println("\tMy name is Justin R");
		System.out.println("\tToday's date is "+date.toString());
		System.out.println("Please enter 4 points aka 8 values");
		Scanner scanner = new Scanner(System.in);  /* creating the scanner */
		String pointline = scanner.nextLine();
		String[] arr = pointline.split(" ");  /* takes the input and splits it into an array */
		
		int[] result= new int[8];
		for(int i=0;i<8;i++)
			result[i]=Integer.parseInt(arr[i]);
		/* turns string array into integer array */
		
		
		double product1 = (result[0]*result[3])+(result[2]*result[5])+(result[4]*result[7])+(result[6]*result[1]);
		double product2 = (result[1]*result[2])+(result[3]*result[4])+(result[5]*result[6])+(result[7]*result[0]);
		double area= (product1-product2) *0.5;  /* divides the quadrilateral into 2 large areas, then subtracts the extra and divides into half */
		
		System.out.println("The points for this quadrilateral are:");
		System.out.println("1: ("+result[0]+","+result[1]+")");
		System.out.println("2: ("+result[2]+","+result[3]+")");
		System.out.println("3: ("+result[4]+","+result[5]+")");
		System.out.println("4: ("+result[6]+","+result[7]+")");
		System.out.println("The area of the quadrilateral is " + Math.abs(area));
		
	}
}