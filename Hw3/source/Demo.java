/** Programmer: Justin Reini */
package code;
import java.util.Scanner;
import javafx.scene.control.Label;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.application.Application;
import javafx.scene.text.TextAlignment;

/**
 *@author Justin Reini
 */
public class Demo extends Application {
	Pane root;
	 /**
     * @param args the command line arguments
     */
	public static void main(String[] args) {
		Application.launch(args);
	}
	@Override
	public void start(Stage stage) {
		root = new StackPane();
		System.out.println("\tMy name is Justin R");
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
		double area2=Math.abs(area);
		createLabel(result, area2);
        Scene scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
  
        stage.setTitle("Area calculator by Justin Reini");
	}
	Label label;
	public void createLabel(int[] result, double area2){
		label = new Label();
        label.setText(" Point 1: "+result[0]+"\n"+" Point 2: "+result[1]+"\n"+" Point 3: "+result[2]+"\n"+" Point 4: "+result[3]+"\n"+" Point 5: "+result[4]+"\n"+
		" Point 6: "+result[5]+"\n"+" Point 7: "+result[6]+"\n"+" Point 8: "+result[7]+"\n"+" The area of the quadrilateral is " + area2);
  
        root.getChildren().add(label);
	}
}
