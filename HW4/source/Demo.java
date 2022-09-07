/** Programmer: Justin Reini */
package code;
import javafx.scene.layout.*;//Pane, VBox
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.application.Application;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
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
		root = new VBox();
		createTextField();
		Scene scene = new Scene(root,400,400);
		stage.setScene(scene);
        stage.show();
        stage.setTitle("Area calculator by Justin Reini");
	}
	TextField tField0,tField1,tField2;
	public void createTextField(){
		tField0 = new TextField("Find the area of the quadrilateral, enter 8 values");
		tField1 = new TextField();
		tField2 = new TextField();
		tField1.setOnAction(new TextFieldHandler());
		root.getChildren().addAll(tField0,tField1,tField2);
	}
	public class TextFieldHandler implements EventHandler<ActionEvent>{
		public void handle( ActionEvent e)
		{
			String str = tField1.getText();
			String[] arr = str.split(" ");  /* takes the input and splits it into an array */
		
			int[] result= new int[8];
			for(int i=0;i<8;i++)
				result[i]=Integer.parseInt(arr[i]);
			/* turns string array into integer array */
		
			double product1 = (result[0]*result[3])+(result[2]*result[5])+(result[4]*result[7])+(result[6]*result[1]);
			double product2 = (result[1]*result[2])+(result[3]*result[4])+(result[5]*result[6])+(result[7]*result[0]);
			double area= (product1-product2) *0.5;  /* divides the quadrilateral into 2 large areas, then subtracts the extra and divides into half */
			double area2=Math.abs(area);
			tField2.setText(" Point 1: ("+result[0]+","+result[1]+")"+" "+" Point 2: ("+result[2]+","+result[3]+")"+" "+" Point 3: ("+result[4]+","+result[5]+")"+" "+
			" Point 4: ("+result[6]+","+result[7]+")"+" The area of the quadrilateral is " + area2);
		}
	}
}
