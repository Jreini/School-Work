/** Programmer: Justin Reini */
package code;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.Node;

/**
 *@author Justin Reini
 */

public class Front{
	Pane pane;
	Image image;
	ImageView imageView;
	Label name,header,desc;
	public Pane showFront(){
		pane = new Pane();
		image = new Image("file:images/justin.png", true);
		imageView = new ImageView(image);
		name= new Label("Name: Justin Reini");
		header = new Label("Demonstration of Circles overlapping for Java GUI: CS5405");
		desc = new Label("This is my original code, I wrote all the code myself");
		
		pane.relocate(0,50);
		imageView.setFitHeight(500);
		imageView.setFitWidth(500);
		header.relocate(0,600);
		imageView.relocate(10,50);
		name.relocate(0,620);
		desc.relocate(0,640);
		pane.getChildren().addAll(imageView,header,name,desc);
		return pane;
	}
}