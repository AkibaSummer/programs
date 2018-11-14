package project1;

import javafx.animation.*;
import javafx.application.*;
import javafx.stage.*;
import javafx.util.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.image.*;
import javafx.scene.layout.*;
import javafx.scene.shape.*;
import javafx.scene.text.*;

class Car{
	private int t=10;
	private ImageView image=new ImageView(new Image(getClass().getResource("car.png").toString()));
	private Label newLabel(String text,double x,double y) {
		Label temp=new Label(text);
		temp.relocate(x, y);
		temp.setFont(new Font("Arial",30));
		return temp;
	}
	private TextField newTextField(String text,double x,double y,Racing_car father) {
		TextField temp=new TextField("10");
		temp.relocate(x, y);
		temp.setFont(new Font("Arial",25));
		temp.setOnAction(e->{
			try{t=Integer.parseInt(temp.getText());father.textChanged();}
			catch(Exception E) {temp.setText(t+"");}});
		temp.setPrefSize(90, 50);
		return temp;
	}
	public Car(Pane root,int id,Racing_car father) {//1~n
		image.relocate(0, 60*id);
		image.setFitHeight(100);
		root.getChildren().addAll(image,new Line(0,id*60,Racing_car.CAR_NUM*200,id*60),
				newLabel("Car"+id+":",id*200-200,10),newTextField("10",id*200-100,5,father));
	}
	public KeyFrame start() {
		return new KeyFrame(Duration.millis(0), new KeyValue(image.xProperty(),0));
	}
	public KeyFrame end() {
		return new KeyFrame(Duration.millis(t*100), new KeyValue(image.xProperty(),Racing_car.CAR_NUM*200-100));
	}
}

public class Racing_car extends Application {
	public final static int CAR_NUM=6;
	private Timeline timeline=new Timeline();
	private Car car[]=new Car[CAR_NUM];
	public void start(Stage primaryStage) {
		primaryStage.setHeight(CAR_NUM*60+60);
		primaryStage.setWidth(CAR_NUM*200);
		primaryStage.show();
		Pane root = new Pane();

		for (int i=0;i<CAR_NUM;i++) 
			car[i]=new Car(root,i+1,this);

		textChanged();
		primaryStage.setScene(new Scene(root, primaryStage.getHeight(), primaryStage.getWidth()));
		primaryStage.show();
	}

	public static void main (String args[]) {
		launch(args);
		System.out.println("Finish!");
	}

	public void textChanged() {
		//timeline.setCycleCount(Timeline.INDEFINITE);
		timeline.getKeyFrames().clear();
		for (int i=0;i<CAR_NUM;i++) {
			timeline.getKeyFrames().addAll(car[i].start(),car[i].end());
		}
		timeline.stop();
		timeline.play();	
	}
}