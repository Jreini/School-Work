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
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

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
		output();
		Scene scene = new Scene(root,800,800);
		stage.setScene(scene);
        stage.show();
        stage.setTitle("Circle Intersects by Justin Reini");
	}
	Button button1,button2,button3;
	Pane front,spatialrelat,problem;
	public void output(){
		Front fr = new Front();
		SpatialRelations spatial = new SpatialRelations();
		Problem prob = new Problem();
		
		front = fr.showFront();
		spatialrelat = spatial.showCirc();
		problem = prob.showProb();
		
		Button button1 = new Button("Front page");
		Button button2 = new Button("Problem");
		Button button3 = new Button("Calculate");
		button2.relocate(100,0);
		button3.relocate(200,0);
		
		root.getChildren().addAll(button1,button2,button3);
		button1.setOnAction(ae-> {root.getChildren().clear();root.getChildren().addAll(button1,button2,button3,front);});
		button2.setOnAction(ae-> {root.getChildren().clear();root.getChildren().addAll(button1,button2,button3,problem);});
		button3.setOnAction(ae-> {root.getChildren().clear();root.getChildren().addAll(button1,button2,button3,spatialrelat);});
	}
}
