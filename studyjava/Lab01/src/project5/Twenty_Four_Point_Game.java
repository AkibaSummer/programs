package project5;

import javafx.application.*;
import javafx.stage.*;
import javafx.scene.Scene;
import javafx.scene.layout.*;

class calc{
	public static double calcInfix(String text) {
		return 0;
	}
}

public class Twenty_Four_Point_Game extends Application {
	public void start(Stage primaryStage) {
		primaryStage.setHeight(400);
		primaryStage.setWidth(800);
		primaryStage.show();
		Pane root = new Pane();
		
		primaryStage.setScene(new Scene(root, primaryStage.getHeight(), primaryStage.getWidth()));
		primaryStage.show();
	}
	
	public static void main (String args[]) {
		launch(args);
		System.out.println("Finish!");
	}
	
}
