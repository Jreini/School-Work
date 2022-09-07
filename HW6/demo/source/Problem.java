/** Programmer: Justin Reini */
package code;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.control.Button;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Label;
import javafx.scene.Node;

/**
 *@author Justin Reini
 */

public class Problem{
	Pane pane;
	Label probdesc,label2;
	public Pane showProb(){
		pane = new Pane();
		probdesc = new Label("Create a program that has two circles as input");
		label2 = new Label("Parameters are x, y, r for each circle");
		
		pane.relocate(0,50);
		probdesc.relocate(0,50);
		label2.relocate(0,70);
		
		pane.getChildren().addAll(probdesc,label2);
		return pane;
	}
}