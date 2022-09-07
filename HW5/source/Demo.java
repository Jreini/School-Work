/** Programmer: Justin Reini */
package code;
import java.util.Scanner;
import java.io.*;
import javafx.scene.layout.*;//Pane, VBox
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.application.Application;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.text.TextAlignment;
import javafx.geometry.Point2D;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

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
		root = new Pane();
		calculate();
		Scene scene = new Scene(root,400,400);
		stage.setScene(scene);
        stage.show();
        stage.setTitle("Circle Intersects by Justin Reini");
	}
	Label label0,outputlabel;
	TextField tField;
	Circle circle1,circle2;
	public void calculate(){
		try
		{
			File file = new File("./source/data/infile.txt");
			Scanner scanner =new Scanner(file);  /* creating the scanner */
			String pointline = scanner.nextLine();
			String[] arr = pointline.split(" ");  /* takes the input and splits it into an array */
			double[] radius= new double[2];
			int[] cords= new int[4];
		
			/* turns strings into either ints or doubles */
			cords[0]=Integer.parseInt(arr[0]);
			cords[1]=Integer.parseInt(arr[1]);
			radius[0]=Double.parseDouble(arr[2]);
			cords[2]=Integer.parseInt(arr[3]);
			cords[3]=Integer.parseInt(arr[4]);
			radius[1]=Double.parseDouble(arr[5]);
		
			label0 = new Label();
			outputlabel = new Label();
			label0.setText("Do the circles intersect? By: Justin Reini");
		
			createCircle(radius,cords);
		
			tField = new TextField(cords[0]+" "+cords[1]+" "+radius[0]+" "+cords[2]+" "+cords[3]+" "+radius[1]);
			tField.relocate(0,20);
			outputlabel.relocate(0,50);
			tField.setOnAction(new TextFieldHandler());
			root.getChildren().addAll(label0,tField,outputlabel);
			
		}
		catch(Exception e)
		{
			System.out.println("error in reading");
			e.printStackTrace();
		}
	}
	public void createCircle(double[] radius, int[] cords)
	{
		Circle circle1 = new Circle();
		Circle circle2 = new Circle();
		circle1.setCenterX(cords[0]);
		circle1.setCenterY(cords[1]);
		circle1.setRadius(radius[0]);
		circle2.setCenterX(cords[2]);
		circle2.setCenterY(cords[3]);
		circle2.setRadius(radius[1]);
		circle1.setStroke(Color.BLUE);
		circle2.setStroke(Color.RED);
		circle1.setFill(Color.DARKVIOLET);
		circle2.setFill(Color.ORANGE);
		if(overlaps(circle1,circle2))
			outputlabel.setText("The two circles overlap");
		else
			outputlabel.setText("The two circles do not overlap");
		root.getChildren().addAll(circle1,circle2);
	}
	public static boolean overlaps(Circle circle1, Circle circle2) {
		return new Point2D(circle1.getCenterX(), circle1.getCenterY()).distance(circle2.getCenterX(), circle2.getCenterY())<= circle1.getRadius() + circle2.getRadius();
	}
	public class TextFieldHandler implements EventHandler<ActionEvent>{
		public void handle( ActionEvent e)
		{
			String str = tField.getText();
			String[] arr = str.split(" ");  /* takes the input and splits it into an array */
			
			double[] radius= new double[2];
			int[] cords= new int[4];
			/* turns strings into either ints or doubles */
			cords[0]=Integer.parseInt(arr[0]);
			cords[1]=Integer.parseInt(arr[1]);
			radius[0]=Double.parseDouble(arr[2]);
			cords[2]=Integer.parseInt(arr[3]);
			cords[3]=Integer.parseInt(arr[4]);
			radius[1]=Double.parseDouble(arr[5]);
			
			createCircle(radius,cords);
		}
	}
}
