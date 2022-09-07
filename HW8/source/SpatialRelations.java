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
import javafx.scene.control.Button;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.TextAlignment;
import javafx.geometry.Point2D;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.control.Slider;

/**
 *@author Justin Reini
 */
public class SpatialRelations{
	Label label0,outputlabel;
	TextField tField;
	Circle circle1,circle2;
	Pane pane;
	Button switchbutton;
	Slider radslider;
	public Pane showCirc(){
		try
		{
			pane = new Pane();
			File file = new File("./data/infile.txt");
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
			
			switchbutton = new Button("circle1");
			
			radslider = new Slider();
			radslider.setShowTickLabels(true);
			radslider.setShowTickMarks(true);
			
			tField = new TextField(cords[0]+" "+cords[1]+" "+radius[0]+" "+cords[2]+" "+cords[3]+" "+radius[1]);
			tField.setPrefWidth(400);
			pane.relocate(0,50);
			tField.relocate(0,20);
			outputlabel.relocate(0,50);
			switchbutton.relocate(200,70);
			radslider.relocate(0,70);
			
			radslider.valueProperty().addListener(ov-> {
				if(switchbutton.getText()=="circle1")
					circle1.setRadius(radslider.getValue());
				if(switchbutton.getText()=="circle2")
					circle2.setRadius(radslider.getValue());
				checkstatus();
			});
			EventHandler<ActionEvent> event = new EventHandler<ActionEvent>()
			{
				public void handle(ActionEvent e)
				{
					pane.getChildren().removeAll(circle1,circle2);
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
					checkstatus();
				}
			};
			tField.setOnAction(event);
			
			/* mouse clicked handlers */
			pane.setOnMouseClicked(e->{
				double centx = e.getX();
				double centy = e.getY();
				if(switchbutton.getText()=="circle1")
				{
					circle1.setCenterX(centx);
					circle1.setCenterY(centy);
				}
				if(switchbutton.getText()=="circle2")
				{
					circle2.setCenterX(centx);
					circle2.setCenterY(centy);
				}
				checkstatus();
			});
			
			EventHandler<ActionEvent> buttonevent = new EventHandler<ActionEvent>()
			{
				public void handle(ActionEvent e)
				{
					if(switchbutton.getText()=="circle1")
						switchbutton.setText("circle2");
					else
						switchbutton.setText("circle1");
					checkstatus();
				}
			};
			switchbutton.setOnAction(buttonevent);
			pane.getChildren().addAll(label0,tField,outputlabel,switchbutton,radslider);
		}
		catch(Exception e)
		{
			System.out.println("error in reading");
			e.printStackTrace();
		}
		return pane;
	}
	public void createCircle(double[] radius, int[] cords)
	{
		circle1 = new Circle();
		circle2 = new Circle();
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
		pane.getChildren().addAll(circle1,circle2);
	}
	public void checkstatus()
	{
		double dist1 = Math.pow(circle2.getCenterX()-circle1.getCenterX(),2)+Math.pow(circle2.getCenterY()-circle1.getCenterY(),2);
		double dist2 = Math.sqrt(dist1);
		double radius1 = circle1.getRadius();
		double radius2 = circle2.getRadius();
		if(dist2>(radius1+radius2))
			outputlabel.setText("The two circles are disjoint");
		else if(dist2==(radius1+radius2))
			outputlabel.setText("The two circles are externally touching");
		else if(dist2==0 & radius1==radius2 )
			outputlabel.setText("The two circles are equal");
		else if((dist2<(radius1-radius2)) & (dist2!=(radius1+radius2)))
			outputlabel.setText("Circle 2 is inside Circle 1, not touching");
		else if((dist2<(radius2-radius1)) & (dist2!=(radius1+radius2)))
			outputlabel.setText("Circle 1 is inside Circle 2, not touching");
		else if(dist2<(radius1-radius2))
			outputlabel.setText("Circle 2 is inside Circle 1, touching");
		else if(dist2<(radius2-radius1))
			outputlabel.setText("Circle 1 is inside Circle 2, touching");
		else
			outputlabel.setText("The two circles have proper overlap");
	}
}
